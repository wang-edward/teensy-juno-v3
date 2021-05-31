#include <Audio.h>

// set SYNTH_DEBUG to enable debug logging (0=off,1=most,2=all messages)
#define SYNTH_DEBUG 2

// define MIDI channel
#define SYNTH_MIDICHANNEL 1

// inital poly mode (POLY, MONO or PORTAMENTO)
#define SYNTH_INITIALMODE POLY

// define tuning of A4 in Hz
#define SYNTH_TUNING 440

// gain at oscillator/filter input stage (1:1)
// keep low so filter does not saturate with resonance
#define GAIN_OSC 0.5

// gain in final mixer stage for polyphonic mode (4:1)
// (0.25 is the safe value but larger sounds better :) )
#define GAIN_POLY 0.25

// gain in final mixer stage for monophonic modes
//#define GAIN_MONO 1.
#define GAIN_MONO 0.25

// define delay lines for modulation effects
#define DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
short delaylineL[DELAY_LENGTH];
short delaylineR[DELAY_LENGTH];

// audio memory
#define AMEMORY 50

// switch between USB and UART MIDI
#if defined USB_MIDI || defined USB_MIDI_SERIAL
#define SYNTH_USBMIDI
#endif

#define SYNTH_COM Serial

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//////////////////////////////////////////////////////////////////////
// Data types and lookup tables
//////////////////////////////////////////////////////////////////////
struct Oscillator {
  AudioSynthWaveformModulated*  pulseLFO;
  AudioSynthWaveformModulated*  saw;
  AudioSynthWaveformModulated*  pulsePWM;
  AudioSynthNoiseWhite*          noise;

  AudioMixer4*                  oscMixer;
  
  AudioFilterStateVariable*     hpf;
  AudioFilterStateVariable*     lpf;

  AudioEffectEnvelope*          env;
  
  int8_t  note;
  uint8_t velocity;
};

// synth architecture in separate file
#include "TestSynthArch.h"

#define NVOICES 8
Oscillator oscs[NVOICES] = {
  { &pulseLFO0, &saw0, &pulsePWM0, &noise0, &oscMixer0, &hpf0, &lpf0, &env0, -1, 0},
  { &pulseLFO1, &saw1, &pulsePWM1, &noise1, &oscMixer1, &hpf1, &lpf1, &env1, -1, 0},
  { &pulseLFO2, &saw2, &pulsePWM2, &noise2, &oscMixer2, &hpf2, &lpf2, &env2, -1, 0},
  { &pulseLFO3, &saw3, &pulsePWM3, &noise3, &oscMixer3, &hpf3, &lpf3, &env3, -1, 0},
  { &pulseLFO4, &saw4, &pulsePWM4, &noise4, &oscMixer4, &hpf4, &lpf4, &env4, -1, 0},
  { &pulseLFO5, &saw5, &pulsePWM5, &noise5, &oscMixer5, &hpf5, &lpf5, &env5, -1, 0},
  { &pulseLFO6, &saw6, &pulsePWM6, &noise6, &oscMixer6, &hpf6, &lpf6, &env6, -1, 0},
  { &pulseLFO7, &saw7, &pulsePWM7, &noise7, &oscMixer7, &hpf7, &lpf7, &env7, -1, 0},
};

//////////////////////////////////////////////////////////////////////
// Global variables
//////////////////////////////////////////////////////////////////////
float   masterVolume   = 0.6;
//uint8_t currentProgram = WAVEFORM_SAWTOOTH;

bool  polyOn = true;
bool  omniOn;
bool  velocityOn = true;

//bool squarePWM or LFO idk

bool squareOn = true; //default to true
bool sawOn = true;
bool noiseOn = false; //start with false

bool  sustainPressed;
float channelVolume = 1.0;
//float panorama;
float pulseWidth; // 0.05-0.95
float pitchBend;  // -1/+1 oct
float pitchScale;
int   octCorr;

// filter
//FilterMode_t filterMode;
float lpfFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float lpfReso; // 0.9-5.0
//float lpfAtt;  // 0-1

float hpfFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float hpfReso; // 0.9-5.0
//float hpfAtt;  // 0-1

