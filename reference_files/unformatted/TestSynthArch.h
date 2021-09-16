#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=298.45001220703125,606.0000152587891
AudioSynthNoiseWhite     noise4;         //xy=296.45001220703125,1134.000015258789
AudioSynthNoiseWhite     noise0;         //xy=299.45001220703125,423.00001525878906
AudioSynthNoiseWhite     noise2;         //xy=299.45001220703125,788.0000152587891
AudioSynthNoiseWhite     noise5;         //xy=297.45001220703125,1305.000015258789
AudioSynthWaveform       sub1;           //xy=301.45001220703125,563.0000152587891
AudioSynthWaveform       sub4;           //xy=299.45001220703125,1091.000015258789
AudioSynthWaveform       sub0;           //xy=302.45001220703125,379.00001525878906
AudioSynthNoiseWhite     noise3;         //xy=300.45001220703125,961.0000152587891
AudioSynthNoiseWhite     noise6;         //xy=298.45001220703125,1480.000015258789
AudioSynthWaveform       sub2;           //xy=302.45001220703125,744.0000152587891
AudioSynthWaveform       sub5;           //xy=300.45001220703125,1262.000015258789
AudioSynthWaveform       pulseLFO1;      //xy=304.45001220703125,480.00001525878906
AudioSynthWaveform       pulseLFO4;      //xy=302.45001220703125,1008.0000152587891
AudioSynthWaveform       pulseLFO0;      //xy=305.45001220703125,296.00001525878906
AudioSynthNoiseWhite     noise7;         //xy=300.45001220703125,1652.000015258789
AudioSynthWaveform       sub6;           //xy=301.45001220703125,1437.000015258789
AudioSynthWaveform       pulseLFO2;      //xy=305.45001220703125,661.0000152587891
AudioSynthWaveform       sub3;           //xy=304.45001220703125,918.0000152587891
AudioSynthWaveform       pulseLFO5;      //xy=303.45001220703125,1179.000015258789
AudioSynthWaveform       saw4;           //xy=304.45001220703125,1043.000015258789
AudioSynthWaveform       saw0;           //xy=307.45001220703125,332.00001525878906
AudioSynthWaveform       saw1;           //xy=307.45001220703125,516.0000152587891
AudioSynthWaveform       pulseLFO3;      //xy=306.45001220703125,834.0000152587891
AudioSynthWaveform       pulseLFO6;      //xy=304.45001220703125,1353.000015258789
AudioSynthWaveform       saw5;           //xy=305.45001220703125,1215.000015258789
AudioSynthWaveform       sub7;           //xy=304.45001220703125,1609.000015258789
AudioSynthWaveform       saw2;           //xy=308.45001220703125,697.0000152587891
AudioSynthWaveform       pulseLFO7;      //xy=306.45001220703125,1525.000015258789
AudioSynthWaveform       saw3;           //xy=309.45001220703125,870.0000152587891
AudioSynthWaveform       saw6;           //xy=307.45001220703125,1389.000015258789
AudioSynthWaveform       saw7;           //xy=309.45001220703125,1561.000015258789
AudioMixer4              oscMixer4;      //xy=501.45001220703125,1086.000015258789
AudioMixer4              oscMixer0;      //xy=504.45001220703125,374.00001525878906
AudioMixer4              oscMixer1;      //xy=504.45001220703125,558.0000152587891
AudioMixer4              oscMixer5;      //xy=502.45001220703125,1257.000015258789
AudioMixer4              oscMixer2;      //xy=505.45001220703125,739.0000152587891
AudioMixer4              oscMixer3;      //xy=506.45001220703125,913.0000152587891
AudioMixer4              oscMixer6;      //xy=504.45001220703125,1432.000015258789
AudioMixer4              oscMixer7;      //xy=506.45001220703125,1604.000015258789
AudioFilterStateVariable hpf1;           //xy=646.4500122070312,569.0000152587891
AudioFilterStateVariable hpf4;           //xy=644.4500122070312,1097.000015258789
AudioFilterStateVariable hpf0;           //xy=647.4500122070312,385.00001525878906
AudioFilterStateVariable hpf2;           //xy=647.4500122070312,750.0000152587891
AudioFilterStateVariable hpf5;           //xy=645.4500122070312,1268.000015258789
AudioFilterStateVariable hpf6;           //xy=646.4500122070312,1442.000015258789
AudioFilterStateVariable hpf3;           //xy=649.4500122070312,924.0000152587891
AudioFilterStateVariable hpf7;           //xy=649.4500122070312,1615.000015258789
AudioFilterStateVariable lpf1;           //xy=779.4500122070312,589.0000152587891
AudioFilterStateVariable lpf4;           //xy=777.4500122070312,1116.000015258789
AudioFilterStateVariable lpf0;           //xy=780.4500122070312,405.00001525878906
AudioFilterStateVariable lpf2;           //xy=780.4500122070312,770.0000152587891
AudioFilterStateVariable lpf5;           //xy=778.4500122070312,1287.000015258789
AudioFilterStateVariable lpf3;           //xy=781.4500122070312,943.0000152587891
AudioFilterStateVariable lpf6;           //xy=779.4500122070312,1462.000015258789
AudioFilterStateVariable lpf7;           //xy=781.4500122070312,1634.000015258789
AudioEffectEnvelope      env1;           //xy=917.4500122070312,589.0000152587891
AudioEffectEnvelope      env4;           //xy=915.4500122070312,1117.000015258789
AudioEffectEnvelope      env0;           //xy=918.4500122070312,405.00001525878906
AudioEffectEnvelope      env2;           //xy=918.4500122070312,770.0000152587891
AudioEffectEnvelope      env5;           //xy=916.4500122070312,1288.000015258789
AudioEffectEnvelope      env3;           //xy=918.4500122070312,935.0000152587891
AudioEffectEnvelope      env6;           //xy=917.4500122070312,1463.000015258789
AudioEffectEnvelope      env7;           //xy=919.4500122070312,1635.000015258789
AudioMixer4              EnvMixer0;      //xy=1196.4500122070312,719.0000152587891
AudioMixer4              EnvMixer1;      //xy=1212.4500122070312,1373.000015258789
AudioMixer4              finalMixer;     //xy=1457.449951171875,1077.9999389648438
AudioEffectChorus        chorus1;        //xy=1557,1186.9999389648438
AudioAnalyzePeak         peak;           //xy=1616.4500122070312,527.0000152587891
AudioMixer4              ChorusMixer;         //xy=1697.8999938964844,1088.8999938964844
AudioOutputI2S           i2s1;           //xy=1870.449951171875,1091.9999389648438
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
AudioConnection          patchCord66(EnvMixer0, 0, finalMixer, 0);
AudioConnection          patchCord67(EnvMixer1, 0, finalMixer, 1);
AudioConnection          patchCord68(finalMixer, chorus1);
AudioConnection          patchCord69(finalMixer, 0, ChorusMixer, 0);
AudioConnection          patchCord70(chorus1, 0, ChorusMixer, 1);
AudioConnection          patchCord71(ChorusMixer, 0, i2s1, 0);
AudioConnection          patchCord72(ChorusMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1569.4500122070312,857.0000152587891
// GUItool: end automatically generated code
