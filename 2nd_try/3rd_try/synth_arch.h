//#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
//#include <SD.h>
//#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=411.5,1660
AudioSynthNoiseWhite     noise4;         //xy=409.5,2188
AudioSynthNoiseWhite     noise0;         //xy=412.5,1477
AudioSynthNoiseWhite     noise2;         //xy=412.5,1842
AudioSynthNoiseWhite     noise5;         //xy=410.5,2359
AudioSynthWaveform       sub1;           //xy=414.5,1617
AudioSynthWaveform       sub4;           //xy=412.5,2145
AudioSynthWaveform       sub0;           //xy=415.5,1433
AudioSynthNoiseWhite     noise3;         //xy=413.5,2015
AudioSynthNoiseWhite     noise6;         //xy=411.5,2534
AudioSynthWaveform       sub2;           //xy=415.5,1798
AudioSynthWaveform       sub5;           //xy=413.5,2316
AudioSynthWaveform       pulseLFO1;      //xy=417.5,1534
AudioSynthWaveform       pulseLFO4;      //xy=415.5,2062
AudioSynthWaveform       pulseLFO0;      //xy=418.5,1350
AudioSynthNoiseWhite     noise7;         //xy=413.5,2706
AudioSynthWaveform       sub6;           //xy=414.5,2491
AudioSynthWaveform       pulseLFO2;      //xy=418.5,1715
AudioSynthWaveform       sub3;           //xy=417.5,1972
AudioSynthWaveform       pulseLFO5;      //xy=416.5,2233
AudioSynthWaveform       saw4;           //xy=417.5,2097
AudioSynthWaveform       saw0;           //xy=420.5,1386
AudioSynthWaveform       saw1;           //xy=420.5,1570
AudioSynthWaveform       pulseLFO3;      //xy=419.5,1888
AudioSynthWaveform       pulseLFO6;      //xy=417.5,2407
AudioSynthWaveform       saw5;           //xy=418.5,2269
AudioSynthWaveform       sub7;           //xy=417.5,2663
AudioSynthWaveform       saw2;           //xy=421.5,1751
AudioSynthWaveform       pulseLFO7;      //xy=419.5,2579
AudioSynthWaveform       saw3;           //xy=422.5,1924
AudioSynthWaveform       saw6;           //xy=420.5,2443
AudioSynthWaveform       saw7;           //xy=422.5,2615
AudioMixer4              oscMixer4;      //xy=614.5,2140
AudioMixer4              oscMixer0;      //xy=617.5,1428
AudioMixer4              oscMixer1;      //xy=617.5,1612
AudioMixer4              oscMixer5;      //xy=615.5,2311
AudioMixer4              oscMixer2;      //xy=618.5,1793
AudioMixer4              oscMixer3;      //xy=619.5,1967
AudioMixer4              oscMixer6;      //xy=617.5,2486
AudioMixer4              oscMixer7;      //xy=619.5,2658
AudioFilterStateVariable hpf1;           //xy=759.5,1623
AudioFilterStateVariable hpf4;           //xy=757.5,2151
AudioFilterStateVariable hpf0;           //xy=760.5,1439
AudioFilterStateVariable hpf2;           //xy=760.5,1804
AudioFilterStateVariable hpf5;           //xy=758.5,2322
AudioFilterStateVariable hpf6;           //xy=759.5,2496
AudioFilterStateVariable hpf3;           //xy=762.5,1978
AudioFilterStateVariable hpf7;           //xy=762.5,2669
AudioFilterStateVariable lpf1;           //xy=892.5,1643
AudioFilterStateVariable lpf4;           //xy=890.5,2170
AudioFilterStateVariable lpf0;           //xy=893.5,1459
AudioFilterStateVariable lpf2;           //xy=893.5,1824
AudioFilterStateVariable lpf5;           //xy=891.5,2341
AudioFilterStateVariable lpf3;           //xy=894.5,1997
AudioFilterStateVariable lpf6;           //xy=892.5,2516
AudioFilterStateVariable lpf7;           //xy=894.5,2688
AudioEffectEnvelope      env1;           //xy=1030.5,1643
AudioEffectEnvelope      env4;           //xy=1028.5,2171
AudioEffectEnvelope      env0;           //xy=1031.5,1459
AudioEffectEnvelope      env2;           //xy=1031.5,1824
AudioEffectEnvelope      env5;           //xy=1029.5,2342
AudioEffectEnvelope      env3;           //xy=1031.5,1989
AudioEffectEnvelope      env6;           //xy=1030.5,2517
AudioEffectEnvelope      env7;           //xy=1032.5,2689
AudioMixer4              EnvMixer0;      //xy=1286.5,1566
AudioMixer4              EnvMixer1;      //xy=1286.5,1898
AudioMixer4              EnvMixer3;      //xy=1295.5,2567
AudioMixer4              EnvMixer2;      //xy=1298.5,2215
AudioMixer4              mixerL;         //xy=1525.5,2017
AudioMixer4              mixerR;         //xy=1532.5,2253
AudioOutputI2S           i2s1;           //xy=1901.5,2157
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
AudioConnection          patchCord33(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord34(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord35(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord36(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord37(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord38(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord39(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord40(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord41(hpf1, 2, lpf1, 0);
AudioConnection          patchCord42(hpf4, 2, lpf4, 0);
AudioConnection          patchCord43(hpf0, 2, lpf0, 0);
AudioConnection          patchCord44(hpf2, 2, lpf2, 0);
AudioConnection          patchCord45(hpf5, 2, lpf5, 0);
AudioConnection          patchCord46(hpf6, 2, lpf6, 0);
AudioConnection          patchCord47(hpf3, 2, lpf3, 0);
AudioConnection          patchCord48(hpf7, 2, lpf7, 0);
AudioConnection          patchCord49(lpf1, 0, env1, 0);
AudioConnection          patchCord50(lpf1, 0, EnvMixer0, 3);
AudioConnection          patchCord51(lpf4, 0, env4, 0);
AudioConnection          patchCord52(lpf4, 0, EnvMixer2, 1);
AudioConnection          patchCord53(lpf0, 0, env0, 0);
AudioConnection          patchCord54(lpf0, 0, EnvMixer0, 1);
AudioConnection          patchCord55(lpf2, 0, env2, 0);
AudioConnection          patchCord56(lpf2, 0, EnvMixer1, 1);
AudioConnection          patchCord57(lpf5, 0, env5, 0);
AudioConnection          patchCord58(lpf5, 0, EnvMixer2, 3);
AudioConnection          patchCord59(lpf3, 0, env3, 0);
AudioConnection          patchCord60(lpf3, 0, EnvMixer1, 3);
AudioConnection          patchCord61(lpf6, 0, env6, 0);
AudioConnection          patchCord62(lpf6, 0, EnvMixer3, 1);
AudioConnection          patchCord63(lpf7, 0, env7, 0);
AudioConnection          patchCord64(lpf7, 0, EnvMixer3, 3);
AudioConnection          patchCord65(env1, 0, EnvMixer0, 2);
AudioConnection          patchCord66(env4, 0, EnvMixer2, 0);
AudioConnection          patchCord67(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord68(env2, 0, EnvMixer1, 0);
AudioConnection          patchCord69(env5, 0, EnvMixer2, 2);
AudioConnection          patchCord70(env3, 0, EnvMixer1, 2);
AudioConnection          patchCord71(env6, 0, EnvMixer3, 0);
AudioConnection          patchCord72(env7, 0, EnvMixer3, 2);
AudioConnection          patchCord73(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord74(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord75(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord76(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord77(EnvMixer3, 0, mixerL, 3);
AudioConnection          patchCord78(EnvMixer3, 0, mixerR, 3);
AudioConnection          patchCord79(EnvMixer2, 0, mixerL, 2);
AudioConnection          patchCord80(EnvMixer2, 0, mixerR, 2);
AudioConnection          patchCord81(mixerL, 0, i2s1, 0);
AudioConnection          patchCord82(mixerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1682.5,1911
// GUItool: end automatically generated code