// envelope
bool  envOn = true;
float envDelay;   // 0-200
float envAttack;  // 0-200
float envHold;    // 0-200
float envDecay;   // 0-200
float envSustain; // 0-1
float envRelease; // 0-200

// FX
bool  flangerOn;
int   flangerOffset;
int   flangerDepth;
float flangerFreqCoarse;
float flangerFreqFine;

// portamento
bool     portamentoOn = false;
uint16_t portamentoTime;
int8_t   portamentoDir;
float    portamentoStep;
float    portamentoPos;

//////////////////////////////////////////////////////////////////////
// Handling of sounding and pressed notes
//////////////////////////////////////////////////////////////////////
int8_t notesOn[NVOICES]      = { -1, -1, -1, -1, -1, -1, -1, -1, };
int8_t notesPressed[NVOICES] = { -1, -1, -1, -1, -1, -1, -1, -1, };

inline void notesReset(int8_t* notes) {
  memset(notes,-1,NVOICES*sizeof(int8_t));
}

inline void notesAdd(int8_t* notes, uint8_t note) {
  int8_t *end=notes+NVOICES;
  do {
    if(*notes == -1) {
      *notes = note;
      break;
    }
  } while (++notes < end);
}

inline int8_t notesDel(int8_t* notes, uint8_t note) {
  int8_t lastNote = -1;
  int8_t *pos=notes, *end=notes+NVOICES;
  while (++pos < end && *(pos-1) != note);
  if (pos-1 != notes) lastNote = *(pos-2);
  while (pos < end) {
    *(pos-1) = *pos;
    if (*pos++ == -1) break;
  }
  if (*(end-1)==note || pos == end)
      *(end-1) = -1;
  return lastNote;
}

inline bool notesFind(int8_t* notes, uint8_t note) {
  int8_t *end=notes+NVOICES;
  do {
    if (*notes == note) return true;
  } while (++notes < end);
  return false;
}

//////////////////////////////////////////////////////////////////////
// Parameter control functions
//////////////////////////////////////////////////////////////////////

//updateFilterMode(), updateFilter(), updateEnvelope(), updateEnvelopeMode(), updateFlanger(), resetAll()

//inline void updateFilterMode() {
//  Serial.print("FILTER MODE");
//  Oscillator *o=oscs,*end=oscs+NVOICES;
//  do {
//    for (uint8_t fm=0; fm<FILTERMODE_N; ++fm) {
//      if (fm == filterMode) o->mix->gain(fm,filtAtt);
//      else                  o->mix->gain(fm,0);
//    }
//  } while (++o < end);
//}

//inline void updatePan() {
//  float norm  = (polyOn && !portamentoOn) ? GAIN_POLY : GAIN_MONO;
//  float left=norm, right=norm;
//  if (panorama < 0.5) right *= 2*panorama;
//  else left *= 2*(1-panorama);
//
//  for (uint8_t i=0; i<4; ++i) {
//    mixerL.gain(i,left);
//    mixerR.gain(i,right);
//  }
//}

//inline void updateFilter() {
//  Oscillator *o=oscs,*end=oscs+NVOICES;
//  do {
//    o->filt->frequency(filtFreq);
//    o->filt->resonance(filtReso);
//  } while (++o < end);
//}

inline void updateHPF() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->hpf->frequency(hpfFreq);
    o->hpf->resonance(hpfReso);
  } while (++o < end);
}

inline void updateLPF() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpf->frequency(lpfFreq);
    o->lpf->resonance(lpfReso);
  } while (++o < end);
}

inline void updateEnvelope() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->env->delay(envDelay);
    o->env->attack(envAttack);
    o->env->hold(envHold);
    o->env->decay(envDecay);
    o->env->sustain(envSustain);
    o->env->release(envRelease);
  } while (++o < end);
}

inline void updateEnvelopeMode() {
  float env    = envOn ? 1 : 0;
  float noenv  = envOn ? 0 : 1;
  for (uint8_t i=0; i<2; ++i) {
    // env
    envmixer1.gain(i,env);
    envmixer2.gain(i,env);
    envmixer3.gain(i,env);
    envmixer4.gain(i,env);
    // no env
    envmixer1.gain(i+2,noenv);
    envmixer2.gain(i+2,noenv);
    envmixer3.gain(i+2,noenv);
    envmixer4.gain(i+2,noenv);
  }
}

