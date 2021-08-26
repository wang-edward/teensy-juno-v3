#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     pwmDc;          //xy=138.3333282470703,210
AudioSynthWaveform       lfo;            //xy=212.3333282470703,20
AudioAmplifier           dcoPitchAmp;    //xy=234.33331298828125,760
AudioMixer4              pwmMixer;       //xy=234.3333282470703,856
AudioSynthWaveformModulated sub7;           //xy=435.3333282470703,1478
AudioSynthWaveformModulated sub4;           //xy=437.3333282470703,980
AudioSynthWaveformModulated saw7;           //xy=436.3333282470703,1439
AudioSynthWaveformModulated saw4;           //xy=438.3333282470703,941
AudioSynthWaveformModulated sub6;           //xy=437.3333282470703,1312
AudioSynthWaveformModulated saw6;           //xy=438.3333282470703,1273
AudioSynthWaveformModulated sub5;           //xy=441.3333282470703,1148
AudioSynthWaveformModulated sub3;           //xy=443.3333282470703,815
AudioSynthWaveformModulated saw5;           //xy=442.3333282470703,1109
AudioSynthNoiseWhite     noise7;         //xy=441.3333282470703,1517
AudioSynthNoiseWhite     noise4;         //xy=443.3333282470703,1019
AudioSynthWaveformModulated saw3;           //xy=444.3333282470703,776
AudioSynthNoiseWhite     noise6;         //xy=443.3333282470703,1351
AudioSynthWaveformModulated pulseLFO7;      //xy=445.3333282470703,1398
AudioSynthWaveformModulated sub2;           //xy=448.3333282470703,649
AudioSynthWaveformModulated pulseLFO4;      //xy=447.3333282470703,900
AudioSynthWaveformModulated saw2;           //xy=449.3333282470703,610
AudioSynthNoiseWhite     noise5;         //xy=447.3333282470703,1187
AudioSynthWaveformModulated pulseLFO6;      //xy=447.3333282470703,1232
AudioSynthWaveformModulated sub0;           //xy=451.3333282470703,305
AudioSynthNoiseWhite     noise3;         //xy=449.3333282470703,854
AudioSynthWaveformModulated saw0;           //xy=452.3333282470703,266
AudioSynthWaveformModulated sub1;           //xy=452.3333282470703,478
AudioSynthWaveformModulated saw1;           //xy=453.3333282470703,439
AudioSynthWaveformModulated pulseLFO5;      //xy=451.3333282470703,1068
AudioSynthWaveformModulated pulseLFO3;      //xy=453.3333282470703,735
AudioSynthNoiseWhite     noise2;         //xy=454.3333282470703,688
AudioSynthNoiseWhite     noise0;         //xy=458.3333282470703,345
AudioSynthNoiseWhite     noise1;         //xy=458.3333282470703,517
AudioSynthWaveformModulated pulseLFO2;      //xy=458.3333282470703,569
AudioSynthWaveformModulated pulseLFO0;      //xy=461.3333282470703,225
AudioSynthWaveformModulated pulseLFO1;      //xy=462.3333282470703,398
AudioMixer4              oscMixer7;      //xy=646.3333282470703,1468
AudioMixer4              oscMixer4;      //xy=648.3333282470703,970
AudioMixer4              oscMixer6;      //xy=648.3333282470703,1302
AudioMixer4              oscMixer5;      //xy=652.3333282470703,1138
AudioMixer4              oscMixer3;      //xy=654.3333282470703,805
AudioMixer4              oscMixer2;      //xy=659.3333282470703,639
AudioMixer4              oscMixer0;      //xy=663.3333282470703,296
AudioMixer4              oscMixer1;      //xy=663.3333282470703,468
AudioFilterStateVariable hpf7;           //xy=789.3333282470703,1479
AudioFilterStateVariable hpf4;           //xy=791.3333282470703,981
AudioFilterStateVariable hpf6;           //xy=791.3333282470703,1313
AudioFilterStateVariable hpf5;           //xy=795.3333282470703,1149
AudioFilterStateVariable hpf3;           //xy=797.3333282470703,816
AudioFilterStateVariable hpf2;           //xy=802.3333282470703,650
AudioFilterStateVariable hpf0;           //xy=806.3333282470703,307
AudioFilterStateVariable hpf1;           //xy=806.3333282470703,479
AudioSynthWaveformDc     vcfEnvDc;       //xy=830.3333282470703,90
AudioSynthWaveformDc     vcfKeyboardDc;  //xy=850.3333282470703,124
AudioSynthWaveformDc     vcfModWheelDc;  //xy=852.3333282470703,159
AudioSynthWaveform       waveform1;      //xy=889.3333282470703,223
AudioFilterStateVariable lpf7;           //xy=922.3333282470703,1499
AudioFilterStateVariable lpf4;           //xy=924.3333282470703,1001
AudioFilterStateVariable lpf6;           //xy=924.3333282470703,1333
AudioFilterStateVariable lpf5;           //xy=928.3333282470703,1169
AudioFilterStateVariable lpf3;           //xy=930.3333282470703,836
AudioFilterStateVariable lpf2;           //xy=935.3333282470703,670
AudioFilterStateVariable lpf0;           //xy=939.3333282470703,327
AudioFilterStateVariable lpf1;           //xy=939.3333282470703,499
AudioEffectEnvelope      vcfEnv;         //xy=963.3333282470703,90
AudioEffectEnvelope      env7;           //xy=1060.3333282470703,1499
AudioEffectEnvelope      env4;           //xy=1062.3333282470703,1001
AudioEffectEnvelope      env6;           //xy=1062.3333282470703,1333
AudioEffectEnvelope      env5;           //xy=1066.3333282470703,1169
AudioEffectEnvelope      env3;           //xy=1068.3333282470703,836
AudioEffectEnvelope      env2;           //xy=1073.3333282470703,670
AudioEffectEnvelope      env0;           //xy=1077.3333282470703,327
AudioEffectEnvelope      env1;           //xy=1077.3333282470703,499
AudioMixer4              vcfModMixer;    //xy=1166.3333282470703,113
AudioMixer4              EnvMixer0;      //xy=1318.3333282470703,601
AudioMixer4              EnvMixer1;      //xy=1341.3333282470703,1279
AudioMixer4              mixerL;         //xy=1571.3333282470703,885
AudioMixer4              mixerR;         //xy=1578.3333282470703,1121
AudioEffectFlange        flangerL;       //xy=1751.3333282470703,973
AudioEffectFlange        flangerR;       //xy=1756.3333282470703,1098
AudioAnalyzePeak         peak;           //xy=1775.3333282470703,449
AudioOutputI2S           i2s1;           //xy=1947.3333282470703,1025
AudioConnection          patchCord1(pwmDc, 0, pwmMixer, 1);
AudioConnection          patchCord2(lfo, 0, vcfModMixer, 0);
AudioConnection          patchCord3(lfo, dcoPitchAmp);
AudioConnection          patchCord4(lfo, 0, pwmMixer, 0);
AudioConnection          patchCord5(dcoPitchAmp, 0, pulseLFO0, 0);
AudioConnection          patchCord6(dcoPitchAmp, 0, sub0, 0);
AudioConnection          patchCord7(dcoPitchAmp, 0, pulseLFO1, 0);
AudioConnection          patchCord8(dcoPitchAmp, 0, sub1, 0);
AudioConnection          patchCord9(dcoPitchAmp, 0, pulseLFO2, 0);
AudioConnection          patchCord10(dcoPitchAmp, 0, sub2, 0);
AudioConnection          patchCord11(dcoPitchAmp, 0, pulseLFO3, 0);
AudioConnection          patchCord12(dcoPitchAmp, 0, sub3, 0);
AudioConnection          patchCord13(dcoPitchAmp, 0, pulseLFO4, 0);
AudioConnection          patchCord14(dcoPitchAmp, 0, sub4, 0);
AudioConnection          patchCord15(dcoPitchAmp, 0, pulseLFO5, 0);
AudioConnection          patchCord16(dcoPitchAmp, 0, sub5, 0);
AudioConnection          patchCord17(dcoPitchAmp, 0, pulseLFO6, 0);
AudioConnection          patchCord18(dcoPitchAmp, 0, sub6, 0);
AudioConnection          patchCord19(dcoPitchAmp, 0, pulseLFO7, 0);
AudioConnection          patchCord20(dcoPitchAmp, 0, sub7, 0);
AudioConnection          patchCord21(pwmMixer, 0, pulseLFO0, 1);
AudioConnection          patchCord22(pwmMixer, 0, pulseLFO1, 1);
AudioConnection          patchCord23(pwmMixer, 0, pulseLFO2, 1);
AudioConnection          patchCord24(pwmMixer, 0, pulseLFO3, 1);
AudioConnection          patchCord25(pwmMixer, 0, pulseLFO4, 1);
AudioConnection          patchCord26(pwmMixer, 0, pulseLFO5, 1);
AudioConnection          patchCord27(pwmMixer, 0, pulseLFO6, 1);
AudioConnection          patchCord28(pwmMixer, 0, pulseLFO7, 1);
AudioConnection          patchCord29(pwmMixer, 0, sub0, 1);
AudioConnection          patchCord30(pwmMixer, 0, sub1, 1);
AudioConnection          patchCord31(pwmMixer, 0, sub2, 1);
AudioConnection          patchCord32(pwmMixer, 0, sub3, 1);
AudioConnection          patchCord33(pwmMixer, 0, sub4, 1);
AudioConnection          patchCord34(pwmMixer, 0, sub5, 1);
AudioConnection          patchCord35(pwmMixer, 0, sub6, 1);
AudioConnection          patchCord36(pwmMixer, 0, sub7, 1);
AudioConnection          patchCord37(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord38(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord39(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord40(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord41(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord42(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord43(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord44(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord45(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord46(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord47(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord48(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord49(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord50(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord51(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord52(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord53(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord54(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord55(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord56(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord57(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord58(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord59(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord60(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord61(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord62(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord63(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord64(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord65(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord66(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord67(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord68(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord69(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord70(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord71(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord72(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord73(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord74(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord75(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord76(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord77(hpf7, 2, lpf7, 0);
AudioConnection          patchCord78(hpf4, 2, lpf4, 0);
AudioConnection          patchCord79(hpf6, 2, lpf6, 0);
AudioConnection          patchCord80(hpf5, 2, lpf5, 0);
AudioConnection          patchCord81(hpf3, 2, lpf3, 0);
AudioConnection          patchCord82(hpf2, 2, lpf2, 0);
AudioConnection          patchCord83(hpf0, 2, lpf0, 0);
AudioConnection          patchCord84(hpf1, 2, lpf1, 0);
AudioConnection          patchCord85(vcfEnvDc, vcfEnv);
AudioConnection          patchCord86(vcfKeyboardDc, 0, vcfModMixer, 2);
AudioConnection          patchCord87(vcfModWheelDc, 0, vcfModMixer, 3);
AudioConnection          patchCord88(lpf7, 0, env7, 0);
AudioConnection          patchCord89(lpf4, 0, env4, 0);
AudioConnection          patchCord90(lpf6, 0, env6, 0);
AudioConnection          patchCord91(lpf5, 0, env5, 0);
AudioConnection          patchCord92(lpf3, 0, env3, 0);
AudioConnection          patchCord93(lpf2, 0, env2, 0);
AudioConnection          patchCord94(lpf0, 0, env0, 0);
AudioConnection          patchCord95(lpf1, 0, env1, 0);
AudioConnection          patchCord96(vcfEnv, 0, vcfModMixer, 1);
AudioConnection          patchCord97(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord98(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord99(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord100(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord101(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord102(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord103(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord104(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord105(EnvMixer0, peak);
AudioConnection          patchCord106(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord107(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord108(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord109(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord110(mixerL, flangerL);
AudioConnection          patchCord111(mixerR, flangerR);
AudioConnection          patchCord112(flangerL, 0, i2s1, 0);
AudioConnection          patchCord113(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1728.3333282470703,779
// GUItool: end automatically generated code
