#include <Audio.h>

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

struct Oscillator {
  AudioSynthWaveform* squareLFO;
  AudioSynthWaveform* saw;
  AudioSynthNoiseWhite* white;
  AudioMixer4* mixer;
};

// GUItool: begin automatically generated code
AudioSynthWaveform       squareDC;       //xy=118.44999694824219,119
AudioSynthWaveform       sawDC;          //xy=182.4499969482422,250
AudioAmplifier           squareAmp;           //xy=192.4499969482422,184.4499969482422
AudioSynthWaveformModulated saw0;           //xy=362.4499969482422,214
AudioSynthWaveformModulated square0;        //xy=372.4499969482422,143
AudioMixer4              mixer0;         //xy=533.4499969482422,235
AudioOutputI2S           i2s1;           //xy=827.4499969482422,279
AudioConnection          patchCord1(squareDC, squareAmp);
AudioConnection          patchCord2(squareAmp, 0, square0, 0);
AudioConnection          patchCord3(squareAmp, 0, saw0, 0);
AudioConnection          patchCord4(saw0, 0, mixer0, 1);
AudioConnection          patchCord5(square0, 0, mixer0, 0);
AudioConnection          patchCord6(mixer0, 0, i2s1, 0);
AudioConnection          patchCord7(mixer0, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1094.4499969482422,472
// GUItool: end automatically generated code


boolean isPlaying = false;

inline float noteToFreq(float note) {
  // Sets all notes as an offset of A4 (#69)
//  if (portamentoOn) note = portamentoPos;     no portamento for now
//  return SYNTH_TUNING*pow(2,(note - 69)/12.+pitchBend/pitchScale+octCorr);
  return 440*pow(2,(note - 69)/12.); //no pitch bend for now
}

void myNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.println("new note!");
  if (!isPlaying) {
    isPlaying = true;
    square0.frequency(noteToFreq(note));
    saw0.frequency(noteToFreq(note));
    square0.amplitude(1.0);
//    saw0.amplitude(1.0);
//    envelope0.noteOn();
  }
}

void myNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {

  isPlaying = false;

//  envelope0.noteOff();
  square0.amplitude(0);
    saw0.amplitude(0);
  
}

void setup() {
  // put your setup code here, to run once:
  AudioMemory(20);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleNoteOn(myNoteOn);
  
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.025);
  square0.begin(WAVEFORM_SQUARE);
  square0.amplitude(0.75);
  
  //squareDC.begin(0.5, 1, WAVEFORM_TRIANGLE);
  squareDC.begin(0.5, 1, WAVEFORM_SINE);
  squareAmp.gain(0.5);
  saw0.begin(WAVEFORM_SAWTOOTH);
  saw0.amplitude(0.75);
  
  mixer0.gain(0,1.0);
  mixer0.gain(1,0);
  mixer0.gain(2,0);


}

void loop() {
  // put your main code here, to run repeatedly:
  usbMIDI.read();
//  if (up) {
//    squareDC.pulseWidth(x);
//    if (x >= 1) {
//      up = false;
//      } else {
//      x = x+0.01;
//    }
//  } else {
//    squareDC.pulseWidth(x);
//    if (x <= 0.01) {
//      up = true;
//    } else {
//      x = x - 0.01;
//    }
//  }
  
}