void updateFlanger() {
  if (flangerOn) {
    AudioNoInterrupts();
    flangerL.voices(flangerOffset,flangerDepth,flangerFreqCoarse+flangerFreqFine);
    flangerR.voices(flangerOffset,flangerDepth,flangerFreqCoarse+flangerFreqFine);
    AudioInterrupts();
#if SYNTH_DEBUG > 0
    SYNTH_COM.print("Flanger: offset=");
    SYNTH_COM.print(flangerOffset);
    SYNTH_COM.print(", depth=");
    SYNTH_COM.print(flangerDepth);
    SYNTH_COM.print(", freq=");
    SYNTH_COM.println(flangerFreqCoarse+flangerFreqFine);
#endif
  } else {
    flangerL.voices(FLANGE_DELAY_PASSTHRU,0,0);
    flangerR.voices(FLANGE_DELAY_PASSTHRU,0,0);
  }
}

void resetAll() {
  polyOn     = true;
  omniOn     = false;
  velocityOn = true;

//  filterMode     = FILTEROFF;
  sustainPressed = false;
  channelVolume  = 1.0;
//  panorama       = 0.5;
  pulseWidth     = 0.5;
  pitchBend      = 0;
  pitchScale     = 1;
  octCorr        = currentProgram == WAVEFORM_PULSE ? 1 : 0;

  // filter
  lpfFreq = 15000.;
  lpfReso = 0.9;
//  lpfAtt  = 1.;
  lpfFreq = 50.;
  lpfReso = 0.9;

  // envelope
  envOn      = true;
  envDelay   = 0;
  envAttack  = 20;
  envHold    = 0;
  envDecay   = 0;
  envSustain = 1;
  envRelease = 20;

  // FX
  flangerOn         = false;
  flangerOffset     = DELAY_LENGTH/4;
  flangerDepth      = DELAY_LENGTH/16;
  flangerFreqCoarse = 0;
  flangerFreqFine   = .5;

  // portamento
  portamentoOn   = false;
  portamentoTime = 1000;
  portamentoDir  = 0;
  portamentoStep = 0;
  portamentoPos  = -1;

  updatePolyMode();
//  updateFilterMode();
  updateEnvelope();
//  updatePan();
}

inline void updateProgram() {
//  if (currentProgram==WAVEFORM_PULSE) octCorr = 1;
//  else                   octCorr = 0;

  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->->pulseWidth(pulseWidth);
    o->wf->begin(progs[currentProgram]);
  } while(++o < end);
}

inline void updatePulseWidth() {
  if (currentProgram!=WAVEFORM_PULSE) return;
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    if (o->note < 0) continue;
    o->wf->pulseWidth(pulseWidth);
  } while(++o < end);
}

inline void updatePitch() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    if (o->note < 0) continue;
    o->wf->frequency(noteToFreq(o->note));
  } while(++o < end);
}

inline void updateVolume() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  float velocity;
  do {
    if (o->note < 0) continue;
    velocity = velocityOn ? o->velocity/127. : 1;
    o->wf->amplitude(velocity*channelVolume*GAIN_OSC);
  } while(++o < end);
}

inline void updateMasterVolume() {
  // read the volume knob
  float vol = (float) analogRead(A1) / 1280.0;
  if( fabs(vol-masterVolume) > 0.01) {
    masterVolume = vol;
    sgtl5000_1.volume(masterVolume);
#if SYNTH_DEBUG > 0
    SYNTH_COM.print("Volume: ");
    SYNTH_COM.println(vol);
#endif
  }
}

inline void updatePolyMode() {
  allOff();
  updateEnvelopeMode();
//  updatePan();
}

inline void updatePortamento()
{
  if (portamentoDir == 0) return;
  if (oscs->note < 0) {
    portamentoDir = 0;
    return;
  }
  if (portamentoDir < 0) {
    portamentoPos -= portamentoStep;
    if (portamentoPos < oscs->note) {
      portamentoPos = oscs->note;
      portamentoDir = 0;
    }
  }
  else {
    portamentoPos += portamentoStep;
    if (portamentoPos > oscs->note) {
      portamentoPos = oscs->note;
      portamentoDir = 0;
    }
  }
  oscs->wf->frequency(noteToFreq(portamentoPos));
}

