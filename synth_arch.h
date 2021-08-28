#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     pwmDc;          //xy=176.3333282470703,276
AudioSynthWaveform       lfo;            //xy=250.3333282470703,86
AudioAmplifier           oscLfoAmp;      //xy=272.3333282470703,826
AudioMixer4              pwmMixer;       //xy=272.3333282470703,922
AudioSynthWaveformModulated sub7;           //xy=473.3333282470703,1544
AudioSynthWaveformModulated sub4;           //xy=475.3333282470703,1046
AudioSynthWaveformModulated saw7;           //xy=474.3333282470703,1505
AudioSynthWaveformModulated saw4;           //xy=476.3333282470703,1007
AudioSynthWaveformModulated sub6;           //xy=475.3333282470703,1378
AudioSynthWaveformModulated saw6;           //xy=476.3333282470703,1339
AudioSynthWaveformModulated sub5;           //xy=479.3333282470703,1214
AudioSynthWaveformModulated sub3;           //xy=481.3333282470703,881
AudioSynthWaveformModulated saw5;           //xy=480.3333282470703,1175
AudioSynthNoiseWhite     noise7;         //xy=479.3333282470703,1583
AudioSynthNoiseWhite     noise4;         //xy=481.3333282470703,1085
AudioSynthWaveformModulated saw3;           //xy=482.3333282470703,842
AudioSynthNoiseWhite     noise6;         //xy=481.3333282470703,1417
AudioSynthWaveformModulated pulseLFO7;      //xy=483.3333282470703,1464
AudioSynthWaveformModulated sub2;           //xy=486.3333282470703,715
AudioSynthWaveformModulated pulseLFO4;      //xy=485.3333282470703,966
AudioSynthWaveformModulated saw2;           //xy=487.3333282470703,676
AudioSynthNoiseWhite     noise5;         //xy=485.3333282470703,1253
AudioSynthWaveformModulated pulseLFO6;      //xy=485.3333282470703,1298
AudioSynthWaveformModulated sub0;           //xy=489.3333282470703,371
AudioSynthNoiseWhite     noise3;         //xy=487.3333282470703,920
AudioSynthWaveformModulated saw0;           //xy=490.3333282470703,332
AudioSynthWaveformModulated sub1;           //xy=490.3333282470703,544
AudioSynthWaveformModulated saw1;           //xy=491.3333282470703,505
AudioSynthWaveformModulated pulseLFO5;      //xy=489.3333282470703,1134
AudioSynthWaveformModulated pulseLFO3;      //xy=491.3333282470703,801
AudioSynthNoiseWhite     noise2;         //xy=492.3333282470703,754
AudioSynthNoiseWhite     noise0;         //xy=496.3333282470703,411
AudioSynthNoiseWhite     noise1;         //xy=496.3333282470703,583
AudioSynthWaveformModulated pulseLFO2;      //xy=496.3333282470703,635
AudioSynthWaveformModulated pulseLFO0;      //xy=499.3333282470703,291
AudioSynthWaveformModulated pulseLFO1;      //xy=500.3333282470703,464
AudioSynthWaveformDc     vcfKeyboardDc;  //xy=583.3333129882812,202
AudioSynthWaveformDc     vcfEnvDc;       //xy=613.3334045410156,92.00000762939453
AudioSynthWaveformDc     vcfModWheelDc;  //xy=669.3333129882812,249
AudioMixer4              oscMixer7;      //xy=684.3333282470703,1534
AudioMixer4              oscMixer4;      //xy=686.3333282470703,1036
AudioMixer4              oscMixer6;      //xy=686.3333282470703,1368
AudioMixer4              oscMixer5;      //xy=690.3333282470703,1204
AudioMixer4              oscMixer3;      //xy=692.3333282470703,871
AudioMixer4              oscMixer2;      //xy=697.3333282470703,705
AudioMixer4              oscMixer0;      //xy=701.3333282470703,362
AudioMixer4              oscMixer1;      //xy=701.3333282470703,534
AudioEffectEnvelope      vcfEnv;         //xy=748.3333129882812,116.00000762939453
AudioFilterStateVariable hpf7;           //xy=827.3333282470703,1545
AudioFilterStateVariable hpf4;           //xy=829.3333282470703,1047
AudioFilterStateVariable hpf6;           //xy=829.3333282470703,1379
AudioFilterStateVariable hpf5;           //xy=833.3333282470703,1215
AudioFilterStateVariable hpf3;           //xy=835.3333282470703,882
AudioFilterStateVariable hpf2;           //xy=840.3333282470703,716
AudioFilterStateVariable hpf0;           //xy=844.3333282470703,373
AudioFilterStateVariable hpf1;           //xy=844.3333282470703,545
AudioMixer4              vcfModMixer;    //xy=923.3333129882812,162
AudioFilterStateVariable lpf7;           //xy=960.3333282470703,1565
AudioFilterStateVariable lpf4;           //xy=962.3333282470703,1067
AudioFilterStateVariable lpf6;           //xy=962.3333282470703,1399
AudioFilterStateVariable lpf5;           //xy=966.3333282470703,1235
AudioFilterStateVariable lpf3;           //xy=968.3333282470703,902
AudioFilterStateVariable lpf2;           //xy=973.3333282470703,736
AudioFilterStateVariable lpf0;           //xy=977.3333282470703,393
AudioFilterStateVariable lpf1;           //xy=977.3333282470703,565
AudioEffectEnvelope      env7;           //xy=1098.3333282470703,1565
AudioEffectEnvelope      env4;           //xy=1100.3333282470703,1067
AudioAmplifier           vcfPolarity;    //xy=1104.3333282470703,241
AudioEffectEnvelope      env6;           //xy=1100.3333282470703,1399
AudioEffectEnvelope      env5;           //xy=1104.3333282470703,1235
AudioEffectEnvelope      env3;           //xy=1106.3333282470703,902
AudioEffectEnvelope      env2;           //xy=1111.3333282470703,736
AudioEffectEnvelope      env0;           //xy=1115.3333282470703,393
AudioEffectEnvelope      env1;           //xy=1115.3333282470703,565
AudioMixer4              EnvMixer0;      //xy=1356.3333282470703,667
AudioMixer4              EnvMixer1;      //xy=1379.3333282470703,1345
AudioMixer4              mixerL;         //xy=1609.3333282470703,951
AudioMixer4              mixerR;         //xy=1616.3333282470703,1187
AudioEffectFlange        flangerL;       //xy=1789.3333282470703,1039
AudioEffectFlange        flangerR;       //xy=1794.3333282470703,1164
AudioAnalyzePeak         peak;           //xy=1813.3333282470703,515
AudioOutputI2S           i2s1;           //xy=1985.3333282470703,1091
AudioConnection          patchCord1(pwmDc, 0, pwmMixer, 1);
AudioConnection          patchCord2(lfo, oscLfoAmp);
AudioConnection          patchCord3(lfo, 0, pwmMixer, 0);
AudioConnection          patchCord4(lfo, 0, vcfModMixer, 1);
AudioConnection          patchCord5(oscLfoAmp, 0, pulseLFO0, 0);
AudioConnection          patchCord6(oscLfoAmp, 0, sub0, 0);
AudioConnection          patchCord7(oscLfoAmp, 0, pulseLFO1, 0);
AudioConnection          patchCord8(oscLfoAmp, 0, sub1, 0);
AudioConnection          patchCord9(oscLfoAmp, 0, pulseLFO2, 0);
AudioConnection          patchCord10(oscLfoAmp, 0, sub2, 0);
AudioConnection          patchCord11(oscLfoAmp, 0, pulseLFO3, 0);
AudioConnection          patchCord12(oscLfoAmp, 0, sub3, 0);
AudioConnection          patchCord13(oscLfoAmp, 0, pulseLFO4, 0);
AudioConnection          patchCord14(oscLfoAmp, 0, sub4, 0);
AudioConnection          patchCord15(oscLfoAmp, 0, pulseLFO5, 0);
AudioConnection          patchCord16(oscLfoAmp, 0, sub5, 0);
AudioConnection          patchCord17(oscLfoAmp, 0, pulseLFO6, 0);
AudioConnection          patchCord18(oscLfoAmp, 0, sub6, 0);
AudioConnection          patchCord19(oscLfoAmp, 0, pulseLFO7, 0);
AudioConnection          patchCord20(oscLfoAmp, 0, sub7, 0);
AudioConnection          patchCord21(oscLfoAmp, 0, saw0, 0);
AudioConnection          patchCord22(oscLfoAmp, 0, saw1, 0);
AudioConnection          patchCord23(oscLfoAmp, 0, saw2, 0);
AudioConnection          patchCord24(oscLfoAmp, 0, saw3, 0);
AudioConnection          patchCord25(oscLfoAmp, 0, saw4, 0);
AudioConnection          patchCord26(oscLfoAmp, 0, saw5, 0);
AudioConnection          patchCord27(oscLfoAmp, 0, saw6, 0);
AudioConnection          patchCord28(oscLfoAmp, 0, saw7, 0);
AudioConnection          patchCord29(pwmMixer, 0, pulseLFO0, 1);
AudioConnection          patchCord30(pwmMixer, 0, pulseLFO1, 1);
AudioConnection          patchCord31(pwmMixer, 0, pulseLFO2, 1);
AudioConnection          patchCord32(pwmMixer, 0, pulseLFO3, 1);
AudioConnection          patchCord33(pwmMixer, 0, pulseLFO4, 1);
AudioConnection          patchCord34(pwmMixer, 0, pulseLFO5, 1);
AudioConnection          patchCord35(pwmMixer, 0, pulseLFO6, 1);
AudioConnection          patchCord36(pwmMixer, 0, pulseLFO7, 1);
AudioConnection          patchCord37(pwmMixer, 0, sub0, 1);
AudioConnection          patchCord38(pwmMixer, 0, sub1, 1);
AudioConnection          patchCord39(pwmMixer, 0, sub2, 1);
AudioConnection          patchCord40(pwmMixer, 0, sub3, 1);
AudioConnection          patchCord41(pwmMixer, 0, sub4, 1);
AudioConnection          patchCord42(pwmMixer, 0, sub5, 1);
AudioConnection          patchCord43(pwmMixer, 0, sub6, 1);
AudioConnection          patchCord44(pwmMixer, 0, sub7, 1);
AudioConnection          patchCord45(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord46(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord47(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord48(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord49(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord50(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord51(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord52(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord53(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord54(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord55(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord56(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord57(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord58(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord59(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord60(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord61(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord62(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord63(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord64(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord65(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord66(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord67(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord68(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord69(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord70(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord71(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord72(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord73(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord74(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord75(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord76(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord77(vcfKeyboardDc, 0, vcfModMixer, 2);
AudioConnection          patchCord78(vcfEnvDc, vcfEnv);
AudioConnection          patchCord79(vcfModWheelDc, 0, vcfModMixer, 3);
AudioConnection          patchCord80(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord81(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord82(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord83(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord84(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord85(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord86(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord87(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord88(vcfEnv, 0, vcfModMixer, 0);
AudioConnection          patchCord89(hpf7, 2, lpf7, 0);
AudioConnection          patchCord90(hpf4, 2, lpf4, 0);
AudioConnection          patchCord91(hpf6, 2, lpf6, 0);
AudioConnection          patchCord92(hpf5, 2, lpf5, 0);
AudioConnection          patchCord93(hpf3, 2, lpf3, 0);
AudioConnection          patchCord94(hpf2, 2, lpf2, 0);
AudioConnection          patchCord95(hpf0, 2, lpf0, 0);
AudioConnection          patchCord96(hpf1, 2, lpf1, 0);
AudioConnection          patchCord97(vcfModMixer, 0, lpf0, 1);
AudioConnection          patchCord98(vcfModMixer, 0, lpf1, 1);
AudioConnection          patchCord99(vcfModMixer, 0, lpf2, 1);
AudioConnection          patchCord100(vcfModMixer, 0, lpf3, 1);
AudioConnection          patchCord101(vcfModMixer, 0, lpf4, 1);
AudioConnection          patchCord102(vcfModMixer, 0, lpf5, 1);
AudioConnection          patchCord103(vcfModMixer, 0, lpf6, 1);
AudioConnection          patchCord104(vcfModMixer, 0, lpf7, 1);
AudioConnection          patchCord105(lpf7, 0, env7, 0);
AudioConnection          patchCord106(lpf4, 0, env4, 0);
AudioConnection          patchCord107(lpf6, 0, env6, 0);
AudioConnection          patchCord108(lpf5, 0, env5, 0);
AudioConnection          patchCord109(lpf3, 0, env3, 0);
AudioConnection          patchCord110(lpf2, 0, env2, 0);
AudioConnection          patchCord111(lpf0, 0, env0, 0);
AudioConnection          patchCord112(lpf1, 0, env1, 0);
AudioConnection          patchCord113(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord114(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord115(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord116(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord117(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord118(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord119(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord120(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord121(EnvMixer0, peak);
AudioConnection          patchCord122(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord123(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord124(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord125(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord126(mixerL, flangerL);
AudioConnection          patchCord127(mixerR, flangerR);
AudioConnection          patchCord128(flangerL, 0, i2s1, 0);
AudioConnection          patchCord129(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1766.3333282470703,845
// GUItool: end automatically generated code
