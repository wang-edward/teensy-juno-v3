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
//AudioSynthWaveform       saw0;           //xy=939,347
//AudioSynthNoiseWhite     noise0;         //xy=961,418
//AudioSynthWaveform       square0;        //xy=969,280
//AudioMixer4              mixer0;         //xy=1122,361
//AudioFilterStateVariable hpf0;           //xy=1281,373
//AudioFilterStateVariable lpf0;        //xy=1423.7500228881836,381.2500057220459
//AudioOutputI2S           i2s1;           //xy=1606.0000228881836,384.2500057220459
//AudioConnection          patchCord1(saw0, 0, mixer0, 1);
//AudioConnection          patchCord2(noise0, 0, mixer0, 2);
//AudioConnection          patchCord3(square0, 0, mixer0, 0);
//AudioConnection          patchCord4(mixer0, 0, hpf0, 0);
//AudioConnection          patchCord5(hpf0, 2, lpf0, 0);
//AudioConnection          patchCord6(lpf0, 0, i2s1, 0);
//AudioConnection          patchCord7(lpf0, 0, i2s1, 1);
//AudioControlSGTL5000     sgtl5000_1;     //xy=1241,527
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

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise0;         //xy=328,288
AudioSynthWaveform       square0;      //xy=336,150
AudioSynthWaveform       saw0;      //xy=306,217
AudioMixer4              mixer0;         //xy=489,231
AudioFilterStateVariable hpf0;        //xy=648,243
AudioFilterStateVariable lpf0;        //xy=785,244
AudioEffectEnvelope      envelope0;      //xy=926,251
AudioOutputI2S           i2s1;           //xy=1128,268
AudioConnection          patchCord1(saw0, 0, mixer0, 1);
AudioConnection          patchCord2(noise0, 0, mixer0, 2);
AudioConnection          patchCord3(square0, 0, mixer0, 0);
AudioConnection          patchCord4(mixer0, 0, hpf0, 0);
AudioConnection          patchCord5(hpf0, 2, lpf0, 0);
AudioConnection          patchCord6(lpf0, 0, envelope0, 0);
AudioConnection          patchCord7(envelope0, 0, i2s1, 0);
AudioConnection          patchCord8(envelope0, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=608,397
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
  square0.pulseWidth(0.85);

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
  
  envelope0.attack(1000);
  envelope0.release(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  usbMIDI.read();
}