//////////////////////////////////////////////////////////////////////
// Oscillator control functions
//////////////////////////////////////////////////////////////////////
inline float noteToFreq(float note) {
  // Sets all notes as an offset of A4 (#69)
//  if (portamentoOn) note = portamentoPos;     no portamento for now
//  return SYNTH_TUNING*pow(2,(note - 69)/12.+pitchBend/pitchScale+octCorr);
  return SYNTH_TUNING*pow(2,(note - 69)/12.); //no pitch bend for now
}

inline void oscOn(Oscillator& osc, int8_t note, uint8_t velocity) {
  float v = velocityOn ? velocity/127. : 1;
  if (osc.note!=note) {
    //set osc frequencies
    if (squareOn) osc.squareLFO->frequency(noteToFreq(note));
    if (sawOn) osc.saw->frequency(noteToFreq(note));
    
    notesAdd(notesOn,note);
    if (envOn && !osc.velocity) osc.env->noteOn();
    
    //turn oscillators on
    if (pulseOn) osc.pulseLFO->amplitude(v*channelVolume*GAIN_OSC);
    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    if (noiseOn) osc.noise->amplitude(v*channelVolume*GAIN_OSC);
    Serial.println(v*channelVolume*GAIN_OSC);
    osc.velocity = velocity;
    osc.note = note;
  } else if (velocity > osc.velocity) {
    //turn oscillators on
    if (pulseOn) osc.pulseLFO->amplitude(v*channelVolume*GAIN_OSC);
    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    if (noiseOn) osc.noise->amplitude(v*channelVolume*GAIN_OSC);
    osc.velocity = velocity;
  }
}

inline void oscOff(Oscillator& osc) {
  if (envOn) osc.env->noteOff();
  else {
    //turn oscillators off
    if (pulseOn) osc.pulseLFO->amplitude(0);
    if (sawOn) osc.saw->amplitude(0);
    if (noiseOn) osc.noise->amplitude(0);
  }
  notesDel(notesOn,osc.note);
  osc.note = -1;
  osc.velocity = 0;
}

inline void allOff() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    oscOff(*o);
    o->pulseLFO->amplitude(0);
    o->saw->amplitude(0);
    o->noise->amplitude(0);
    o->env->noteOff();
  } while(++o < end);
  notesReset(notesOn);
}

//////////////////////////////////////////////////////////////////////
// MIDI handlers
//////////////////////////////////////////////////////////////////////
void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.println(note);
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 1
  SYNTH_COM.println("NoteOn");
#endif

  notesAdd(notesPressed,note);

  Oscillator *o=oscs;
  if (portamentoOn) {
    if (portamentoTime == 0 || portamentoPos < 0) {
      portamentoPos = note;
      portamentoDir = 0;
    } else if (portamentoPos > -1) {
      portamentoDir  = note > portamentoPos ? 1 : -1;
      portamentoStep = fabs(note-portamentoPos)/(portamentoTime);
    }
    *notesOn = -1;
    oscOn(*o, note, velocity);
  }
  else if (polyOn) {
    Oscillator *curOsc=0, *end=oscs+NVOICES;
    if (sustainPressed && notesFind(notesOn,note)) {
      do {
        if (o->note == note) {
          curOsc = o;
          break;
        }
      } while (++o < end);
    }
    for (o=oscs; o < end && !curOsc; ++o) {
      if (o->note < 0) {
        curOsc = o;
        break;
      }
    }
    if (!curOsc && *notesOn != -1) {
#if SYNTH_DEBUG > 0
      SYNTH_COM.println("Stealing voice");
#endif
      curOsc = OnNoteOffReal(channel,*notesOn,velocity,true);
    }
    if (!curOsc) return;
    Serial.println("done!");
    oscOn(*curOsc, note, velocity);
  }
  else
  {
    *notesOn = -1;
    oscOn(*o, note, velocity);
  }

  return;
}

Oscillator* OnNoteOffReal(uint8_t channel, uint8_t note, uint8_t velocity, bool ignoreSustain) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return 0;

