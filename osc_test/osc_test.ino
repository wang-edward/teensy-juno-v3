#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform2;      //xy=463,388
AudioSynthNoisePink      pink1;          //xy=485,459
AudioSynthWaveform       waveform1;      //xy=493,321
AudioMixer4              mixer1;         //xy=682,410
AudioOutputI2S           i2s1;           //xy=868,409
AudioConnection          patchCord1(waveform2, 0, mixer1, 1);
AudioConnection          patchCord2(pink1, 0, mixer1, 2);
AudioConnection          patchCord3(waveform1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=663,521
// GUItool: end automatically generated code

void myControlChange() {
  
}

void setup() {
  // put your setup code here, to run once:
  AudioMemory(20);
  usbMIDI.setHandleControlChange(myControlChange);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(300);
  waveform1.pulseWidth(0.85);

  waveform2.begin(WAVEFORM_SAWTOOTH);
  waveform2.amplitude(0.75);
  waveform2.frequency(450);
  waveform2.pulseWidth(0.15);

  pink1.amplitude(1.0);
  mixer1.gain(0,1.0);
  mixer1.gain(1,1.0);
  mixer1.gain(2,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  usbMIDI.read();
}
