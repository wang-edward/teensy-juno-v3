#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       LFO2; //xy=320.4183464050293,1939.4738636016846
AudioSynthWaveform       LFO3; //xy=319.4183464050293,2220.807237625122
AudioSynthWaveform       LFO1; //xy=328.4183464050293,1682.362657546997
AudioSynthWaveform       LFO0;  //xy=329.9999694824219,1403.029405593872
AudioSynthWaveformDc     dc2; //xy=512.8627433776855,1979.0019073486328
AudioSynthWaveformDc     dc3;  //xy=511.86274337768555,2260.3352813720703
AudioSynthWaveformModulated noise2; //xy=515.8627738952637,1911.1129875183105
AudioSynthWaveformModulated noise3; //xy=514.8627738952637,2192.446361541748
AudioSynthWaveformDc     dc1; //xy=520.8627433776855,1721.8907012939453
AudioSynthWaveformDc     dc0; //xy=522.4443664550781,1442.5574493408203
AudioSynthWaveformModulated squareLFO2; //xy=521.7516899108887,1800.8073616027832
AudioSynthWaveformModulated squareLFO3; //xy=520.7516899108887,2082.1407356262207
AudioSynthWaveformModulated noise1; //xy=523.8627738952637,1654.001781463623
AudioSynthWaveformModulated noise0; //xy=525.4443969726562,1374.668529510498
AudioSynthWaveformModulated saw2; //xy=524.085018157959,1836.5851364135742
AudioSynthWaveformModulated saw3; //xy=523.085018157959,2117.9185104370117
AudioSynthWaveform       squarePWM2; //xy=525.8628005981445,1876.3350458145142
AudioSynthWaveform       squarePWM3; //xy=524.8628005981445,2157.6684198379517
AudioSynthWaveformModulated squareLFO1; //xy=529.7516899108887,1543.6961555480957
AudioSynthWaveformModulated squareLFO0; //xy=531.3333129882812,1264.3629035949707
AudioSynthWaveformModulated saw1;  //xy=532.085018157959,1579.4739303588867
AudioSynthWaveformModulated saw0; //xy=533.6666412353516,1300.1406784057617
AudioSynthWaveform       squarePWM1; //xy=533.8628005981445,1619.2238397598267
AudioSynthWaveform       squarePWM0; //xy=535.4444236755371,1339.8905878067017
AudioSynthWaveformDc     keyTrack2; //xy=668.3072166442871,2010.4462985992432
AudioSynthWaveformDc     keyTrack3; //xy=667.3072166442871,2291.7796726226807
AudioEffectEnvelope      lpfEnv2; //xy=672.5294303894043,1956.6684741973877
AudioEffectEnvelope      lpfEnv3; //xy=671.5294303894043,2238.001848220825
AudioSynthWaveformDc     keyTrack1; //xy=676.3072166442871,1753.3350925445557
AudioSynthWaveformDc     keyTrack0; //xy=677.8888397216797,1474.0018405914307
AudioEffectEnvelope      lpfEnv1; //xy=680.5294303894043,1699.5572681427002
AudioEffectEnvelope      lpfEnv0; //xy=682.1110534667969,1420.2240161895752
AudioMixer4              oscMixer2; //xy=721.001708984375,1879.1129150390625
AudioMixer4              oscMixer3; //xy=720.001708984375,2160.4462890625
AudioMixer4              oscMixer1; //xy=729.001708984375,1622.001708984375
AudioMixer4              oscMixer0; //xy=730.5833320617676,1342.66845703125
AudioMixer4              lpfModMix2; //xy=848.751651763916,1954.2239742279053
AudioMixer4              lpfModMix3; //xy=847.751651763916,2235.557348251343
AudioMixer4              lpfModMix1; //xy=856.751651763916,1697.1127681732178
AudioMixer4              lpfModMix0; //xy=858.3332748413086,1417.7795162200928
AudioFilterStateVariable hpf2; //xy=863.8627471923828,1890.1127910614014
AudioFilterStateVariable hpf3; //xy=862.8627471923828,2171.446165084839
AudioFilterStateVariable hpf1; //xy=871.8627471923828,1633.0015850067139
AudioFilterStateVariable hpf0;  //xy=873.4443702697754,1353.6683330535889
AudioFilterStateVariable lpf2; //xy=996.6405601501465,1909.557264328003
AudioFilterStateVariable lpf3; //xy=995.6405601501465,2190.8906383514404
AudioFilterStateVariable lpf1; //xy=1004.6405601501465,1652.4460582733154
AudioFilterStateVariable lpf0; //xy=1006.2221832275391,1373.1128063201904
AudioEffectEnvelope      env2; //xy=1134.4200859069824,1910.3350830078125
AudioEffectEnvelope      env3; //xy=1133.4200859069824,2191.66845703125
AudioEffectEnvelope      env1; //xy=1142.4200859069824,1653.223876953125
AudioEffectEnvelope      env0; //xy=1144.001708984375,1373.890625
AudioMixer4              EnvMixer0; //xy=1343.0017738342285,1763.7797393798828
AudioAnalyzePeak         peak2; //xy=1485.0017547607422,1406.779528617859
AudioOutputI2S           i2s1; //xy=1568.7794647216797,1781.6684322357178
AudioConnection          patchCord1(LFO2, 0, squareLFO2, 0);
AudioConnection          patchCord2(LFO2, 0, saw2, 0);
AudioConnection          patchCord3(LFO2, 0, lpfModMix2, 0);
AudioConnection          patchCord4(LFO3, 0, squareLFO3, 0);
AudioConnection          patchCord5(LFO3, 0, saw3, 0);
AudioConnection          patchCord6(LFO3, 0, lpfModMix3, 0);
AudioConnection          patchCord7(LFO1, 0, squareLFO1, 0);
AudioConnection          patchCord8(LFO1, 0, saw1, 0);
AudioConnection          patchCord9(LFO1, 0, lpfModMix1, 0);
AudioConnection          patchCord10(LFO0, 0, squareLFO0, 0);
AudioConnection          patchCord11(LFO0, 0, saw0, 0);
AudioConnection          patchCord12(LFO0, 0, lpfModMix0, 0);
AudioConnection          patchCord13(dc2, lpfEnv2);
AudioConnection          patchCord14(dc3, lpfEnv3);
AudioConnection          patchCord15(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord16(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord17(dc1, lpfEnv1);
AudioConnection          patchCord18(dc0, lpfEnv0);
AudioConnection          patchCord19(squareLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord20(squareLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord21(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord22(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord23(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord24(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord25(squarePWM2, 0, oscMixer2, 2);
AudioConnection          patchCord26(squarePWM3, 0, oscMixer3, 2);
AudioConnection          patchCord27(squareLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord28(squareLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord29(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord30(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord31(squarePWM1, 0, oscMixer1, 2);
AudioConnection          patchCord32(squarePWM0, 0, oscMixer0, 2);
AudioConnection          patchCord33(keyTrack2, 0, lpfModMix2, 2);
AudioConnection          patchCord34(keyTrack3, 0, lpfModMix3, 2);
AudioConnection          patchCord35(lpfEnv2, 0, lpfModMix2, 1);
AudioConnection          patchCord36(lpfEnv3, 0, lpfModMix3, 1);
AudioConnection          patchCord37(keyTrack1, 0, lpfModMix1, 2);
AudioConnection          patchCord38(keyTrack0, 0, lpfModMix0, 2);
AudioConnection          patchCord39(lpfEnv1, 0, lpfModMix1, 1);
AudioConnection          patchCord40(lpfEnv0, 0, lpfModMix0, 1);
AudioConnection          patchCord41(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord42(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord43(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord44(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord45(lpfModMix2, 0, lpf2, 1);
AudioConnection          patchCord46(lpfModMix3, 0, lpf3, 1);
AudioConnection          patchCord47(lpfModMix1, 0, lpf1, 1);
AudioConnection          patchCord48(lpfModMix0, 0, lpf0, 1);
AudioConnection          patchCord49(hpf2, 2, lpf2, 0);
AudioConnection          patchCord50(hpf3, 2, lpf3, 0);
AudioConnection          patchCord51(hpf1, 2, lpf1, 0);
AudioConnection          patchCord52(hpf0, 2, lpf0, 0);
AudioConnection          patchCord53(lpf2, 0, env2, 0);
AudioConnection          patchCord54(lpf3, 0, env3, 0);
AudioConnection          patchCord55(lpf1, 0, env1, 0);
AudioConnection          patchCord56(lpf0, 0, env0, 0);
AudioConnection          patchCord57(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord58(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord59(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord60(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord61(EnvMixer0, peak2);
AudioConnection          patchCord62(EnvMixer0, 0, i2s1, 0);
AudioConnection          patchCord63(EnvMixer0, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1682.2064743041992,1669.3412551879883
// GUItool: end automatically generated code