#if SYNTH_DEBUG > 1
  SYNTH_COM.println("NoteOff");
#endif
  int8_t lastNote = notesDel(notesPressed,note);

  if (sustainPressed && !ignoreSustain) return 0;

  Oscillator *o=oscs;
  if (portamentoOn) {
    if (o->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,note);
        if (portamentoTime == 0) {
          portamentoPos = lastNote;
          portamentoDir = 0;
        } else {
          portamentoDir = lastNote > portamentoPos? 1 : -1;
          portamentoStep = fabs(lastNote-portamentoPos)/(portamentoTime);
        }
        oscOn(*o, lastNote, velocity);
      }
      else
      {
        oscOff(*o);
        portamentoPos = -1;
        portamentoDir = 0;
      }
    }
    if (oscs->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,o->note);
        oscOn(*o, lastNote, velocity);
      } else {
        oscOff(*o);
      }
    }
  }
  else if (polyOn) {
    Oscillator *end=oscs+NVOICES;
    do {
      if (o->note == note) break;
    } while (++o < end);
    if (o == end) return 0;
    oscOff(*o);
  } else {
    if (oscs->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,o->note);
        oscOn(*o, lastNote, velocity);
      } else {
        oscOff(*o);
      }
    }
  }

  return o;
}

inline void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  OnNoteOffReal(channel,note,velocity,false);
}

void OnAfterTouchPoly(uint8_t channel, uint8_t note, uint8_t value) {
#if SYNTH_DEBUG > 0
  SYNTH_COM.print("AfterTouchPoly: channel ");
  SYNTH_COM.print(channel);
  SYNTH_COM.print(", note ");
  SYNTH_COM.print(note);
  SYNTH_COM.print(", value ");
  SYNTH_COM.println(value);
#endif
}

#include "control-change.h"

inline void printResources( float cpu, uint8_t mem) {
  SYNTH_COM.print( "CPU Usage: ");
  SYNTH_COM.print(cpu);
  SYNTH_COM.print( "%, Memory: ");
  SYNTH_COM.println(mem);
}

//void performanceCheck() {
//  static unsigned long last = 0;
//  unsigned long now = millis();
//  if ((now-last)>1000) {
//    last = now;
//    float cpu = AudioProcessorUsageMax();
//    uint8_t mem = AudioMemoryUsageMax();
//    if( (statsMem!=mem) || fabs(statsCpu-cpu)>1) {
//      printResources( cpu, mem);
//    }
//    AudioProcessorUsageMaxReset();
//    AudioMemoryUsageMaxReset();
//    last = now;
//    statsCpu = cpu;
//    statsMem = mem;
//  }
//}

//////////////////////////////////////////////////////////////////////
// test setup
//////////////////////////////////////////////////////////////////////

void testSetup() {
  Serial.println("testing");
  for (int i=0;i<4;i++) {
    EnvMixer0.gain(i,1.0);
    EnvMixer1.gain(i,1.0);
  }
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->oscMixer->gain(1,1.0);
    o->hpf->frequency(400);
    o->lpf->frequency(10000);
    o->saw->begin(WAVEFORM_SAWTOOTH);
    o->pulseLFO->begin(WAVEFORM_PULSE);
  } while (++o < end);
}

//////////////////////////////////////////////////////////////////////
// setup() and loop()
//////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  AudioMemory(AMEMORY);

  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);

  sgtl5000_1.enable();
  sgtl5000_1.volume(masterVolume);

  testSetup();
  
//  usbMIDI.setHandleVelocityChange(OnAfterTouchPoly);
//  usbMIDI.setHandleControlChange(OnControlChange);
//  usbMIDI.setHandlePitchChange(OnPitchChange);
//  usbMIDI.setHandleProgramChange(OnProgramChange);
//  usbMIDI.setHandleAfterTouch(OnAfterTouch);
//  usbMIDI.setHandleSysEx(OnSysEx);
  //usbMIDI.setHandleRealTimeSystem(OnRealTimeSystem);
//  usbMIDI.setHandleTimeCodeQuarterFrame(OnTimeCodeQFrame);
}

void loop() {
  // put your main code here, to run repeatedly:
  usbMIDI.read();
}
