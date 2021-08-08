#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=254,502
AudioSynthNoiseWhite     noise4;         //xy=252,1030
AudioSynthNoiseWhite     noise0;         //xy=255,319
AudioSynthNoiseWhite     noise2;         //xy=255,684
AudioSynthNoiseWhite     noise5;         //xy=253,1201
AudioSynthWaveform       sub1;           //xy=257,459
AudioSynthWaveform       sub4;           //xy=255,987
AudioSynthWaveform       sub0;           //xy=258,275
AudioSynthNoiseWhite     noise3;         //xy=256,857
AudioSynthNoiseWhite     noise6;         //xy=254,1376
AudioSynthWaveform       sub2;           //xy=258,640
AudioSynthWaveform       sub5;           //xy=256,1158
AudioSynthWaveform       pulseLFO1;      //xy=260,376
AudioSynthWaveform       pulseLFO4;      //xy=258,904
AudioSynthWaveform       pulseLFO0;      //xy=261,192
AudioSynthNoiseWhite     noise7;         //xy=256,1548
AudioSynthWaveform       sub6;           //xy=257,1333
AudioSynthWaveform       pulseLFO2;      //xy=261,557
AudioSynthWaveform       sub3;           //xy=260,814
AudioSynthWaveform       pulseLFO5;      //xy=259,1075
AudioSynthWaveform       saw4;           //xy=260,939
AudioSynthWaveform       saw0;           //xy=263,228
AudioSynthWaveform       saw1;           //xy=263,412
AudioSynthWaveform       pulseLFO3;      //xy=262,730
AudioSynthWaveform       pulseLFO6;      //xy=260,1249
AudioSynthWaveform       saw5;           //xy=261,1111
AudioSynthWaveform       sub7;           //xy=260,1505
AudioSynthWaveform       saw2;           //xy=264,593
AudioSynthWaveform       pulseLFO7;      //xy=262,1421
AudioSynthWaveform       saw3;           //xy=265,766
AudioSynthWaveform       saw6;           //xy=263,1285
AudioSynthWaveform       saw7;           //xy=265,1457
AudioSynthWaveformDc     dc0;            //xy=458,113
AudioMixer4              oscMixer4;      //xy=457,982
AudioMixer4              oscMixer0;      //xy=460,270
AudioMixer4              oscMixer1;      //xy=460,454
AudioMixer4              oscMixer5;      //xy=458,1153
AudioMixer4              oscMixer2;      //xy=461,635
AudioMixer4              oscMixer3;      //xy=462,809
AudioMixer4              oscMixer6;      //xy=460,1328
AudioMixer4              oscMixer7;      //xy=462,1500
AudioEffectEnvelope      lpfEnv;      //xy=600,177
AudioFilterStateVariable hpf1;           //xy=602,465
AudioFilterStateVariable hpf4;           //xy=600,993
AudioFilterStateVariable hpf0;           //xy=603,281
AudioFilterStateVariable hpf2;           //xy=603,646
AudioFilterStateVariable hpf5;           //xy=601,1164
AudioFilterStateVariable hpf6;           //xy=602,1338
AudioFilterStateVariable hpf3;           //xy=605,820
AudioFilterStateVariable hpf7;           //xy=605,1511
AudioFilterStateVariable lpf1;           //xy=735,485
AudioFilterStateVariable lpf4;           //xy=733,1012
AudioFilterStateVariable lpf0;           //xy=736,301
AudioFilterStateVariable lpf2;           //xy=736,666
AudioFilterStateVariable lpf5;           //xy=734,1183
AudioFilterStateVariable lpf3;           //xy=737,839
AudioFilterStateVariable lpf6;           //xy=735,1358
AudioFilterStateVariable lpf7;           //xy=737,1530
AudioEffectEnvelope      env1;           //xy=873,485
AudioEffectEnvelope      env4;           //xy=871,1013
AudioEffectEnvelope      env0;           //xy=874,301
AudioEffectEnvelope      env2;           //xy=874,666
AudioEffectEnvelope      env5;           //xy=872,1184
AudioEffectEnvelope      env3;           //xy=874,831
AudioEffectEnvelope      env6;           //xy=873,1359
AudioEffectEnvelope      env7;           //xy=875,1531
AudioMixer4              EnvMixer0;      //xy=1115,575
AudioMixer4              EnvMixer1;      //xy=1138,1253
AudioMixer4              mixerL;         //xy=1368,859
AudioMixer4              mixerR;         //xy=1375,1095
AudioEffectFlange        flangerL;       //xy=1548,947
AudioEffectFlange        flangerR;       //xy=1553,1072
AudioAnalyzePeak         peak;           //xy=1572,423
AudioOutputI2S           i2s1;           //xy=1744,999
AudioConnection          patchCord1(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord2(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord3(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord4(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord5(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord6(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord7(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord8(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord9(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord10(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord11(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord12(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord13(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord14(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord15(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord16(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord17(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord18(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord19(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord20(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord21(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord22(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord23(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord24(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord25(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord26(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord27(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord28(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord29(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord30(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord31(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord32(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord33(dc0, lpfEnv);
AudioConnection          patchCord34(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord35(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord36(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord37(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord38(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord39(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord40(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord41(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord42(lpfEnv, 0, lpf0, 1);
AudioConnection          patchCord43(lpfEnv, 0, lpf1, 1);
AudioConnection          patchCord44(lpfEnv, 0, lpf2, 1);
AudioConnection          patchCord45(lpfEnv, 0, lpf3, 1);
AudioConnection          patchCord46(lpfEnv, 0, lpf4, 1);
AudioConnection          patchCord47(lpfEnv, 0, lpf5, 1);
AudioConnection          patchCord48(lpfEnv, 0, lpf6, 1);
AudioConnection          patchCord49(lpfEnv, 0, lpf7, 1);
AudioConnection          patchCord50(hpf1, 2, lpf1, 0);
AudioConnection          patchCord51(hpf4, 2, lpf4, 0);
AudioConnection          patchCord52(hpf0, 2, lpf0, 0);
AudioConnection          patchCord53(hpf2, 2, lpf2, 0);
AudioConnection          patchCord54(hpf5, 2, lpf5, 0);
AudioConnection          patchCord55(hpf6, 2, lpf6, 0);
AudioConnection          patchCord56(hpf3, 2, lpf3, 0);
AudioConnection          patchCord57(hpf7, 2, lpf7, 0);
AudioConnection          patchCord58(lpf1, 0, env1, 0);
AudioConnection          patchCord59(lpf4, 0, env4, 0);
AudioConnection          patchCord60(lpf0, 0, env0, 0);
AudioConnection          patchCord61(lpf2, 0, env2, 0);
AudioConnection          patchCord62(lpf5, 0, env5, 0);
AudioConnection          patchCord63(lpf3, 0, env3, 0);
AudioConnection          patchCord64(lpf6, 0, env6, 0);
AudioConnection          patchCord65(lpf7, 0, env7, 0);
AudioConnection          patchCord66(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord67(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord68(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord69(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord70(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord71(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord72(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord73(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord74(EnvMixer0, peak);
AudioConnection          patchCord75(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord76(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord77(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord78(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord79(mixerL, flangerL);
AudioConnection          patchCord80(mixerR, flangerR);
AudioConnection          patchCord81(flangerL, 0, i2s1, 0);
AudioConnection          patchCord82(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1525,753
// GUItool: end automatically generated code
