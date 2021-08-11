#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     pwmDc;            //xy=80.36666870117188,424.3666687011719
AudioSynthWaveform       lfo;            //xy=154.33331298828125,234
AudioMixer4              pwmMixer;         //xy=176.36668395996094,1070.3666687011719
AudioSynthWaveformModulated sub7; //xy=377.6666564941406,1692.999984741211
AudioSynthWaveformModulated sub4; //xy=379.6666564941406,1194.999984741211
AudioSynthWaveformModulated saw7; //xy=378.6666564941406,1653.999984741211
AudioSynthWaveformModulated saw4; //xy=380.6666564941406,1155.999984741211
AudioSynthWaveformModulated sub6; //xy=379.6666564941406,1526.999984741211
AudioSynthWaveformModulated saw6; //xy=380.6666564941406,1487.999984741211
AudioSynthWaveformModulated sub5; //xy=383.6666564941406,1362.999984741211
AudioSynthWaveformModulated sub3; //xy=385.6666564941406,1029.999984741211
AudioSynthWaveformModulated saw5; //xy=384.6666564941406,1323.999984741211
AudioSynthWaveformModulated saw3; //xy=386.6666564941406,990.9999847412109
AudioSynthNoiseWhite     noise7; //xy=383.99998474121094,1731.9999923706055
AudioSynthNoiseWhite     noise4; //xy=385.99998474121094,1233.9999923706055
AudioSynthNoiseWhite     noise6; //xy=385.99998474121094,1565.9999923706055
AudioSynthWaveformModulated pulseLFO7; //xy=387.6666564941406,1612.999984741211
AudioSynthWaveformModulated sub2; //xy=390.6666564941406,863.9999847412109
AudioSynthWaveformModulated pulseLFO4; //xy=389.6666564941406,1114.999984741211
AudioSynthWaveformModulated saw2; //xy=391.6666564941406,824.9999847412109
AudioSynthWaveformModulated pulseLFO6; //xy=389.6666564941406,1446.999984741211
AudioSynthNoiseWhite     noise5; //xy=389.99998474121094,1401.9999923706055
AudioSynthWaveformModulated sub0;   //xy=393.99998474121094,519.9999923706055
AudioSynthNoiseWhite     noise3; //xy=391.99998474121094,1068.9999923706055
AudioSynthWaveformModulated saw0;   //xy=394.99998474121094,480.99999237060547
AudioSynthWaveformModulated sub1; //xy=394.6666564941406,692.9999847412109
AudioSynthWaveformModulated saw1; //xy=395.6666564941406,653.9999847412109
AudioSynthWaveformModulated pulseLFO5; //xy=393.6666564941406,1282.999984741211
AudioSynthWaveformModulated pulseLFO3; //xy=395.6666564941406,949.9999847412109
AudioSynthNoiseWhite     noise2; //xy=396.99998474121094,902.9999923706055
AudioSynthNoiseWhite     noise0;         //xy=400.33331298828125,559
AudioSynthWaveformModulated pulseLFO2; //xy=400.6666564941406,783.9999847412109
AudioSynthNoiseWhite     noise1; //xy=400.99998474121094,731.9999923706055
AudioSynthWaveformModulated pulseLFO0;   //xy=403.99998474121094,439.99999237060547
AudioSynthWaveformModulated pulseLFO1; //xy=404.6666564941406,612.9999847412109
AudioAmplifier           dcoPitchAmp;    //xy=468.33331298828125,304
AudioSynthWaveformModulated testWaveform;   //xy=562.3333129882812,383
AudioMixer4              oscMixer7; //xy=588.9999847412109,1682.9999923706055
AudioMixer4              oscMixer4; //xy=590.9999847412109,1184.9999923706055
AudioMixer4              oscMixer6; //xy=590.9999847412109,1516.9999923706055
AudioMixer4              oscMixer5; //xy=594.9999847412109,1352.9999923706055
AudioMixer4              oscMixer3; //xy=596.9999847412109,1019.9999923706055
AudioMixer4              oscMixer2; //xy=601.9999847412109,853.9999923706055
AudioMixer4              oscMixer0;      //xy=605.3333129882812,510
AudioMixer4              oscMixer1; //xy=605.9999847412109,682.9999923706055
AudioFilterStateVariable hpf7; //xy=731.9999847412109,1693.9999923706055
AudioFilterStateVariable hpf4; //xy=733.9999847412109,1195.9999923706055
AudioFilterStateVariable hpf6; //xy=733.9999847412109,1527.9999923706055
AudioFilterStateVariable hpf5; //xy=737.9999847412109,1363.9999923706055
AudioFilterStateVariable hpf3; //xy=739.9999847412109,1030.9999923706055
AudioFilterStateVariable hpf2;  //xy=744.9999847412109,864.9999923706055
AudioFilterStateVariable hpf0;           //xy=748.3333129882812,521
AudioFilterStateVariable hpf1; //xy=748.9999847412109,693.9999923706055
AudioSynthWaveformDc     vcfEnvDc;       //xy=772.3333129882812,304
AudioSynthWaveformDc     vcfKeyboardDc;  //xy=792.3333129882812,338
AudioSynthWaveformDc     vcfModWheelDc;  //xy=794.3333129882812,373
AudioSynthWaveform       waveform1;      //xy=831.3666534423828,437.36666107177734
AudioFilterStateVariable lpf7; //xy=864.9999847412109,1713.9999923706055
AudioFilterStateVariable lpf4; //xy=866.9999847412109,1215.9999923706055
AudioFilterStateVariable lpf6; //xy=866.9999847412109,1547.9999923706055
AudioFilterStateVariable lpf5; //xy=870.9999847412109,1383.9999923706055
AudioFilterStateVariable lpf3; //xy=872.9999847412109,1050.9999923706055
AudioFilterStateVariable lpf2; //xy=877.9999847412109,884.9999923706055
AudioFilterStateVariable lpf0;           //xy=881.3333129882812,541
AudioFilterStateVariable lpf1; //xy=881.9999847412109,713.9999923706055
AudioEffectEnvelope      vcfEnv;         //xy=905.3333129882812,304
AudioEffectEnvelope      env7; //xy=1002.9999847412109,1713.9999923706055
AudioEffectEnvelope      env4; //xy=1004.9999847412109,1215.9999923706055
AudioEffectEnvelope      env6; //xy=1004.9999847412109,1547.9999923706055
AudioEffectEnvelope      env5; //xy=1008.9999847412109,1383.9999923706055
AudioEffectEnvelope      env3; //xy=1010.9999847412109,1050.9999923706055
AudioEffectEnvelope      env2; //xy=1015.9999847412109,884.9999923706055
AudioEffectEnvelope      env0;           //xy=1019.3333129882812,541
AudioEffectEnvelope      env1; //xy=1019.9999847412109,713.9999923706055
AudioMixer4              vcfModMixer;    //xy=1108.3333129882812,327
AudioMixer4              EnvMixer0;      //xy=1260.3333129882812,815
AudioMixer4              EnvMixer1;      //xy=1283.3333129882812,1493
AudioMixer4              mixerL;         //xy=1513.3333129882812,1099
AudioMixer4              mixerR;         //xy=1520.3333129882812,1335
AudioEffectFlange        flangerL;       //xy=1693.3333129882812,1187
AudioEffectFlange        flangerR;       //xy=1698.3333129882812,1312
AudioAnalyzePeak         peak;           //xy=1717.3333129882812,663
AudioOutputI2S           i2s1;           //xy=1889.3333129882812,1239
AudioConnection          patchCord1(pwmDc, 0, pwmMixer, 1);
AudioConnection          patchCord2(lfo, 0, vcfModMixer, 0);
AudioConnection          patchCord3(lfo, dcoPitchAmp);
AudioConnection          patchCord4(lfo, 0, pwmMixer, 0);
AudioConnection          patchCord5(pwmMixer, 0, pulseLFO0, 1);
AudioConnection          patchCord6(pwmMixer, 0, pulseLFO1, 1);
AudioConnection          patchCord7(pwmMixer, 0, pulseLFO2, 1);
AudioConnection          patchCord8(pwmMixer, 0, pulseLFO3, 1);
AudioConnection          patchCord9(pwmMixer, 0, pulseLFO4, 1);
AudioConnection          patchCord10(pwmMixer, 0, pulseLFO5, 1);
AudioConnection          patchCord11(pwmMixer, 0, pulseLFO6, 1);
AudioConnection          patchCord12(pwmMixer, 0, pulseLFO7, 1);
AudioConnection          patchCord13(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord14(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord15(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord16(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord17(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord18(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord19(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord20(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord21(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord22(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord23(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord24(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord25(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord26(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord27(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord28(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord29(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord30(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord31(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord32(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord33(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord34(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord35(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord36(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord37(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord38(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord39(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord40(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord41(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord42(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord43(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord44(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord45(dcoPitchAmp, 0, testWaveform, 0);
AudioConnection          patchCord46(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord47(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord48(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord49(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord50(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord51(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord52(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord53(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord54(hpf7, 2, lpf7, 0);
AudioConnection          patchCord55(hpf4, 2, lpf4, 0);
AudioConnection          patchCord56(hpf6, 2, lpf6, 0);
AudioConnection          patchCord57(hpf5, 2, lpf5, 0);
AudioConnection          patchCord58(hpf3, 2, lpf3, 0);
AudioConnection          patchCord59(hpf2, 2, lpf2, 0);
AudioConnection          patchCord60(hpf0, 2, lpf0, 0);
AudioConnection          patchCord61(hpf1, 2, lpf1, 0);
AudioConnection          patchCord62(vcfEnvDc, vcfEnv);
AudioConnection          patchCord63(vcfKeyboardDc, 0, vcfModMixer, 2);
AudioConnection          patchCord64(vcfModWheelDc, 0, vcfModMixer, 3);
AudioConnection          patchCord65(lpf7, 0, env7, 0);
AudioConnection          patchCord66(lpf4, 0, env4, 0);
AudioConnection          patchCord67(lpf6, 0, env6, 0);
AudioConnection          patchCord68(lpf5, 0, env5, 0);
AudioConnection          patchCord69(lpf3, 0, env3, 0);
AudioConnection          patchCord70(lpf2, 0, env2, 0);
AudioConnection          patchCord71(lpf0, 0, env0, 0);
AudioConnection          patchCord72(lpf1, 0, env1, 0);
AudioConnection          patchCord73(vcfEnv, 0, vcfModMixer, 1);
AudioConnection          patchCord74(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord75(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord76(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord77(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord78(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord79(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord80(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord81(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord82(EnvMixer0, peak);
AudioConnection          patchCord83(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord84(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord85(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord86(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord87(mixerL, flangerL);
AudioConnection          patchCord88(mixerR, flangerR);
AudioConnection          patchCord89(flangerL, 0, i2s1, 0);
AudioConnection          patchCord90(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1670.3333129882812,993
// GUItool: end automatically generated code
