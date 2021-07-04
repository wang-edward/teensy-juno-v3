#include <Audio.h>

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//////////////////////////////////////////////////////////////////////
// Data types and lookup tables
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

#include "parameter_control.h"

//updateFilterMode(), updateFilter(), updateEnvelope(), updateEnvelopeMode(), updateFlanger(), resetAll()

#include "osc_control.h"


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

void testSetup() {
  Serial.println("testing");
  short delayBuffer[16*AUDIO_BLOCK_SAMPLES];
//  chorus1.begin(delayBuffer,16*AUDIO_BLOCK_SAMPLES,2);
  sawOn=false;
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
}
