#include <Audio.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//////////////////////////////////////////////////////////////////////
// Data types and lookup tables
//////////////////////////////////////////////////////////////////////
struct Oscillator {
  AudioSynthWaveformModulated*  squareLFO;
  AudioSynthWaveformModulated*  saw;
  AudioSynthWaveformModulated*  squarePWM;
  AudioSynthNoiseWhite          noise;
  
  AudioFilterStateVariable*     hpf;
  AudioFilterStateVariable*     lpf;
  AudioMixer4*                  oscMixer;
  AudioEffectEnvelope*          env;
  
  int8_t  note;
  uint8_t velocity;
};

// synth architecture in separate file
#include "SynthArch.h"

#define NVOICES 8
Oscillator oscs[NVOICES] = {
  { &squareLFO0, &saw0, &squarePWM0, &noise0, &hpf0, &lpf0, &env0, -1, 0},
  { &squareLFO1, &saw1, &squarePWM1, &noise1, &hpf1, &lpf1, &env1, -1, 0},
  { &squareLFO2, &saw2, &squarePWM2, &noise2, &hpf2, &lpf2, &env2, -1, 0},
  { &squareLFO3, &saw3, &squarePWM3, &noise3, &hpf3, &lpf3, &env3, -1, 0},
  { &squareLFO4, &saw4, &squarePWM4, &noise4, &hpf4, &lpf4, &env4, -1, 0},
  { &squareLFO5, &saw5, &squarePWM5, &noise5, &hpf5, &lpf5, &env5, -1, 0},
  { &squareLFO6, &saw6, &squarePWM6, &noise6, &hpf6, &lpf6, &env6, -1, 0},
  { &squareLFO7, &saw7, &squarePWM7, &noise7, &hpf7, &lpf7, &env7, -1, 0},
};

//////////////////////////////////////////////////////////////////////
// Global variables
//////////////////////////////////////////////////////////////////////
float   masterVolume   = 0.3;
//uint8_t currentProgram = WAVEFORM_SAWTOOTH;

bool  polyOn;
bool  omniOn;
bool  velocityOn;

//bool squarePWM or LFO idk

bool squareOn = true; //default to true
bool sawOn = true;
bool noiseOn = false; //start with false

bool  sustainPressed;
float channelVolume;
float panorama;
float pulseWidth; // 0.05-0.95
float pitchBend;  // -1/+1 oct
float pitchScale;
int   octCorr;

// filter
FilterMode_t filterMode;
float filtFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float filtReso; // 0.9-5.0
float filtAtt;  // 0-1

// envelope
bool  envOn;
float envDelay;   // 0-200
float envAttack;  // 0-200
float envHold;    // 0-200
float envDecay;   // 0-200
float envSustain; // 0-1
float envRelease; // 0-200

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

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//////////////////////////////////////////////////////////////////////
// Oscillator control functions
//////////////////////////////////////////////////////////////////////
inline float noteToFreq(float note) {
  // Sets all notes as an offset of A4 (#69)
  if (portamentoOn) note = portamentoPos;
  return SYNTH_TUNING*pow(2,(note - 69)/12.+pitchBend/pitchScale+octCorr);
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
    if (squareOn) osc.squareLFO->amplitude(v*channelVolume*GAIN_OSC);
    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    if (noiseOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    
    osc.velocity = velocity;
    osc.note = note;
  } else if (velocity > osc.velocity) {
    osc.wf->amplitude(v*channelVolume*GAIN_OSC);
    osc.velocity = velocity;
  }
}

inline void oscOff(Oscillator& osc) {
  if (envOn) osc.env->noteOff();
  else       osc.wf->amplitude(0);
  notesDel(notesOn,osc.note);
  osc.note = -1;
  osc.velocity = 0;
}

inline void allOff() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    oscOff(*o);
    o->wf->amplitude(0);
    o->env->noteOff();
  } while(++o < end);
  notesReset(notesOn);
}
