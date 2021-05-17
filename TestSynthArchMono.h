#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise0;         //xy=525,1391
AudioSynthWaveformModulated squarePWM0; //xy=528.4443969726562,1347.6685791015625
AudioSynthWaveformModulated squareLFO0; //xy=531.3333129882812,1264.3629035949707
AudioSynthWaveformModulated saw0; //xy=533.6666412353516,1300.1406784057617
AudioMixer4              oscMixer0; //xy=730.5833320617676,1342.66845703125
AudioFilterStateVariable hpf0;  //xy=873.4443702697754,1353.6683330535889
AudioFilterStateVariable lpf0; //xy=1006.2221832275391,1373.1128063201904
AudioEffectEnvelope      env0; //xy=1144.001708984375,1373.890625
AudioMixer4              EnvMixer0; //xy=1305.2240371704102,1419.335355758667
AudioAnalyzePeak         peak; //xy=1495.0017127990723,1347.89066696167
AudioOutputI2S           i2s1; //xy=1526.5571784973145,1468.3350992202759
AudioConnection          patchCord1(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord2(squarePWM0, 0, oscMixer0, 2);
AudioConnection          patchCord3(squareLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord4(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord5(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord6(hpf0, 2, lpf0, 0);
AudioConnection          patchCord7(lpf0, 0, env0, 0);
AudioConnection          patchCord8(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord9(EnvMixer0, peak);
AudioConnection          patchCord10(EnvMixer0, 0, i2s1, 0);
AudioConnection          patchCord11(EnvMixer0, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1319.9842529296875,1205.7857666015625
// GUItool: end automatically generated code
