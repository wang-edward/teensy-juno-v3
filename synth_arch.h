#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     pwmDc;          //xy=480.33331298828125,513.0000076293945
AudioSynthWaveform       lfo;            //xy=554.3333129882812,323.00000762939453
AudioAmplifier           oscLfoAmp;      //xy=576.3333129882812,1063.0000076293945
AudioMixer4              pwmMixer;       //xy=576.3333129882812,1159.0000076293945
AudioSynthWaveformModulated sub7;           //xy=777.3333129882812,1781.0000076293945
AudioSynthWaveformModulated sub4;           //xy=779.3333129882812,1283.0000076293945
AudioSynthWaveformModulated saw7;           //xy=778.3333129882812,1742.0000076293945
AudioSynthWaveformModulated saw4;           //xy=780.3333129882812,1244.0000076293945
AudioSynthWaveformModulated sub6;           //xy=779.3333129882812,1615.0000076293945
AudioSynthWaveformModulated saw6;           //xy=780.3333129882812,1576.0000076293945
AudioSynthWaveformModulated sub5;           //xy=783.3333129882812,1451.0000076293945
AudioSynthWaveformModulated sub3;           //xy=785.3333129882812,1118.0000076293945
AudioSynthWaveformModulated saw5;           //xy=784.3333129882812,1412.0000076293945
AudioSynthNoiseWhite     noise7;         //xy=783.3333129882812,1820.0000076293945
AudioSynthNoiseWhite     noise4;         //xy=785.3333129882812,1322.0000076293945
AudioSynthWaveformModulated saw3;           //xy=786.3333129882812,1079.0000076293945
AudioSynthNoiseWhite     noise6;         //xy=785.3333129882812,1654.0000076293945
AudioSynthWaveformModulated pulseLFO7;      //xy=787.3333129882812,1701.0000076293945
AudioSynthWaveformModulated sub2;           //xy=790.3333129882812,952.0000076293945
AudioSynthWaveformModulated pulseLFO4;      //xy=789.3333129882812,1203.0000076293945
AudioSynthWaveformModulated saw2;           //xy=791.3333129882812,913.0000076293945
AudioSynthNoiseWhite     noise5;         //xy=789.3333129882812,1490.0000076293945
AudioSynthWaveformModulated pulseLFO6;      //xy=789.3333129882812,1535.0000076293945
AudioSynthWaveformModulated sub0;           //xy=793.3333129882812,608.0000076293945
AudioSynthNoiseWhite     noise3;         //xy=791.3333129882812,1157.0000076293945
AudioSynthWaveformModulated saw0;           //xy=794.3333129882812,569.0000076293945
AudioSynthWaveformModulated sub1;           //xy=794.3333129882812,781.0000076293945
AudioSynthWaveformModulated saw1;           //xy=795.3333129882812,742.0000076293945
AudioSynthWaveformModulated pulseLFO5;      //xy=793.3333129882812,1371.0000076293945
AudioSynthWaveformModulated pulseLFO3;      //xy=795.3333129882812,1038.0000076293945
AudioSynthNoiseWhite     noise2;         //xy=796.3333129882812,991.0000076293945
AudioSynthNoiseWhite     noise0;         //xy=800.3333129882812,648.0000076293945
AudioSynthNoiseWhite     noise1;         //xy=800.3333129882812,820.0000076293945
AudioSynthWaveformModulated pulseLFO2;      //xy=800.3333129882812,872.0000076293945
AudioSynthWaveformModulated pulseLFO0;      //xy=803.3333129882812,528.0000076293945
AudioSynthWaveformModulated pulseLFO1;      //xy=804.3333129882812,701.0000076293945
AudioSynthWaveformDc     lpfEnvDc;       //xy=899.333251953125,318
AudioSynthWaveformDc     lpfKeyboardDc;  //xy=938.333251953125,471
AudioSynthWaveformDc     lpfModWheelDc;  //xy=947.333251953125,520
AudioMixer4              oscMixer7;      //xy=988.3333129882812,1771.0000076293945
AudioMixer4              oscMixer4;      //xy=990.3333129882812,1273.0000076293945
AudioMixer4              oscMixer6;      //xy=990.3333129882812,1605.0000076293945
AudioMixer4              oscMixer5;      //xy=994.3333129882812,1441.0000076293945
AudioMixer4              oscMixer3;      //xy=996.3333129882812,1108.0000076293945
AudioMixer4              oscMixer2;      //xy=1001.3333129882812,942.0000076293945
AudioMixer4              oscMixer0;      //xy=1005.3333129882812,599.0000076293945
AudioMixer4              oscMixer1;      //xy=1005.3333129882812,771.0000076293945
AudioEffectEnvelope      lfoEnv0; //xy=1078.2833251953125,443.2833251953125
AudioEffectEnvelope      lpfEnv1;  //xy=1082.2833251953125,680.2833251953125
AudioEffectEnvelope      lpfEnv2; //xy=1085.2833251953125,841.2833251953125
AudioEffectEnvelope      lpfEnv5; //xy=1084.2833251953125,1348.2833251953125
AudioEffectEnvelope      lfoEnv2; //xy=1087.2833251953125,876.2833251953125
AudioEffectEnvelope      lpfEnv3; //xy=1087.2833251953125,1021.2833251953125
AudioEffectEnvelope      lpfEnv4; //xy=1088.2833251953125,1178.2833251953125
AudioEffectEnvelope      lfoEnv4;  //xy=1089.2833251953125,1212.2833251953125
AudioEffectEnvelope      lfoEnv3; //xy=1091.2833251953125,1056.2833251953125
AudioEffectEnvelope      lfoEnv5; //xy=1090.2833251953125,1386.2833251953125
AudioEffectEnvelope      lpfEnv6; //xy=1091.2833251953125,1516.2833251953125
AudioEffectEnvelope      lfoEnv1; //xy=1095.2833251953125,720.2833251953125
AudioEffectEnvelope      lfoEnv7; //xy=1093.2833251953125,1721.2833251953125
AudioEffectEnvelope      lfoEnv6;  //xy=1094.2833251953125,1555.2833251953125
AudioEffectEnvelope      lpfEnv7; //xy=1094.2833251953125,1685.2833251953125
AudioEffectEnvelope      lpfEnv0;         //xy=1128.333251953125,387
AudioFilterStateVariable hpf7;           //xy=1131.3333129882812,1782.0000076293945
AudioFilterStateVariable hpf4;           //xy=1133.3333129882812,1284.0000076293945
AudioFilterStateVariable hpf6;           //xy=1133.3333129882812,1616.0000076293945
AudioFilterStateVariable hpf5;           //xy=1137.3333129882812,1452.0000076293945
AudioFilterStateVariable hpf3;           //xy=1139.3333129882812,1119.0000076293945
AudioFilterStateVariable hpf2;           //xy=1144.3333129882812,953.0000076293945
AudioFilterStateVariable hpf0;           //xy=1148.3333129882812,610.0000076293945
AudioFilterStateVariable hpf1;           //xy=1148.3333129882812,782.0000076293945
AudioMixer4              lpfModMixer0;    //xy=1239.333251953125,539
AudioMixer4              lpfModMixer1; //xy=1266.2833251953125,721.2833251953125
AudioFilterStateVariable lpf7;           //xy=1264.3333129882812,1802.0000076293945
AudioFilterStateVariable lpf4;           //xy=1266.3333129882812,1304.0000076293945
AudioMixer4              lpfModMixer2; //xy=1269.2833251953125,882.2833251953125
AudioFilterStateVariable lpf6;           //xy=1266.3333129882812,1636.0000076293945
AudioMixer4              lpfModMixer5; //xy=1268.2833251953125,1389.2833251953125
AudioMixer4              lpfModMixer3; //xy=1271.2833251953125,1062.2833251953125
AudioFilterStateVariable lpf5;           //xy=1270.3333129882812,1472.0000076293945
AudioFilterStateVariable lpf3;           //xy=1272.3333129882812,1139.0000076293945
AudioMixer4              lpfModMixer4; //xy=1272.2833251953125,1219.2833251953125
AudioFilterStateVariable lpf2;           //xy=1277.3333129882812,973.0000076293945
AudioMixer4              lpfModMixer6; //xy=1275.2833251953125,1557.2833251953125
AudioFilterStateVariable lpf0;           //xy=1281.3333129882812,630.0000076293945
AudioFilterStateVariable lpf1;           //xy=1281.3333129882812,802.0000076293945
AudioMixer4              lpfModMixer7; //xy=1278.2833251953125,1726.2833251953125
AudioEffectEnvelope      env7;           //xy=1402.3333129882812,1802.0000076293945
AudioEffectEnvelope      env4;           //xy=1404.3333129882812,1304.0000076293945
AudioEffectEnvelope      env6;           //xy=1404.3333129882812,1636.0000076293945
AudioEffectEnvelope      env5;           //xy=1408.3333129882812,1472.0000076293945
AudioAmplifier           lpfPolarity;    //xy=1412.333251953125,477
AudioEffectEnvelope      env3;           //xy=1410.3333129882812,1139.0000076293945
AudioEffectEnvelope      env2;           //xy=1415.3333129882812,973.0000076293945
AudioEffectEnvelope      env0;           //xy=1419.3333129882812,630.0000076293945
AudioEffectEnvelope      env1;           //xy=1419.3333129882812,802.0000076293945
AudioMixer4              EnvMixer0;      //xy=1660.3333129882812,904.0000076293945
AudioMixer4              EnvMixer1;      //xy=1683.3333129882812,1582.0000076293945
AudioMixer4              mixerL;         //xy=1913.3333129882812,1188.0000076293945
AudioMixer4              mixerR;         //xy=1920.3333129882812,1424.0000076293945
AudioEffectFlange        flangerL;       //xy=2093.3333129882812,1276.0000076293945
AudioEffectFlange        flangerR;       //xy=2098.3333129882812,1401.0000076293945
AudioAnalyzePeak         peak;           //xy=2117.3333129882812,752.0000076293945
AudioOutputI2S           i2s1;           //xy=2289.3333129882812,1328.0000076293945
AudioConnection          patchCord1(pwmDc, 0, pwmMixer, 1);
AudioConnection          patchCord2(lfo, oscLfoAmp);
AudioConnection          patchCord3(lfo, 0, pwmMixer, 0);
AudioConnection          patchCord4(lfo, lfoEnv0);
AudioConnection          patchCord5(lfo, lfoEnv2);
AudioConnection          patchCord6(lfo, lfoEnv1);
AudioConnection          patchCord7(lfo, lfoEnv3);
AudioConnection          patchCord8(lfo, lfoEnv4);
AudioConnection          patchCord9(lfo, lfoEnv5);
AudioConnection          patchCord10(lfo, lfoEnv6);
AudioConnection          patchCord11(lfo, lfoEnv7);
AudioConnection          patchCord12(oscLfoAmp, 0, pulseLFO0, 0);
AudioConnection          patchCord13(oscLfoAmp, 0, sub0, 0);
AudioConnection          patchCord14(oscLfoAmp, 0, pulseLFO1, 0);
AudioConnection          patchCord15(oscLfoAmp, 0, sub1, 0);
AudioConnection          patchCord16(oscLfoAmp, 0, pulseLFO2, 0);
AudioConnection          patchCord17(oscLfoAmp, 0, sub2, 0);
AudioConnection          patchCord18(oscLfoAmp, 0, pulseLFO3, 0);
AudioConnection          patchCord19(oscLfoAmp, 0, sub3, 0);
AudioConnection          patchCord20(oscLfoAmp, 0, pulseLFO4, 0);
AudioConnection          patchCord21(oscLfoAmp, 0, sub4, 0);
AudioConnection          patchCord22(oscLfoAmp, 0, pulseLFO5, 0);
AudioConnection          patchCord23(oscLfoAmp, 0, sub5, 0);
AudioConnection          patchCord24(oscLfoAmp, 0, pulseLFO6, 0);
AudioConnection          patchCord25(oscLfoAmp, 0, sub6, 0);
AudioConnection          patchCord26(oscLfoAmp, 0, pulseLFO7, 0);
AudioConnection          patchCord27(oscLfoAmp, 0, sub7, 0);
AudioConnection          patchCord28(oscLfoAmp, 0, saw0, 0);
AudioConnection          patchCord29(oscLfoAmp, 0, saw1, 0);
AudioConnection          patchCord30(oscLfoAmp, 0, saw2, 0);
AudioConnection          patchCord31(oscLfoAmp, 0, saw3, 0);
AudioConnection          patchCord32(oscLfoAmp, 0, saw4, 0);
AudioConnection          patchCord33(oscLfoAmp, 0, saw5, 0);
AudioConnection          patchCord34(oscLfoAmp, 0, saw6, 0);
AudioConnection          patchCord35(oscLfoAmp, 0, saw7, 0);
AudioConnection          patchCord36(pwmMixer, 0, pulseLFO0, 1);
AudioConnection          patchCord37(pwmMixer, 0, pulseLFO1, 1);
AudioConnection          patchCord38(pwmMixer, 0, pulseLFO2, 1);
AudioConnection          patchCord39(pwmMixer, 0, pulseLFO3, 1);
AudioConnection          patchCord40(pwmMixer, 0, pulseLFO4, 1);
AudioConnection          patchCord41(pwmMixer, 0, pulseLFO5, 1);
AudioConnection          patchCord42(pwmMixer, 0, pulseLFO6, 1);
AudioConnection          patchCord43(pwmMixer, 0, pulseLFO7, 1);
AudioConnection          patchCord44(pwmMixer, 0, sub0, 1);
AudioConnection          patchCord45(pwmMixer, 0, sub1, 1);
AudioConnection          patchCord46(pwmMixer, 0, sub2, 1);
AudioConnection          patchCord47(pwmMixer, 0, sub3, 1);
AudioConnection          patchCord48(pwmMixer, 0, sub4, 1);
AudioConnection          patchCord49(pwmMixer, 0, sub5, 1);
AudioConnection          patchCord50(pwmMixer, 0, sub6, 1);
AudioConnection          patchCord51(pwmMixer, 0, sub7, 1);
AudioConnection          patchCord52(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord53(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord54(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord55(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord56(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord57(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord58(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord59(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord60(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord61(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord62(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord63(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord64(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord65(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord66(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord67(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord68(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord69(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord70(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord71(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord72(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord73(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord74(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord75(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord76(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord77(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord78(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord79(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord80(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord81(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord82(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord83(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord84(lpfEnvDc, lpfEnv0);
AudioConnection          patchCord85(lpfEnvDc, lpfEnv1);
AudioConnection          patchCord86(lpfEnvDc, lpfEnv2);
AudioConnection          patchCord87(lpfEnvDc, lpfEnv3);
AudioConnection          patchCord88(lpfEnvDc, lpfEnv4);
AudioConnection          patchCord89(lpfEnvDc, lpfEnv5);
AudioConnection          patchCord90(lpfEnvDc, lpfEnv6);
AudioConnection          patchCord91(lpfEnvDc, lpfEnv7);
AudioConnection          patchCord92(lpfKeyboardDc, 0, lpfModMixer0, 2);
AudioConnection          patchCord93(lpfKeyboardDc, 0, lpfModMixer1, 2);
AudioConnection          patchCord94(lpfKeyboardDc, 0, lpfModMixer2, 2);
AudioConnection          patchCord95(lpfKeyboardDc, 0, lpfModMixer3, 2);
AudioConnection          patchCord96(lpfKeyboardDc, 0, lpfModMixer4, 2);
AudioConnection          patchCord97(lpfKeyboardDc, 0, lpfModMixer5, 2);
AudioConnection          patchCord98(lpfKeyboardDc, 0, lpfModMixer6, 2);
AudioConnection          patchCord99(lpfKeyboardDc, 0, lpfModMixer7, 2);
AudioConnection          patchCord100(lpfModWheelDc, 0, lpfModMixer0, 3);
AudioConnection          patchCord101(lpfModWheelDc, 0, lpfModMixer1, 3);
AudioConnection          patchCord102(lpfModWheelDc, 0, lpfModMixer2, 3);
AudioConnection          patchCord103(lpfModWheelDc, 0, lpfModMixer3, 3);
AudioConnection          patchCord104(lpfModWheelDc, 0, lpfModMixer4, 3);
AudioConnection          patchCord105(lpfModWheelDc, 0, lpfModMixer5, 3);
AudioConnection          patchCord106(lpfModWheelDc, 0, lpfModMixer6, 3);
AudioConnection          patchCord107(lpfModWheelDc, 0, lpfModMixer7, 3);
AudioConnection          patchCord108(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord109(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord110(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord111(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord112(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord113(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord114(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord115(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord116(lfoEnv0, 0, lpfModMixer0, 1);
AudioConnection          patchCord117(lpfEnv1, 0, lpfModMixer1, 0);
AudioConnection          patchCord118(lpfEnv2, 0, lpfModMixer2, 0);
AudioConnection          patchCord119(lpfEnv5, 0, lpfModMixer5, 0);
AudioConnection          patchCord120(lfoEnv2, 0, lpfModMixer2, 1);
AudioConnection          patchCord121(lpfEnv3, 0, lpfModMixer3, 0);
AudioConnection          patchCord122(lpfEnv4, 0, lpfModMixer4, 0);
AudioConnection          patchCord123(lfoEnv4, 0, lpfModMixer4, 1);
AudioConnection          patchCord124(lfoEnv3, 0, lpfModMixer3, 1);
AudioConnection          patchCord125(lfoEnv5, 0, lpfModMixer5, 1);
AudioConnection          patchCord126(lpfEnv6, 0, lpfModMixer6, 0);
AudioConnection          patchCord127(lfoEnv1, 0, lpfModMixer1, 1);
AudioConnection          patchCord128(lfoEnv7, 0, lpfModMixer7, 1);
AudioConnection          patchCord129(lfoEnv6, 0, lpfModMixer6, 1);
AudioConnection          patchCord130(lpfEnv7, 0, lpfModMixer7, 0);
AudioConnection          patchCord131(lpfEnv0, 0, lpfModMixer0, 0);
AudioConnection          patchCord132(hpf7, 2, lpf7, 0);
AudioConnection          patchCord133(hpf4, 2, lpf4, 0);
AudioConnection          patchCord134(hpf6, 2, lpf6, 0);
AudioConnection          patchCord135(hpf5, 2, lpf5, 0);
AudioConnection          patchCord136(hpf3, 2, lpf3, 0);
AudioConnection          patchCord137(hpf2, 2, lpf2, 0);
AudioConnection          patchCord138(hpf0, 2, lpf0, 0);
AudioConnection          patchCord139(hpf1, 2, lpf1, 0);
AudioConnection          patchCord140(lpfModMixer0, 0, lpf0, 1);
AudioConnection          patchCord141(lpfModMixer1, 0, lpf1, 1);
AudioConnection          patchCord142(lpf7, 0, env7, 0);
AudioConnection          patchCord143(lpf4, 0, env4, 0);
AudioConnection          patchCord144(lpfModMixer2, 0, lpf2, 1);
AudioConnection          patchCord145(lpf6, 0, env6, 0);
AudioConnection          patchCord146(lpfModMixer5, 0, lpf5, 1);
AudioConnection          patchCord147(lpfModMixer3, 0, lpf3, 1);
AudioConnection          patchCord148(lpf5, 0, env5, 0);
AudioConnection          patchCord149(lpf3, 0, env3, 0);
AudioConnection          patchCord150(lpfModMixer4, 0, lpf4, 1);
AudioConnection          patchCord151(lpf2, 0, env2, 0);
AudioConnection          patchCord152(lpfModMixer6, 0, lpf6, 1);
AudioConnection          patchCord153(lpf0, 0, env0, 0);
AudioConnection          patchCord154(lpf1, 0, env1, 0);
AudioConnection          patchCord155(lpfModMixer7, 0, lpf7, 1);
AudioConnection          patchCord156(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord157(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord158(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord159(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord160(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord161(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord162(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord163(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord164(EnvMixer0, peak);
AudioConnection          patchCord165(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord166(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord167(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord168(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord169(mixerL, flangerL);
AudioConnection          patchCord170(mixerR, flangerR);
AudioConnection          patchCord171(flangerL, 0, i2s1, 0);
AudioConnection          patchCord172(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2070.3333129882812,1082.0000076293945
// GUItool: end automatically generated code
