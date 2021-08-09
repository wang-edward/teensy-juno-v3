#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       lfo;      //xy=313.1000061035156,88.10000610351562
AudioSynthNoiseWhite     noise1;         //xy=362,607.0000076293945
AudioSynthNoiseWhite     noise4;         //xy=360,1135.0000076293945
AudioSynthNoiseWhite     noise0;         //xy=363,424.00000762939453
AudioSynthNoiseWhite     noise2;         //xy=363,789.0000076293945
AudioSynthNoiseWhite     noise5;         //xy=361,1306.0000076293945
AudioSynthWaveform       sub1;           //xy=365,564.0000076293945
AudioSynthWaveform       sub4;           //xy=363,1092.0000076293945
AudioSynthWaveform       sub0;           //xy=366,380.00000762939453
AudioSynthNoiseWhite     noise3;         //xy=364,962.0000076293945
AudioSynthNoiseWhite     noise6;         //xy=362,1481.0000076293945
AudioSynthWaveform       sub2;           //xy=366,745.0000076293945
AudioSynthWaveform       sub5;           //xy=364,1263.0000076293945
AudioSynthWaveform       pulseLFO1;      //xy=368,481.00000762939453
AudioSynthWaveform       pulseLFO4;      //xy=366,1009.0000076293945
AudioSynthWaveform       pulseLFO0;      //xy=369,297.00000762939453
AudioSynthNoiseWhite     noise7;         //xy=364,1653.0000076293945
AudioSynthWaveform       sub6;           //xy=365,1438.0000076293945
AudioSynthWaveform       pulseLFO2;      //xy=369,662.0000076293945
AudioSynthWaveform       sub3;           //xy=368,919.0000076293945
AudioSynthWaveform       pulseLFO5;      //xy=367,1180.0000076293945
AudioSynthWaveform       saw4;           //xy=368,1044.0000076293945
AudioSynthWaveform       saw0;           //xy=371,333.00000762939453
AudioSynthWaveform       saw1;           //xy=371,517.0000076293945
AudioSynthWaveform       pulseLFO3;      //xy=370,835.0000076293945
AudioSynthWaveform       pulseLFO6;      //xy=368,1354.0000076293945
AudioSynthWaveform       saw5;           //xy=369,1216.0000076293945
AudioSynthWaveform       sub7;           //xy=368,1610.0000076293945
AudioSynthWaveform       saw2;           //xy=372,698.0000076293945
AudioSynthWaveform       pulseLFO7;      //xy=370,1526.0000076293945
AudioSynthWaveform       saw3;           //xy=373,871.0000076293945
AudioSynthWaveform       saw6;           //xy=371,1390.0000076293945
AudioSynthWaveform       saw7;           //xy=373,1562.0000076293945
AudioAmplifier           dcoPitchAmp;           //xy=431,169
AudioAmplifier           dcoPwmAmp; //xy=471,49
AudioSynthWaveformModulated testWaveform;   //xy=525.1000061035156,248.10000610351562
AudioMixer4              oscMixer4;      //xy=565,1087.0000076293945
AudioMixer4              oscMixer0;      //xy=568,375.00000762939453
AudioMixer4              oscMixer1;      //xy=568,559.0000076293945
AudioMixer4              oscMixer5;      //xy=566,1258.0000076293945
AudioMixer4              oscMixer2;      //xy=569,740.0000076293945
AudioMixer4              oscMixer3;      //xy=570,914.0000076293945
AudioMixer4              oscMixer6;      //xy=568,1433.0000076293945
AudioMixer4              oscMixer7;      //xy=570,1605.0000076293945
AudioAnalyzePeak         pwmPeak;          //xy=652,65
AudioFilterStateVariable hpf1;           //xy=710,570.0000076293945
AudioFilterStateVariable hpf4;           //xy=708,1098.0000076293945
AudioFilterStateVariable hpf0;           //xy=711,386.00000762939453
AudioFilterStateVariable hpf2;           //xy=711,751.0000076293945
AudioFilterStateVariable hpf5;           //xy=709,1269.0000076293945
AudioFilterStateVariable hpf6;           //xy=710,1443.0000076293945
AudioFilterStateVariable hpf3;           //xy=713,925.0000076293945
AudioFilterStateVariable hpf7;           //xy=713,1616.0000076293945
AudioSynthWaveformDc     vcfEnvDc;            //xy=735,169
AudioSynthWaveformDc     vcfKeyboardDc;            //xy=755,203
AudioSynthWaveformDc     vcfModWheelDc;            //xy=757,238
AudioFilterStateVariable lpf1;           //xy=843,590.0000076293945
AudioFilterStateVariable lpf4;           //xy=841,1117.0000076293945
AudioFilterStateVariable lpf0;           //xy=844,406.00000762939453
AudioFilterStateVariable lpf2;           //xy=844,771.0000076293945
AudioFilterStateVariable lpf5;           //xy=842,1288.0000076293945
AudioFilterStateVariable lpf3;           //xy=845,944.0000076293945
AudioFilterStateVariable lpf6;           //xy=843,1463.0000076293945
AudioFilterStateVariable lpf7;           //xy=845,1635.0000076293945
AudioEffectEnvelope      vcfEnv;      //xy=868,169
AudioEffectEnvelope      env1;           //xy=981,590.0000076293945
AudioEffectEnvelope      env4;           //xy=979,1118.0000076293945
AudioEffectEnvelope      env0;           //xy=982,406.00000762939453
AudioEffectEnvelope      env2;           //xy=982,771.0000076293945
AudioEffectEnvelope      env5;           //xy=980,1289.0000076293945
AudioEffectEnvelope      env3;           //xy=982,936.0000076293945
AudioEffectEnvelope      env6;           //xy=981,1464.0000076293945
AudioEffectEnvelope      env7;           //xy=983,1636.0000076293945
AudioMixer4              vcfModMixer;         //xy=1071,192.99999237060547
AudioMixer4              EnvMixer0;      //xy=1223,680.0000076293945
AudioMixer4              EnvMixer1;      //xy=1246,1358.0000076293945
AudioMixer4              mixerL;         //xy=1476,964.0000076293945
AudioMixer4              mixerR;         //xy=1483,1200.0000076293945
AudioEffectFlange        flangerL;       //xy=1656,1052.0000076293945
AudioEffectFlange        flangerR;       //xy=1661,1177.0000076293945
AudioAnalyzePeak         peak;           //xy=1680,528.0000076293945
AudioOutputI2S           i2s1;           //xy=1852,1104.0000076293945
AudioConnection          patchCord1(lfo, 0, vcfModMixer, 0);
AudioConnection          patchCord2(lfo, dcoPitchAmp);
AudioConnection          patchCord3(lfo, dcoPwmAmp);
AudioConnection          patchCord4(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord5(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord6(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord7(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord8(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord9(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord10(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord11(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord12(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord13(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord14(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord15(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord16(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord17(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord18(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord19(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord20(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord21(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord22(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord23(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord24(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord25(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord26(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord27(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord28(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord29(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord30(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord31(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord32(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord33(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord34(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord35(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord36(dcoPitchAmp, 0, testWaveform, 0);
AudioConnection          patchCord37(dcoPwmAmp, pwmPeak);
AudioConnection          patchCord38(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord39(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord40(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord41(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord42(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord43(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord44(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord45(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord46(hpf1, 2, lpf1, 0);
AudioConnection          patchCord47(hpf4, 2, lpf4, 0);
AudioConnection          patchCord48(hpf0, 2, lpf0, 0);
AudioConnection          patchCord49(hpf2, 2, lpf2, 0);
AudioConnection          patchCord50(hpf5, 2, lpf5, 0);
AudioConnection          patchCord51(hpf6, 2, lpf6, 0);
AudioConnection          patchCord52(hpf3, 2, lpf3, 0);
AudioConnection          patchCord53(hpf7, 2, lpf7, 0);
AudioConnection          patchCord54(vcfEnvDc, vcfEnv);
AudioConnection          patchCord55(vcfKeyboardDc, 0, vcfModMixer, 2);
AudioConnection          patchCord56(vcfModWheelDc, 0, vcfModMixer, 3);
AudioConnection          patchCord57(lpf1, 0, env1, 0);
AudioConnection          patchCord58(lpf4, 0, env4, 0);
AudioConnection          patchCord59(lpf0, 0, env0, 0);
AudioConnection          patchCord60(lpf2, 0, env2, 0);
AudioConnection          patchCord61(lpf5, 0, env5, 0);
AudioConnection          patchCord62(lpf3, 0, env3, 0);
AudioConnection          patchCord63(lpf6, 0, env6, 0);
AudioConnection          patchCord64(lpf7, 0, env7, 0);
AudioConnection          patchCord65(vcfEnv, 0, vcfModMixer, 1);
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
AudioControlSGTL5000     sgtl5000_1;     //xy=1633,858.0000076293945
// GUItool: end automatically generated code
