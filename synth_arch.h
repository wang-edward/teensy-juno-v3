#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=205.3333282470703,475.00000762939453
AudioSynthNoiseWhite     noise4;         //xy=203.3333282470703,1003.0000076293945
AudioSynthNoiseWhite     noise0;         //xy=206.3333282470703,292.00000762939453
AudioSynthNoiseWhite     noise2;         //xy=206.3333282470703,657.0000076293945
AudioSynthNoiseWhite     noise5;         //xy=204.3333282470703,1174.0000076293945
AudioSynthWaveform       sub1;           //xy=208.3333282470703,432.00000762939453
AudioSynthWaveform       sub4;           //xy=206.3333282470703,960.0000076293945
AudioSynthWaveform       sub0;           //xy=209.3333282470703,248.00000762939453
AudioSynthNoiseWhite     noise3;         //xy=207.3333282470703,830.0000076293945
AudioSynthNoiseWhite     noise6;         //xy=205.3333282470703,1349.0000076293945
AudioSynthWaveform       sub2;           //xy=209.3333282470703,613.0000076293945
AudioSynthWaveform       sub5;           //xy=207.3333282470703,1131.0000076293945
AudioSynthWaveform       pulseLFO1;      //xy=211.3333282470703,349.00000762939453
AudioSynthWaveform       pulseLFO4;      //xy=209.3333282470703,877.0000076293945
AudioSynthWaveform       pulseLFO0;      //xy=212.3333282470703,165.00000762939453
AudioSynthNoiseWhite     noise7;         //xy=207.3333282470703,1521.0000076293945
AudioSynthWaveform       sub6;           //xy=208.3333282470703,1306.0000076293945
AudioSynthWaveform       pulseLFO2;      //xy=212.3333282470703,530.0000076293945
AudioSynthWaveform       sub3;           //xy=211.3333282470703,787.0000076293945
AudioSynthWaveform       pulseLFO5;      //xy=210.3333282470703,1048.0000076293945
AudioSynthWaveform       saw4;           //xy=211.3333282470703,912.0000076293945
AudioSynthWaveform       saw0;           //xy=214.3333282470703,201.00000762939453
AudioSynthWaveform       saw1;           //xy=214.3333282470703,385.00000762939453
AudioSynthWaveform       pulseLFO3;      //xy=213.3333282470703,703.0000076293945
AudioSynthWaveform       pulseLFO6;      //xy=211.3333282470703,1222.0000076293945
AudioSynthWaveform       saw5;           //xy=212.3333282470703,1084.0000076293945
AudioSynthWaveform       sub7;           //xy=211.3333282470703,1478.0000076293945
AudioSynthWaveform       saw2;           //xy=215.3333282470703,566.0000076293945
AudioSynthWaveform       pulseLFO7;      //xy=213.3333282470703,1394.0000076293945
AudioSynthWaveform       saw3;           //xy=216.3333282470703,739.0000076293945
AudioSynthWaveform       saw6;           //xy=214.3333282470703,1258.0000076293945
AudioSynthWaveform       saw7;           //xy=216.3333282470703,1430.0000076293945
AudioMixer4              oscMixer4;      //xy=408.3333282470703,955.0000076293945
AudioMixer4              oscMixer0;      //xy=411.3333282470703,243.00000762939453
AudioMixer4              oscMixer1;      //xy=411.3333282470703,427.00000762939453
AudioMixer4              oscMixer5;      //xy=409.3333282470703,1126.0000076293945
AudioMixer4              oscMixer2;      //xy=412.3333282470703,608.0000076293945
AudioMixer4              oscMixer3;      //xy=413.3333282470703,782.0000076293945
AudioMixer4              oscMixer6;      //xy=411.3333282470703,1301.0000076293945
AudioMixer4              oscMixer7;      //xy=413.3333282470703,1473.0000076293945
AudioFilterStateVariable hpf1;           //xy=553.3333282470703,438.00000762939453
AudioFilterStateVariable hpf4;           //xy=551.3333282470703,966.0000076293945
AudioFilterStateVariable hpf0;           //xy=554.3333282470703,254.00000762939453
AudioFilterStateVariable hpf2;           //xy=554.3333282470703,619.0000076293945
AudioFilterStateVariable hpf5;           //xy=552.3333282470703,1137.0000076293945
AudioFilterStateVariable hpf6;           //xy=553.3333282470703,1311.0000076293945
AudioFilterStateVariable hpf3;           //xy=556.3333282470703,793.0000076293945
AudioFilterStateVariable hpf7;           //xy=556.3333282470703,1484.0000076293945
AudioFilterStateVariable lpf1;           //xy=686.3333282470703,458.00000762939453
AudioFilterStateVariable lpf4;           //xy=684.3333282470703,985.0000076293945
AudioFilterStateVariable lpf0;           //xy=687.3333282470703,274.00000762939453
AudioFilterStateVariable lpf2;           //xy=687.3333282470703,639.0000076293945
AudioFilterStateVariable lpf5;           //xy=685.3333282470703,1156.0000076293945
AudioFilterStateVariable lpf3;           //xy=688.3333282470703,812.0000076293945
AudioFilterStateVariable lpf6;           //xy=686.3333282470703,1331.0000076293945
AudioFilterStateVariable lpf7;           //xy=688.3333282470703,1503.0000076293945
AudioEffectEnvelope      env1;           //xy=824.3333282470703,458.00000762939453
AudioEffectEnvelope      env4;           //xy=822.3333282470703,986.0000076293945
AudioEffectEnvelope      env0;           //xy=825.3333282470703,274.00000762939453
AudioEffectEnvelope      env2;           //xy=825.3333282470703,639.0000076293945
AudioEffectEnvelope      env5;           //xy=823.3333282470703,1157.0000076293945
AudioEffectEnvelope      env3;           //xy=825.3333282470703,804.0000076293945
AudioEffectEnvelope      env6;           //xy=824.3333282470703,1332.0000076293945
AudioEffectEnvelope      env7;           //xy=826.3333282470703,1504.0000076293945
AudioMixer4              EnvMixer0;      //xy=1066.333251953125,548.0000305175781
AudioMixer4              EnvMixer1;      //xy=1089.3331909179688,1226.9999389648438
AudioMixer4              mixerL;         //xy=1319.3333282470703,832.0000076293945
AudioMixer4              mixerR;         //xy=1326.3333282470703,1068.0000076293945
AudioEffectFlange        flangerL;       //xy=1499.3333282470703,920.0000076293945
AudioEffectFlange        flangerR;       //xy=1504.3333282470703,1045.0000076293945
AudioAnalyzePeak         peak;           //xy=1523.3333282470703,396.00000762939453
AudioOutputI2S           i2s1;           //xy=1695.3333282470703,972.0000076293945
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
AudioConnection          patchCord57(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord58(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord59(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord60(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord61(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord62(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord63(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord64(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord65(EnvMixer0, peak);
AudioConnection          patchCord66(EnvMixer0, 0, mixerL, 0);
AudioConnection          patchCord67(EnvMixer0, 0, mixerR, 0);
AudioConnection          patchCord68(EnvMixer1, 0, mixerL, 1);
AudioConnection          patchCord69(EnvMixer1, 0, mixerR, 1);
AudioConnection          patchCord70(mixerL, flangerL);
AudioConnection          patchCord71(mixerR, flangerR);
AudioConnection          patchCord72(flangerL, 0, i2s1, 0);
AudioConnection          patchCord73(flangerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1476.3333282470703,726.0000076293945
// GUItool: end automatically generated code
