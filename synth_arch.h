#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     pwmDc;          //xy=341.3333435058594,581.3333129882812
AudioSynthWaveform       lfo;            //xy=415.3333435058594,391.33331298828125
AudioAmplifier           oscLfoAmp;      //xy=437.3333435058594,1131.3333129882812
AudioMixer4              pwmMixer;       //xy=437.3333435058594,1227.3333129882812
AudioSynthWaveformModulated sub7;           //xy=638.3333435058594,1849.3333129882812
AudioSynthWaveformModulated sub4;           //xy=640.3333435058594,1351.3333129882812
AudioSynthWaveformModulated saw7;           //xy=639.3333435058594,1810.3333129882812
AudioSynthWaveformModulated saw4;           //xy=641.3333435058594,1312.3333129882812
AudioSynthWaveformModulated sub6;           //xy=640.3333435058594,1683.3333129882812
AudioSynthWaveformModulated saw6;           //xy=641.3333435058594,1644.3333129882812
AudioSynthWaveformModulated sub5;           //xy=644.3333435058594,1519.3333129882812
AudioSynthWaveformModulated sub3;           //xy=646.3333435058594,1186.3333129882812
AudioSynthWaveformModulated saw5;           //xy=645.3333435058594,1480.3333129882812
AudioSynthNoiseWhite     noise7;         //xy=644.3333435058594,1888.3333129882812
AudioSynthNoiseWhite     noise4;         //xy=646.3333435058594,1390.3333129882812
AudioSynthWaveformModulated saw3;           //xy=647.3333435058594,1147.3333129882812
AudioSynthNoiseWhite     noise6;         //xy=646.3333435058594,1722.3333129882812
AudioSynthWaveformModulated pulseLFO7;      //xy=648.3333435058594,1769.3333129882812
AudioSynthWaveformModulated sub2;           //xy=651.3333435058594,1020.3333129882812
AudioSynthWaveformModulated pulseLFO4;      //xy=650.3333435058594,1271.3333129882812
AudioSynthWaveformModulated saw2;           //xy=652.3333435058594,981.3333129882812
AudioSynthNoiseWhite     noise5;         //xy=650.3333435058594,1558.3333129882812
AudioSynthWaveformModulated pulseLFO6;      //xy=650.3333435058594,1603.3333129882812
AudioSynthWaveformModulated sub0;           //xy=654.3333435058594,676.3333129882812
AudioSynthNoiseWhite     noise3;         //xy=652.3333435058594,1225.3333129882812
AudioSynthWaveformModulated saw0;           //xy=655.3333435058594,637.3333129882812
AudioSynthWaveformModulated sub1;           //xy=655.3333435058594,849.3333129882812
AudioSynthWaveformModulated saw1;           //xy=656.3333435058594,810.3333129882812
AudioSynthWaveformModulated pulseLFO5;      //xy=654.3333435058594,1439.3333129882812
AudioSynthWaveformModulated pulseLFO3;      //xy=656.3333435058594,1106.3333129882812
AudioSynthNoiseWhite     noise2;         //xy=657.3333435058594,1059.3333129882812
AudioSynthNoiseWhite     noise0;         //xy=661.3333435058594,716.3333129882812
AudioSynthNoiseWhite     noise1;         //xy=661.3333435058594,888.3333129882812
AudioSynthWaveformModulated pulseLFO2;      //xy=661.3333435058594,940.3333129882812
AudioSynthWaveformModulated pulseLFO0;      //xy=664.3333435058594,596.3333129882812
AudioSynthWaveformModulated pulseLFO1;      //xy=665.3333435058594,769.3333129882812
AudioSynthWaveformDc     vcfEnvDc;       //xy=708.3333435058594,460.33331298828125
AudioSynthWaveformDc     vcfKeyboardDc;  //xy=783.3333435058594,509.33331298828125
AudioEffectEnvelope      vcfEnv;         //xy=846.3333435058594,463.33331298828125
AudioMixer4              oscMixer7;      //xy=849.3333435058594,1839.3333129882812
AudioMixer4              oscMixer4;      //xy=851.3333435058594,1341.3333129882812
AudioMixer4              oscMixer6;      //xy=851.3333435058594,1673.3333129882812
AudioMixer4              oscMixer5;      //xy=855.3333435058594,1509.3333129882812
AudioMixer4              oscMixer3;      //xy=857.3333435058594,1176.3333129882812
AudioMixer4              oscMixer2;      //xy=862.3333435058594,1010.3333129882812
AudioMixer4              oscMixer0;      //xy=866.3333435058594,667.3333129882812
AudioMixer4              oscMixer1;      //xy=866.3333435058594,839.3333129882812
AudioSynthWaveformDc     vcfModWheelDc;  //xy=877.3333435058594,548.3333129882812
AudioFilterStateVariable hpf7;           //xy=992.3333435058594,1850.3333129882812
AudioFilterStateVariable hpf4;           //xy=994.3333435058594,1352.3333129882812
AudioFilterStateVariable hpf6;           //xy=994.3333435058594,1684.3333129882812
AudioFilterStateVariable hpf5;           //xy=998.3333435058594,1520.3333129882812
AudioFilterStateVariable hpf3;           //xy=1000.3333435058594,1187.3333129882812
AudioFilterStateVariable hpf2;           //xy=1005.3333435058594,1021.3333129882812
AudioFilterStateVariable hpf0;           //xy=1009.3333435058594,678.3333129882812
AudioFilterStateVariable hpf1;           //xy=1009.3333435058594,850.3333129882812
AudioMixer4              vcfModMixer;    //xy=1100.3333435058594,478.33331298828125
AudioFilterStateVariable lpf7;           //xy=1125.3333435058594,1870.3333129882812
AudioFilterStateVariable lpf4;           //xy=1127.3333435058594,1372.3333129882812
AudioFilterStateVariable lpf6;           //xy=1127.3333435058594,1704.3333129882812
AudioFilterStateVariable lpf5;           //xy=1131.3333435058594,1540.3333129882812
AudioFilterStateVariable lpf3;           //xy=1133.3333435058594,1207.3333129882812
AudioFilterStateVariable lpf2;           //xy=1138.3333435058594,1041.3333129882812
AudioFilterStateVariable lpf0;           //xy=1142.3333435058594,698.3333129882812
AudioFilterStateVariable lpf1;           //xy=1142.3333435058594,870.3333129882812
AudioEffectEnvelope      env7;           //xy=1263.3333435058594,1870.3333129882812
AudioEffectEnvelope      env4;           //xy=1265.3333435058594,1372.3333129882812
AudioAmplifier           vcfPolarity;    //xy=1269.3333435058594,546.3333129882812
AudioEffectEnvelope      env6;           //xy=1265.3333435058594,1704.3333129882812
AudioEffectEnvelope      env5;           //xy=1269.3333435058594,1540.3333129882812
AudioEffectEnvelope      env3;           //xy=1271.3333435058594,1207.3333129882812
AudioEffectEnvelope      env2;           //xy=1276.3333435058594,1041.3333129882812
AudioEffectEnvelope      env0;           //xy=1280.3333435058594,698.3333129882812
AudioEffectEnvelope      env1;           //xy=1280.3333435058594,870.3333129882812
AudioMixer4              EnvMixer0;      //xy=1521.3333435058594,972.3333129882812
AudioMixer4              EnvMixer1;      //xy=1544.3333435058594,1650.3333129882812
AudioMixer4              mixerL;         //xy=1774.3333435058594,1256.3333129882812
AudioMixer4              mixerR;         //xy=1781.3333435058594,1492.3333129882812
AudioEffectFlange        flangerL;       //xy=1954.3333435058594,1344.3333129882812
AudioEffectFlange        flangerR;       //xy=1959.3333435058594,1469.3333129882812
AudioAnalyzePeak         peak;           //xy=1978.3333435058594,820.3333129882812
AudioOutputI2S           i2s1;           //xy=2150.3333435058594,1396.3333129882812
AudioConnection          patchCord1(pwmDc, 0, pwmMixer, 1);
AudioConnection          patchCord2(lfo, 0, vcfModMixer, 0);
AudioConnection          patchCord3(lfo, oscLfoAmp);
AudioConnection          patchCord4(lfo, 0, pwmMixer, 0);
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
AudioConnection          patchCord77(vcfEnvDc, vcfEnv);
AudioConnection          patchCord78(vcfKeyboardDc, 0, vcfModMixer, 2);
AudioConnection          patchCord79(vcfEnv, 0, vcfModMixer, 1);
AudioConnection          patchCord80(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord81(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord82(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord83(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord84(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord85(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord86(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord87(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord88(vcfModWheelDc, 0, vcfModMixer, 3);
AudioConnection          patchCord89(hpf7, 2, lpf7, 0);
AudioConnection          patchCord90(hpf4, 2, lpf4, 0);
AudioConnection          patchCord91(hpf6, 2, lpf6, 0);
AudioConnection          patchCord92(hpf5, 2, lpf5, 0);
AudioConnection          patchCord93(hpf3, 2, lpf3, 0);
AudioConnection          patchCord94(hpf2, 2, lpf2, 0);
AudioConnection          patchCord95(hpf0, 2, lpf0, 0);
AudioConnection          patchCord96(hpf1, 2, lpf1, 0);
AudioConnection          patchCord97(lpf7, 0, env7, 0);
AudioConnection          patchCord98(lpf4, 0, env4, 0);
AudioConnection          patchCord99(lpf6, 0, env6, 0);
AudioConnection          patchCord100(lpf5, 0, env5, 0);
AudioConnection          patchCord101(lpf3, 0, env3, 0);
AudioConnection          patchCord102(lpf2, 0, env2, 0);
AudioConnection          patchCord103(lpf0, 0, env0, 0);
AudioConnection          patchCord104(lpf1, 0, env1, 0);
AudioConnection          patchCord105(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord106(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord107(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord108(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord109(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord110(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord111(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord112(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord113(EnvMixer0, peak);
AudioConnection          patchCord114(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord115(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord116(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord117(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord118(mixerL, flangerL);
AudioConnection          patchCord119(mixerR, flangerR);
AudioConnection          patchCord120(flangerL, 0, i2s1, 0);
AudioConnection          patchCord121(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1931.3333435058594,1150.3333129882812
// GUItool: end automatically generated code
