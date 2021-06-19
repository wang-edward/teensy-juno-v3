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
AudioSynthWaveform       saw0;           //xy=171,171
AudioSynthNoiseWhite     noise0;         //xy=193,242
AudioSynthWaveform       square0;        //xy=201,104
AudioMixer4              mixer0;         //xy=354,185
AudioFilterStateVariable hpf0;           //xy=513,197
AudioFilterStateVariable lpf0;           //xy=655,205
AudioEffectChorus        chorus1;        //xy=828.75,208.75
AudioOutputI2S           i2s1;           //xy=1013,230.50003051757812
AudioConnection          patchCord1(saw0, 0, mixer0, 1);
AudioConnection          patchCord2(noise0, 0, mixer0, 2);
AudioConnection          patchCord3(square0, 0, mixer0, 0);
AudioConnection          patchCord4(mixer0, 0, hpf0, 0);
AudioConnection          patchCord5(hpf0, 2, lpf0, 0);
AudioConnection          patchCord6(lpf0, 0, chorus1, 0);
AudioConnection          patchCord7(chorus1, 0, i2s1, 0);
AudioConnection          patchCord8(chorus1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=473,351
// GUItool: end automatically generated code



/////////////////////////////////////////////

// GUItool: begin automatically generated code
//AudioSynthWaveform       saw0;      //xy=306,217
//AudioSynthNoiseWhite     noise0;         //xy=328,288
//AudioSynthWaveform       square0;      //xy=336,150
//AudioMixer4              mixer0;         //xy=476,238
//AudioOutputI2S           i2s1;           //xy=665,239
//AudioConnection          patchCord1(saw0, 0, mixer0, 1);
//AudioConnection          patchCord2(noise0, 0, mixer0, 2);
//AudioConnection          patchCord3(square0, 0, mixer0, 0);
//AudioConnection          patchCord4(mixer0, 0, i2s1, 0);
//AudioConnection          patchCord5(mixer0, 0, i2s1, 1);
//AudioControlSGTL5000     sgtl5000_1;     //xy=608,397
// GUItool: end automatically generated code


//////////////////////////////////////////

//modulated square!
// GUItool: begin automatically generated code
//AudioSynthWaveform       squareDC;      //xy=1358.5714285714284,1019.9999999999999
//AudioSynthNoiseWhite     noise0;         //xy=1402.142780303955,1171.571496963501
//AudioSynthWaveform       saw0;           //xy=1414.4286346435547,1100.5714626312256
//AudioSynthWaveformModulated square0;   //xy=1542.857135772705,1005.714277267456
//AudioMixer4              mixer0;         //xy=1606,1106
//AudioFilterStateVariable hpf0;           //xy=1765,1118
//AudioFilterStateVariable lpf0;           //xy=1902,1119
//AudioEffectEnvelope      envelope0;      //xy=2043,1126
//AudioOutputI2S           i2s1;           //xy=2245,1143
//AudioConnection          patchCord1(squareDC, 0, square0, 1);
//AudioConnection          patchCord2(noise0, 0, mixer0, 2);
//AudioConnection          patchCord3(saw0, 0, mixer0, 1);
//AudioConnection          patchCord4(square0, 0, mixer0, 0);
//AudioConnection          patchCord5(mixer0, 0, hpf0, 0);
//AudioConnection          patchCord6(hpf0, 2, lpf0, 0);
//AudioConnection          patchCord7(lpf0, 0, envelope0, 0);
//AudioConnection          patchCord8(envelope0, 0, i2s1, 0);
//AudioConnection          patchCord9(envelope0, 0, i2s1, 1);
//AudioControlSGTL5000     sgtl5000_1;     //xy=1725,1272
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
//    square0.amplitude(1.0);
//    saw0.amplitude(1.0);
    envelope0.noteOn();
  }
}

void myNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  Serial.println("note off!");
  isPlaying = false;
  Serial.print("BEFORE");
  envelope0.noteOff();
  Serial.println("AFTER");
}

void setup() {
  // put your setup code here, to run once:
  AudioMemory(20);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleNoteOn(myNoteOn);
  
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.4);
  square0.begin(WAVEFORM_SQUARE);
  square0.amplitude(0.75);
  
  squareDC.begin(WAVEFORM_SQUARE);
  squareDC.pulseWidth(0.85);

  saw0.begin(WAVEFORM_SAWTOOTH);
  saw0.amplitude(0.75);
  saw0.pulseWidth(0.15);

  noise0.amplitude(1.0);
  
  mixer0.gain(0,1.0);
  mixer0.gain(1,1.0);
  mixer0.gain(2,0);

  hpf0.frequency(0);
  lpf0.frequency(2000);
  
//  envelope0.delay(0);
//  envelope0.hold(0);
  
  envelope0.attack(100);
  envelope0.release(100);

  
}
boolean up = true;
  float x = 0.01;

void loop() {
  // put your main code here, to run repeatedly:
  usbMIDI.read();
  if (up) {
    squareDC.pulseWidth(x);
    if (x >= 1) {
      up = false;
      } else {
      x = x+0.01;
    }
  } else {
    squareDC.pulseWidth(x);
    if (x <= 0.01) {
      up = true;
    } else {
      x = x - 0.01;
    }
  }
  
}
