#include <Audio.h>
#include <MIDI.h>
// synth architecture in separate file
#include "synth_arch.h"

#include "global_variables.h"
#include "notes_handling.h"

#include "osc_control.h"

#include "parameter_control.h"

#include "midi_handle.h"

#include "control_change.h"

void OnPitchChange(uint8_t channel, int pitch) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 1
  SYNTH_COM.print("PitchChange: channel ");
  SYNTH_COM.print(channel);
  SYNTH_COM.print(", pitch ");
  SYNTH_COM.println(pitch);
#endif

#ifdef SYNTH_USBMIDI
  if (pitch == 8192)
    pitchBend = 0;
  else
    pitchBend = (pitch-8192)/8192.;
#else
  pitchBend = pitch/8192.;
#endif

  updatePitch();
}

//void OnProgramChange(uint8_t channel, uint8_t program) {
//  if (!omniOn && channel!=SYNTH_MIDICHANNEL) return;
//
//#if SYNTH_DEBUG > 1
//  SYNTH_COM.print("ProgramChange: channel ");
//  SYNTH_COM.print(channel);
//  SYNTH_COM.print(", program ");
//  SYNTH_COM.println(program);
//#endif
//
//  if (program <NPROGS) {
//    if( program!=currentProgram) {
//      currentProgram = program;
//      updateProgram();
//    }
//  }
//}

void OnAfterTouch(uint8_t channel, uint8_t pressure) {
  if (!omniOn && channel!=SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 0
  SYNTH_COM.print("AfterTouch: channel ");
  SYNTH_COM.print(channel);
  SYNTH_COM.print(", pressure ");
  SYNTH_COM.println(pressure);
#endif
}

//#include "debug.h"

void testSetup() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  envOn = true;
  updateEnvelopeMode();
  do {
    o->oscMixer->gain(1,1.0);
    o->hpf->frequency(400);
    o->lpf->frequency(10000);
    o->saw->begin(WAVEFORM_SAWTOOTH);
    o->pulseLFO->begin(WAVEFORM_PULSE);
  } while (++o < end);
}

void setup() {
  SYNTH_COM.begin(115200);

  AudioMemory(AMEMORY);
  sgtl5000_1.enable();
  sgtl5000_1.volume(masterVolume);

  testSetup();
  
  resetAll();
//  updateProgram();

  flangerL.begin(delaylineL,DELAY_LENGTH,FLANGE_DELAY_PASSTHRU,0,0);
  flangerR.begin(delaylineR,DELAY_LENGTH,FLANGE_DELAY_PASSTHRU,0,0);
  updateFlanger();

#ifdef SYNTH_USBMIDI
  // see arduino/hardware/teensy/avr/libraries/USBHost_t36/USBHost_t36.h
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleVelocityChange(OnAfterTouchPoly);
  usbMIDI.setHandleControlChange(OnControlChange);
  usbMIDI.setHandlePitchChange(OnPitchChange);
//  usbMIDI.setHandleProgramChange(OnProgramChange);
  usbMIDI.setHandleAfterTouch(OnAfterTouch);
//  usbMIDI.setHandleSysEx(OnSysEx);
  //usbMIDI.setHandleRealTimeSystem(OnRealTimeSystem);
//  usbMIDI.setHandleTimeCodeQuarterFrame(OnTimeCodeQFrame);
#endif
  // see arduino/hardware/teensy/avr/libraries/MIDI/src/MIDI.h
  MIDI.begin();
  MIDI.setHandleNoteOff(OnNoteOff);
  MIDI.setHandleNoteOn(OnNoteOn);
  MIDI.setHandleAfterTouchPoly(OnAfterTouchPoly);
  MIDI.setHandleControlChange(OnControlChange);
  MIDI.setHandlePitchBend(OnPitchChange);
//  MIDI.setHandleProgramChange(OnProgramChange);
  MIDI.setHandleAfterTouchChannel(OnAfterTouch);
  // the following functions need a different callback signature but they are
  // not used anyways, so...
  //MIDI.setHandleSystemExclusive(OnSysEx);
  //MIDI.setHandleTimeCodeQuarterFrame(OnTimeCodeQFrame);

  delay(1000);
}

void loop() {
//#ifdef SYNTH_USBMIDI
  usbMIDI.read();
//#endif
  MIDI.read();

  updateMasterVolume();
  updatePortamento();

//#if SYNTH_DEBUG > 0
//  performanceCheck();
//  while (SYNTH_COM.available())
//    selectCommand(SYNTH_COM.read());
//#endif
}
