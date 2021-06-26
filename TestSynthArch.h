#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise0;         //xy=525,1391
AudioSynthNoiseWhite     noise4; //xy=522.1944389343262,2102.77587890625
AudioSynthNoiseWhite     noise1; //xy=524.4166679382324,1574.9981689453125
AudioSynthNoiseWhite     noise5; //xy=523.3055229187012,2273.886962890625
AudioSynthNoiseWhite     noise2; //xy=525.5277519226074,1756.1092529296875
AudioSynthWaveform sub0; //xy=528.4443969726562,1347.6685791015625
AudioSynthWaveform sub4; //xy=525.6388359069824,2059.4444580078125
AudioSynthWaveform sub1; //xy=527.8610649108887,1531.666748046875
AudioSynthNoiseWhite     noise6; //xy=524.4166679382324,2448.33154296875
AudioSynthNoiseWhite     noise3; //xy=526.6388359069824,1929.442626953125
AudioSynthWaveform sub5; //xy=526.7499198913574,2230.5555419921875
AudioSynthWaveform sub2; //xy=528.9721488952637,1712.77783203125
AudioSynthWaveform pulseLFO0; //xy=531.3333129882812,1264.3629035949707
AudioSynthWaveform pulseLFO4; //xy=528.5277519226074,1976.1387825012207
AudioSynthWaveform pulseLFO1; //xy=530.7499809265137,1448.3610725402832
AudioSynthNoiseWhite     noise7; //xy=526.6388359069824,2620.5537109375
AudioSynthWaveform sub6; //xy=527.8610649108887,2405.0001220703125
AudioSynthWaveform sub3; //xy=530.0832328796387,1886.1112060546875
AudioSynthWaveform pulseLFO5; //xy=529.6388359069824,2147.2498664855957
AudioSynthWaveform pulseLFO2; //xy=531.8610649108887,1629.4721565246582
AudioSynthWaveform saw0; //xy=533.6666412353516,1300.1406784057617
AudioSynthWaveform saw4;  //xy=530.8610801696777,2011.9165573120117
AudioSynthWaveform saw1; //xy=533.083309173584,1484.1388473510742
AudioSynthWaveform pulseLFO6; //xy=530.7499809265137,2321.6944465637207
AudioSynthWaveform pulseLFO3; //xy=532.9721488952637,1802.8055305480957
AudioSynthWaveform sub7; //xy=530.0832328796387,2577.2222900390625
AudioSynthWaveform saw5; //xy=531.9721641540527,2183.0276412963867
AudioSynthWaveform saw2; //xy=534.194393157959,1665.2499313354492
AudioSynthWaveform saw6;  //xy=533.083309173584,2357.4722213745117
AudioSynthWaveform saw3; //xy=535.305477142334,1838.5833053588867
AudioSynthWaveform pulseLFO7; //xy=532.9721488952637,2493.9166145324707
AudioSynthWaveform saw7; //xy=535.305477142334,2529.6943893432617
AudioMixer4              oscMixer0; //xy=730.5833320617676,1342.66845703125
AudioMixer4              oscMixer4; //xy=727.7777709960938,2054.4443359375
AudioMixer4              oscMixer1; //xy=730,1526.6666259765625
AudioMixer4              oscMixer5; //xy=728.8888549804688,2225.555419921875
AudioMixer4              oscMixer2; //xy=731.111083984375,1707.7777099609375
AudioMixer4              oscMixer6; //xy=730,2400
AudioMixer4              oscMixer3; //xy=732.22216796875,1881.111083984375
AudioMixer4              oscMixer7; //xy=732.22216796875,2572.22216796875
AudioFilterStateVariable hpf0;  //xy=873.4443702697754,1353.6683330535889
AudioFilterStateVariable hpf4; //xy=870.6388092041016,2065.444211959839
AudioFilterStateVariable hpf1; //xy=872.8610382080078,1537.6665019989014
AudioFilterStateVariable hpf5;  //xy=871.7498931884766,2236.555295944214
AudioFilterStateVariable hpf2; //xy=873.9721221923828,1718.7775859832764
AudioFilterStateVariable hpf6; //xy=872.8610382080078,2410.999876022339
AudioFilterStateVariable hpf3; //xy=875.0832061767578,1892.1109600067139
AudioFilterStateVariable hpf7; //xy=875.0832061767578,2583.222043991089
AudioFilterStateVariable lpf0; //xy=1006.2221832275391,1373.1128063201904
AudioFilterStateVariable lpf4; //xy=1003.4166221618652,2084.8886852264404
AudioFilterStateVariable lpf1; //xy=1005.6388511657715,1557.110975265503
AudioFilterStateVariable lpf5; //xy=1004.5277061462402,2255.9997692108154
AudioFilterStateVariable lpf2; //xy=1006.7499351501465,1738.222059249878
AudioFilterStateVariable lpf6; //xy=1005.6388511657715,2430.4443492889404
AudioFilterStateVariable lpf3; //xy=1007.8610191345215,1911.5554332733154
AudioFilterStateVariable lpf7; //xy=1007.8610191345215,2602.6665172576904
AudioEffectEnvelope      env0; //xy=1144.001708984375,1373.890625
AudioEffectEnvelope      env4; //xy=1141.1961479187012,2085.66650390625
AudioEffectEnvelope      env1; //xy=1143.4183769226074,1557.8887939453125
AudioEffectEnvelope      env5; //xy=1142.3072319030762,2256.777587890625
AudioEffectEnvelope      env2; //xy=1144.5294609069824,1738.9998779296875
AudioEffectEnvelope      env3; //xy=1144.211929321289,1903.7618780136108
AudioEffectEnvelope      env6; //xy=1143.4183769226074,2431.22216796875
AudioEffectEnvelope      env7; //xy=1145.6405448913574,2603.4443359375
AudioMixer4              EnvMixer0; //xy=1422.3668174743652,1687.90678024292
AudioMixer4              EnvMixer1; //xy=1438.5714111328125,2341.4287109375
AudioMixer4              finalMixer; //xy=1655.71435546875,2048.571533203125
AudioAnalyzePeak         peak; //xy=1842.1445770263672,1495.0334587097168
AudioOutputI2S           i2s1; //xy=1865.1285972595215,2022.620849609375
AudioConnection          patchCord1(noise0, 0, oscMixer0, 3);
AudioConnection          patchCord2(noise4, 0, oscMixer4, 3);
AudioConnection          patchCord3(noise1, 0, oscMixer1, 3);
AudioConnection          patchCord4(noise5, 0, oscMixer5, 3);
AudioConnection          patchCord5(noise2, 0, oscMixer2, 3);
AudioConnection          patchCord6(sub0, 0, oscMixer0, 2);
AudioConnection          patchCord7(sub4, 0, oscMixer4, 2);
AudioConnection          patchCord8(sub1, 0, oscMixer1, 2);
AudioConnection          patchCord9(noise6, 0, oscMixer6, 3);
AudioConnection          patchCord10(noise3, 0, oscMixer3, 3);
AudioConnection          patchCord11(sub5, 0, oscMixer5, 2);
AudioConnection          patchCord12(sub2, 0, oscMixer2, 2);
AudioConnection          patchCord13(pulseLFO0, 0, oscMixer0, 0);
AudioConnection          patchCord14(pulseLFO4, 0, oscMixer4, 0);
AudioConnection          patchCord15(pulseLFO1, 0, oscMixer1, 0);
AudioConnection          patchCord16(noise7, 0, oscMixer7, 3);
AudioConnection          patchCord17(sub6, 0, oscMixer6, 2);
AudioConnection          patchCord18(sub3, 0, oscMixer3, 2);
AudioConnection          patchCord19(pulseLFO5, 0, oscMixer5, 0);
AudioConnection          patchCord20(pulseLFO2, 0, oscMixer2, 0);
AudioConnection          patchCord21(saw0, 0, oscMixer0, 1);
AudioConnection          patchCord22(saw4, 0, oscMixer4, 1);
AudioConnection          patchCord23(saw1, 0, oscMixer1, 1);
AudioConnection          patchCord24(pulseLFO6, 0, oscMixer6, 0);
AudioConnection          patchCord25(pulseLFO3, 0, oscMixer3, 0);
AudioConnection          patchCord26(sub7, 0, oscMixer7, 2);
AudioConnection          patchCord27(saw5, 0, oscMixer5, 1);
AudioConnection          patchCord28(saw2, 0, oscMixer2, 1);
AudioConnection          patchCord29(saw6, 0, oscMixer6, 1);
AudioConnection          patchCord30(saw3, 0, oscMixer3, 1);
AudioConnection          patchCord31(pulseLFO7, 0, oscMixer7, 0);
AudioConnection          patchCord32(saw7, 0, oscMixer7, 1);
AudioConnection          patchCord33(oscMixer0, 0, hpf0, 0);
AudioConnection          patchCord34(oscMixer4, 0, hpf4, 0);
AudioConnection          patchCord35(oscMixer1, 0, hpf1, 0);
AudioConnection          patchCord36(oscMixer5, 0, hpf5, 0);
AudioConnection          patchCord37(oscMixer2, 0, hpf2, 0);
AudioConnection          patchCord38(oscMixer6, 0, hpf6, 0);
AudioConnection          patchCord39(oscMixer3, 0, hpf3, 0);
AudioConnection          patchCord40(oscMixer7, 0, hpf7, 0);
AudioConnection          patchCord41(hpf0, 2, lpf0, 0);
AudioConnection          patchCord42(hpf4, 2, lpf4, 0);
AudioConnection          patchCord43(hpf1, 2, lpf1, 0);
AudioConnection          patchCord44(hpf5, 2, lpf5, 0);
AudioConnection          patchCord45(hpf2, 2, lpf2, 0);
AudioConnection          patchCord46(hpf6, 2, lpf6, 0);
AudioConnection          patchCord47(hpf3, 2, lpf3, 0);
AudioConnection          patchCord48(hpf7, 2, lpf7, 0);
AudioConnection          patchCord49(lpf0, 0, env0, 0);
AudioConnection          patchCord50(lpf4, 0, env4, 0);
AudioConnection          patchCord51(lpf1, 0, env1, 0);
AudioConnection          patchCord52(lpf5, 0, env5, 0);
AudioConnection          patchCord53(lpf2, 0, env2, 0);
AudioConnection          patchCord54(lpf6, 0, env6, 0);
AudioConnection          patchCord55(lpf3, 0, env3, 0);
AudioConnection          patchCord56(lpf7, 0, env7, 0);
AudioConnection          patchCord57(env0, 0, EnvMixer0, 0);
AudioConnection          patchCord58(env4, 0, EnvMixer1, 0);
AudioConnection          patchCord59(env1, 0, EnvMixer0, 1);
AudioConnection          patchCord60(env5, 0, EnvMixer1, 1);
AudioConnection          patchCord61(env2, 0, EnvMixer0, 2);
AudioConnection          patchCord62(env3, 0, EnvMixer0, 3);
AudioConnection          patchCord63(env6, 0, EnvMixer1, 2);
AudioConnection          patchCord64(env7, 0, EnvMixer1, 3);
AudioConnection          patchCord65(EnvMixer0, peak);
AudioConnection          patchCord66(EnvMixer0, 0, finalMixer, 0);
AudioConnection          patchCord67(EnvMixer1, 0, finalMixer, 1);
AudioConnection          patchCord68(finalMixer, 0, i2s1, 0);
AudioConnection          patchCord69(finalMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1795.698600769043,1825.7857465744019
// GUItool: end automatically generated code
