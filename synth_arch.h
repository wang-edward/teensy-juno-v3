#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=203.08334350585938,412
AudioSynthNoiseWhite     noise4;         //xy=201.08334350585938,940
AudioSynthNoiseWhite     noise0;         //xy=204.08334350585938,229
AudioSynthNoiseWhite     noise2;         //xy=204.08334350585938,594
AudioSynthNoiseWhite     noise5;         //xy=202.08334350585938,1111
AudioSynthWaveform       sub1;           //xy=206.08334350585938,369
AudioSynthWaveform       sub4;           //xy=204.08334350585938,897
AudioSynthWaveform       sub0;           //xy=207.08334350585938,185
AudioSynthNoiseWhite     noise3;         //xy=205.08334350585938,767
AudioSynthNoiseWhite     noise6;         //xy=203.08334350585938,1286
AudioSynthWaveform       sub2;           //xy=207.08334350585938,550
AudioSynthWaveform       sub5;           //xy=205.08334350585938,1068
AudioSynthWaveform       pulseLFO1;      //xy=209.08334350585938,286
AudioSynthWaveform       pulseLFO4;      //xy=207.08334350585938,814
AudioSynthWaveform       pulseLFO0;      //xy=210.08334350585938,102
AudioSynthNoiseWhite     noise7;         //xy=205.08334350585938,1458
AudioSynthWaveform       sub6;           //xy=206.08334350585938,1243
AudioSynthWaveform       pulseLFO2;      //xy=210.08334350585938,467
AudioSynthWaveform       sub3;           //xy=209.08334350585938,724
AudioSynthWaveform       pulseLFO5;      //xy=208.08334350585938,985
AudioSynthWaveform       saw4;           //xy=209.08334350585938,849
AudioSynthWaveform       saw0;           //xy=212.08334350585938,138
AudioSynthWaveform       saw1;           //xy=212.08334350585938,322
AudioSynthWaveform       pulseLFO3;      //xy=211.08334350585938,640
AudioSynthWaveform       pulseLFO6;      //xy=209.08334350585938,1159
AudioSynthWaveform       saw5;           //xy=210.08334350585938,1021
AudioSynthWaveform       sub7;           //xy=209.08334350585938,1415
AudioSynthWaveform       saw2;           //xy=213.08334350585938,503
AudioSynthWaveform       pulseLFO7;      //xy=211.08334350585938,1331
AudioSynthWaveform       saw3;           //xy=214.08334350585938,676
AudioSynthWaveform       saw6;           //xy=212.08334350585938,1195
AudioSynthWaveform       saw7;           //xy=214.08334350585938,1367
AudioMixer4              oscMixer4;      //xy=406.0833435058594,892
AudioMixer4              oscMixer0;      //xy=409.0833435058594,180
AudioMixer4              oscMixer1;      //xy=409.0833435058594,364
AudioMixer4              oscMixer5;      //xy=407.0833435058594,1063
AudioMixer4              oscMixer2;      //xy=410.0833435058594,545
AudioMixer4              oscMixer3;      //xy=411.0833435058594,719
AudioMixer4              oscMixer6;      //xy=409.0833435058594,1238
AudioMixer4              oscMixer7;      //xy=411.0833435058594,1410
AudioFilterStateVariable hpf1;           //xy=551.0833435058594,375
AudioFilterStateVariable hpf4;           //xy=549.0833435058594,903
AudioFilterStateVariable hpf0;           //xy=552.0833435058594,191
AudioFilterStateVariable hpf2;           //xy=552.0833435058594,556
AudioFilterStateVariable hpf5;           //xy=550.0833435058594,1074
AudioFilterStateVariable hpf6;           //xy=551.0833435058594,1248
AudioFilterStateVariable hpf3;           //xy=554.0833435058594,730
AudioFilterStateVariable hpf7;           //xy=554.0833435058594,1421
AudioFilterStateVariable lpf1;           //xy=684.0833435058594,395
AudioFilterStateVariable lpf4;           //xy=682.0833435058594,922
AudioFilterStateVariable lpf0;           //xy=685.0833435058594,211
AudioFilterStateVariable lpf2;           //xy=685.0833435058594,576
AudioFilterStateVariable lpf5;           //xy=683.0833435058594,1093
AudioFilterStateVariable lpf3;           //xy=686.0833435058594,749
AudioFilterStateVariable lpf6;           //xy=684.0833435058594,1268
AudioFilterStateVariable lpf7;           //xy=686.0833435058594,1440
AudioAmplifier           amp5; //xy=731.6500244140625,1031.8499755859375
AudioAmplifier           amp4; //xy=737.6500244140625,862.25
AudioAmplifier           amp6; //xy=739.6500244140625,1214.8499755859375
AudioAmplifier           amp0;           //xy=747,137
AudioAmplifier           amp3; //xy=747.6500244140625,691.8499755859375
AudioAmplifier           amp7; //xy=752.6500244140625,1382.8499755859375
AudioAmplifier           amp1; //xy=758.6500244140625,333.45001220703125
AudioAmplifier           amp2; //xy=761.6500244140625,517.4500122070312
AudioEffectEnvelope      env1;           //xy=822.0833435058594,395
AudioEffectEnvelope      env4;           //xy=820.0833435058594,923
AudioEffectEnvelope      env0;           //xy=823.0833435058594,211
AudioEffectEnvelope      env2;           //xy=823.0833435058594,576
AudioEffectEnvelope      env5;           //xy=821.0833435058594,1094
AudioEffectEnvelope      env3;           //xy=823.0833435058594,741
AudioEffectEnvelope      env6;           //xy=822.0833435058594,1269
AudioEffectEnvelope      env7;           //xy=824.0833435058594,1441
AudioMixer4              EnvMixer0;      //xy=1064.0833435058594,485
AudioMixer4              EnvMixer1;      //xy=1087.0833435058594,1163
AudioMixer4              mixerL;         //xy=1317.0833435058594,769
AudioMixer4              mixerR;         //xy=1324.0833435058594,1005
AudioEffectFlange        flangerL;       //xy=1497.0833435058594,857
AudioEffectFlange        flangerR;       //xy=1502.0833435058594,982
AudioAnalyzePeak         peak;           //xy=1521.0833435058594,333
AudioOutputI2S           i2s1;           //xy=1693.0833435058594,909
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
AudioConnection          patchCord50(lpf4, 0, env4, 0);
AudioConnection          patchCord51(lpf0, 0, env0, 0);
AudioConnection          patchCord52(lpf2, 0, env2, 0);
AudioConnection          patchCord53(lpf5, 0, env5, 0);
AudioConnection          patchCord54(lpf3, 0, env3, 0);
AudioConnection          patchCord55(lpf6, 0, env6, 0);
AudioConnection          patchCord56(lpf7, 0, env7, 0);
AudioConnection          patchCord57(amp5, 0, lpf5, 1);
AudioConnection          patchCord58(amp4, 0, lpf4, 1);
AudioConnection          patchCord59(amp6, 0, lpf6, 1);
AudioConnection          patchCord60(amp0, 0, lpf0, 1);
AudioConnection          patchCord61(amp3, 0, lpf3, 1);
AudioConnection          patchCord62(amp7, 0, lpf7, 1);
AudioConnection          patchCord63(amp1, 0, lpf1, 1);
AudioConnection          patchCord64(amp2, 0, lpf2, 1);
AudioConnection          patchCord65(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord66(env1, amp1);
AudioConnection          patchCord67(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord68(env4, amp4);
AudioConnection          patchCord69(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord70(env0, amp0);
AudioConnection          patchCord71(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord72(env2, amp2);
AudioConnection          patchCord73(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord74(env5, amp5);
AudioConnection          patchCord75(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord76(env3, amp3);
AudioConnection          patchCord77(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord78(env6, amp6);
AudioConnection          patchCord79(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord80(env7, amp7);
AudioConnection          patchCord81(EnvMixer0, peak);
AudioConnection          patchCord82(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord83(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord84(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord85(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord86(mixerL, flangerL);
AudioConnection          patchCord87(mixerR, flangerR);
AudioConnection          patchCord88(flangerL, 0, i2s1, 0);
AudioConnection          patchCord89(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1474.0833435058594,663
// GUItool: end automatically generated code
