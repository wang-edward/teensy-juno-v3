#include <Audio.h>

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//////////////////////////////////////////////////////////////////////
// Data types and lookup tables`
//////////////////////////////////////////////////////////////////////


// synth architecture in separate file
#include "synth_arch.h"


#include "global_variables.h"

//////////////////////////////////////////////////////////////////////
// Handling of sounding and pressed notes
//////////////////////////////////////////////////////////////////////

#include "note_handle.h"

//////////////////////////////////////////////////////////////////////
// Parameter control functions
//////////////////////////////////////////////////////////////////////
#include "osc_control.h"//111
#include "parameter_control.h"

//updateFilterMode(), updateFilter(), updateEnvelope(), updateEnvelopeMode(), updateFlanger(), resetAll()

//#include "osc_control.h"


//////////////////////////////////////////////////////////////////////
// MIDI handlers
//////////////////////////////////////////////////////////////////////
#include "midi_handle.h"

#include "control_change.h"

//DEBUG!!

#include "debug.h"

//////////////////////////////////////////////////////////////////////
// test setup
//////////////////////////////////////////////////////////////////////

#define FLANGE_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
  short l_delayline[FLANGE_DELAY_LENGTH];
  short r_delayline[FLANGE_DELAY_LENGTH];

  int s_idx = 3*FLANGE_DELAY_LENGTH/4;
  int s_depth = FLANGE_DELAY_LENGTH/8;
  double s_freq = 0.0625;

void testSetup() {
  Serial.println("testing");
//  short delayBuffer[16*AUDIO_BLOCK_SAMPLES];
//  chorus1.begin(delayBuffer,16*AUDIO_BLOCK_SAMPLES,2);

  flangerL.begin(l_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);
  flangerR.begin(r_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);
  
  sawOn=true;
  pulseOn=true;
  flangerOn = true;
  envOn = true;
  
  for (int i=0;i<4;i++) {
    EnvMixer0.gain(i,1.0);
    EnvMixer1.gain(i,1.0);
//    EnvMixer2.gain(i,1.0);
//    EnvMixer3.gain(i,1.0);
    mixerL.gain(i,1.0);
    mixerR.gain(i,1.0);
  }
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->hpf->frequency(100);
    o->lpf->frequency(8000);
    o->saw->begin(WAVEFORM_SAWTOOTH);
    o->pulseLFO->begin(WAVEFORM_PULSE);
    o->sub->begin(WAVEFORM_PULSE); // sub!
    o->oscMixer->gain(1,1.0);
    o->oscMixer->gain(2,1.0);
  } while (++o < end);
  updateEnvelopeMode();
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
  resetAll();

//  dc0.amplitude(1);
//  lpfEnv.attack(100);

  lfo.begin(WAVEFORM_TRIANGLE);
  lfo.amplitude(10);
  lfo.offset(0);
  lfo.frequency(1);
  dcoPitchAmp.gain(100);
//  pwmDc.amplitude(0);
  //  pwmMixer.gain(0,10);
  //  pwmMixer.gain(1,0);
//  dcoPitchAmp.gain(0);
  
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->pulseLFO->frequencyModulation(12);
    o->sub->frequencyModulation(12);
    o->lpf->octaveControl(3);
  } while (++o < end);
  
//  usbMIDI.setHandleVelocityChange(OnAfterTouchPoly);
  usbMIDI.setHandleControlChange(OnControlChange);
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
//  updateMasterVolume();
//  updatePortamento();
  
//#if SYNTH_DEBUG > 0
//  performanceCheck();
//  while (Serial.available())
//    selectCommand(Serial.read());
//#endif
}
