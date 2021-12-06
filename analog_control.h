// #include "pins.h"
double readPos(int muxAddress, int muxPosition) {
    return (1023-(muxArray[muxAddress].Mux::read(muxPosition)));
}

void analogControl() {
//    checkSliders();
}

void checkSliders() {
//  Serial.println("check sliders");
    double value;
    
    value =  (pow(readPos(0,0),2));
    if (value != lfoRate) {
      Serial.println("lfo rate update");
        lfoRate = value;
        updateLfo();
    }

//    value = 2000 * (pow(readPos(0,1),2));
//    if (value != lfoDelay) {
//        lfoDelay = value;
//        updateLfoDelay();
//    }
//
//    value = (pow(readPos(0,2),2));
//    if (value != oscLfoLevel) {
//        Serial.println("osc lfo level update");
//        oscLfoLevel = value;
//        updateOscLfo();
//    }
//
//    value = (readPos(0,3))*0.9+0.05;
//    if (value != pulseWidth) {
//        pulseWidth = value;
//        updatePulseWidth();
//    }
//
//    value = readPos(0,4);
//    if (value != subLevel) {
//        subLevel = value;
//        updateOscVolume();
//    }
//
//    value = readPos(0,5);
//    if (value != noiseLevel) {
//        noiseLevel = value;
//        updateOscVolume();
//    }
//    //hpf frequency
//    value = pow(readPos(0,6),2);
//    if (value != hpfFreq) {
//        hpfFreq = value;
//        updateHPF();
//    }
//    //lpf frequency
//    value = min((pow(readPos(0,7),2)),10000);
//    if (value != lpfFreq) {
//        lpfFreq = value;
//        updateLPF();
//    }
//    //lpf resonance
//    value = readPos(0,8)*4.1/127.+0.9;
//    if (value != lpfReso) {
//            lpfReso = value;
//            updateLPF();
//        }
//    //lpf envelope level
//    value = readPos(0,9)*2;
//    if (value != lpfEnvLevel) {
//            lpfEnvLevel = value;
//            updateLpfMod();
//        }
//    //lpf lfo level
//    value = readPos(0,10)*2;
//    if (value != lpfLfoLevel) {
//            lpfLfoLevel = value;
//            updateLpfMod();
//        }
//    //lpf keyboard level
//    value = readPos(0,11)*2;
//    if (value != lpfKbdLevel) {
//            lpfKbdLevel = value;
//            updateLpfMod();
//        }
//    //channel volume
//    value = readPos(0,12);
//    if (value != channelVolume) {
//            channelVolume = value;
//            updateVolume();
//        }
//    //flanger offset
//    value = int (readPos(0,13)*8)*DELAY_LENGTH/8;
//    if (value != flangerOffset) {
//            flangerOffset = value;
//            updateFlanger();
//        }
//    //flanger depth
//    value = int (readPos(0,14)*8)*DELAY_LENGTH/8;
//    if (value != flangerDepth) {
//            flangerDepth = value;
//            updateFlanger();
//        }
//    //flanger frequency coarse
//    value = readPos(0,15)*10;
//    if (value != flangerFreqCoarse) {
//            flangerFreqCoarse = value;
//            updateFlanger();
//        }
//    //flanger frequency fine
//    value = readPos(1,0);
//    if (value != flangerFreqFine) {
//            flangerFreqFine = value;
//            updateFlanger();
//        }
//    //envelope attack
//    value = pow(readPos(1,1),2) * 1000;
//    if (value != envAttack) {
//            envAttack = value;
//            updateEnvelope();
//        }
//    //envelope decay
//    value = readPos(1,2) * 200;
//    if (value != envDecay) {
//            envDecay = value;
//            updateEnvelope();
//        }
//    //envelope sustain
//    value = readPos(1,3);
//    if (value != envSustain) {
//            envDecay = value;
//            updateEnvelope();
//        }
//    //envelope release
//    value = readPos(1,4);
//    if (value != envRelease) {
//            envRelease = value;
//            updateEnvelope();
//        }
    

    //master volume
//    value = readPos(1,8);
//    if (value != masterVolume) {
//        masterVolume = value;
//        updateMasterVolume();
//    }
}
