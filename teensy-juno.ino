#include <Audio.h>
#include <MIDI.h>
#include "Mux.h"
using namespace admux;

#include "synth_arch.h"
#include "global_variables.h"
#include "presets.h"
#include "note_handle.h"
#include "osc_control.h"//111
#include "parameter_control.h"
#include "midi_handle.h"

#include "pins.h"
#include "button.h"
#include "analog_control.h"

#include "control_change.h"

//DEBUG!!

//#include "debug.h"

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

  //reduce clipping
  for (int i=0;i<4;i++) {
    EnvMixer0.gain(i,0.25);
    EnvMixer1.gain(i,0.25);
    mixerL.gain(i,0.5);
    mixerR.gain(i,0.5);
  }
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->hpf->frequency(100);
    o->lpf->frequency(8000);
    o->saw->begin(WAVEFORM_SAWTOOTH);
    o->pulseLFO->begin(WAVEFORM_PULSE);
    o->sub->begin(WAVEFORM_PULSE); // sub!

    //reduce clipping
    o->oscMixer->gain(0,0.25);
    o->oscMixer->gain(1,0.25);
    o->oscMixer->gain(2,0.25);
    o->oscMixer->gain(3,0.25);
  } while (++o < end);
  updateEnvelopeMode();
}

#include "debug.h"


//////////////////////////////////////////////////////////////////////
// setup() and loop()
//////////////////////////////////////////////////////////////////////

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  AudioMemory(AMEMORY);

  
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(OnNoteOn);
  MIDI.setHandleNoteOff(OnNoteOff);
  
  MIDI.setHandleControlChange(OnControlChange);

//  usbMIDI.setHandleNoteOff(OnNoteOff);
//  usbMIDI.setHandleNoteOn(OnNoteOn);
//usbMIDI.setHandleControlChange(OnControlChange);
  sgtl5000_1.enable(); 
  sgtl5000_1.volume(masterVolume);
  sgtl5000_1.volume(0.9);
  testSetup();
  resetAll();

  lpfEnvDc.amplitude(5);
//  lpfEnv.attack(100);

  lfo.begin(1, 1, WAVEFORM_SINE);
  oscLfoAmp.gain(0.5);
  pwmDc.amplitude(1);
  lpfEnvDc.amplitude(1);
  //turn off lfo mod to start off
  lpfLfoLevel = 0;
  updateLpfLfoLevel();
  oscLfoLevel = 0;
  updateOscLfo();

  //filter envelope test
  pulseOn = false;
  envAttack = 100;
  envDecay = 500;
  envSustain = 0;
  envRelease = 150;
  updateEnvelope();
  lpfFreq = 300;
  lpfReso = 3.49;
  lpfEnvLevel = 0.98;
  updateLPF();
  updateLpfEnvLevel();

  lpfModWheelLevel = 0;
  lpfLfoLevel = 0;
  lpfKbdLevel = 0;

  lpfOctaveControl = 7;
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpf->octaveControl(lpfOctaveControl);
    o->lfoEnv->delay(500);
  } while (++o < end);

    oscLfoLevel = 10;
    updateOscLfo();
    lfoRate = 50;
    updateLfo();
    velocityOn = false;
    envSustain = 1;
    updateEnvelope();
    t_init();

  Button MBU1(M1, 0, 0, 70, 1, 5);
}

void t_init() {
  for(int i=29;i<33;i++) {
    pinMode(i, OUTPUT);
  }
}

float t_read(int k) {
    char buff[65];
    String s = itoa(k, buff, 2);
    for (int i=((int)(s.length()));i<=4;i++) {
      s = "0" + s;
    }
    for(int i=3;i>0;i--) {
//      Serial.print(s); Serial.print(" ");
//      Serial.println(s[i]);
      if(s[i]=='1') {
        digitalWrite(i+29,HIGH);
      } else {
        digitalWrite(i+29,LOW);
      }
    }
    Serial.println(s);
    return analogRead(25);
}

void all_read() {
  for(int i=0;i<16;i++) {
    Serial.print(i);Serial.print(": ");
      Serial.println(t_read(i));
    delay(100);
  }
  Serial.println("\n\n\n");
}

void loop() {
  // put your main code here, to run repeatedly:
//  usbMIDI.read();
  if(MIDI.read()) {
    Serial.println("AAA");
    
  }
  MIDI.read();
//  Serial.println(t_read(0));
  int j = 11;
//  Serial.println(muxArray[1].Mux::read(j));
//  delay(50);
  analogControl();
//  checkSliders();
  updateButtons();
//    delay(10);
//    float a = muxArray[1].Mux::read(0)/1023.;
//    delay(10);
//    float b = muxArray[1].Mux::read(1)/1023.;
//    delay(10);
//    float c = muxArray[1].Mux::read(2)/1023.;
//    delay(10);
//    float d = muxArray[1].Mux::read(3)/1023.;
//    delay(10);
//    float e = muxArray[1].Mux::read(4)/1023.;
//    delay(10);
//    Serial.print("0: ");    Serial.println(a);
//    Serial.print("1: ");    Serial.println(b);
//    Serial.print("2: ");    Serial.println(c);
//    Serial.print("3: ");    Serial.println(d);
//    Serial.print("4: ");    Serial.println(e);
//    
//    Serial.println();
//  delay(5);
//  updateMasterVolume();
//  updatePortamento();
//#if SYNTH_DEBUG > 0
//  performanceCheck();
//  while (Serial.available())
//    selectCommand(Serial.read());
//#endif
}
