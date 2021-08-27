void OnControlChange(uint8_t channel, uint8_t control, uint8_t value) {
//  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;
  switch (control) {
  case 0: // bank select, do nothing (switch sounds via program change only)
    break;
  case 5: // portamento time ?
  {
    float portamentoRange = portamentoStep*portamentoTime;
    portamentoTime = value*50;
    portamentoStep = portamentoRange/portamentoTime;
    break;
  }
  case 7: // volume v
    channelVolume = value/127.;
    updateVolume();
    break;
  case 9: // velocity v
    switch (value) {
    case 0:
      velocityOn = false;
      break;
    case 1:
      velocityOn = true;
      break;
    default:
      velocityOn = !velocityOn;
      break;
    }
    break;
  case 10: // pan v
     panorama = value/127.;
    updatePan();
    break;
  case 12: // attack v
    envAttack = value*200./127.;
    updateEnvelope();
    break;
  case 13: // release v
    envRelease = value*200./127.;
    updateEnvelope();
    break;
  case 14: // LOW PASS filter frequency v
    //filtFreq = value/2.5*AUDIO_SAMPLE_RATE_EXACT/127.;
    lpfFreq = min(float(pow(value, 2)),10000);
    //filtFreq = float(pow(value, 3)/127.);
    updateLPF();
    break;
  case 15: // LOW PASS filter resonance v
    lpfReso = value*4.1/127.+0.9;
    updateLPF();
    break;
  case 18: // poly mode (using other poly mode)
    switch (value) {
    case 0:
      polyOn = true;
      portamentoOn = false;
      break;
    case 1:
      polyOn = false;
      portamentoOn = false;
      break;
    case 2:
      polyOn = false;
      portamentoOn = true;
      break;
    default: // cycle POLY, MONO, PORTAMENTO
    {
      bool tmp = polyOn;
      polyOn = portamentoOn;
      portamentoOn = !(tmp || portamentoOn);
      break;
    }
    }
    updatePolyMode();
    break;
  case 19: // envelope mode ?
    allOff();
    envOn = !envOn;
    updateEnvelopeMode();
    break;
  case 20: // delay idk
    envDelay = value*200./127.;
    updateEnvelope();
    break;
  case 21: // hold idk
    envHold = value*200./127.;
    updateEnvelope();
    break;
  case 22: // decay v 
    envDecay = value*200./127.;
    updateEnvelope();
    break;
  case 23: // sustain v
    envSustain = value/127.;
    updateEnvelope();
    break;
  case 24: // pulse width manual v
    pulseWidth = (value/127.)*0.9+0.05;
    updatePulseWidth();
    break;
  case 25: // flanger toggle
    if (value < 2)
        flangerOn = bool(value);
    else
        flangerOn = !flangerOn;
    updateFlanger();
    break;
  case 26: // flanger offset v
    flangerOffset = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case 27: // flanger depth v
    flangerDepth = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case 28: // flanger coarse frequency v
    flangerFreqCoarse = value/127.*10.;
    updateFlanger();
    break;
  case 29: // flanger fine frequency v
    flangerFreqFine = value/127.;
    updateFlanger();
    break;
  case 30: // pitch range in semitones v
    pitchScale = 12./value;
    break;
  case 64: // sustain/damper pedal ?
    if (value > 63) sustainPressed = true;
    else {
      sustainPressed = false;
      Oscillator *o=oscs, *end=oscs+NVOICES;
      do {
        if (o->note != -1 && !notesFind(notesPressed,o->note)) oscOff(*o);
      } while (++o < end);
    }
    break;
  case 65: // portamento on/off
    if (polyOn) break;
    if (value > 63) {
      portamentoOn = true;
      if (oscs->note != -1) portamentoPos = oscs->note;
    }
    else portamentoOn = false;
    break;
  case 75: //hpf frequency change
    hpfFreq = float(pow(value,2));
    updateHPF();
    break;
  case 76: //hpf resonance change
    hpfReso = value*4.1/127.+0.9;
    updateHPF();
    break;
  case 77: //FLANGER PRESETS
    switch (value) {
      case 0: //none
        break;
      case 1:
        flangerOffset     = DELAY_LENGTH/4;
        flangerDepth      = DELAY_LENGTH/16;
        flangerFreqCoarse = 0;
        flangerFreqFine   = .5;
      case 2:
        flangerOffset = 2*DELAY_LENGTH/4;
        flangerDepth = DELAY_LENGTH/4;
        flangerFreqCoarse = 3;
        flangerFreqFine = 0;
      case 3:
        flangerOffset = 3*DELAY_LENGTH/4;
        flangerDepth = DELAY_LENGTH/8;
        flangerFreqCoarse = 0.0625;
        flangerFreqFine = 0;
    }
    updateFlanger();
    break;
  case 84: // portamento control (start note)
    portamentoPos = value;
    break;
  case 85: // oscillator select
    if (value==0) {
      Serial.println("0 0");
      pulseOn = false; sawOn = false;
    } else if (value==1) {
      Serial.println("1 0");
        pulseOn = true; sawOn = false;
    } else if (value==2) {
      Serial.println("0 1");
        pulseOn = false; sawOn = true;
    } else if (value ==3) {
      Serial.println("1 1");
        pulseOn = true; sawOn = true;
    }
//    switch (value) {
//      case 0: // 0 0
//        Serial.println("0 0");
//        pulseOn = false; sawOn = false;
//        break;
//      case 1: // 1 0
//        Serial.println("1 0");
//        pulseOn = true; sawOn = false;
//      case 2: // 0 1
//        Serial.println("0 1");
//        pulseOn = false; sawOn = true;
//      case 3: // 1 1
//        Serial.println("1 1");
//        pulseOn = true; sawOn = true;
//    }
    break;
  case 86: // sub level
    subLevel = value/127.;
    updateOscVolume();
    break;
  case 87: // noise level
    noiseLevel = max(0.01,value/127.);
    updateOscVolume();
    break;
  case 88: //lpf env level v
    break;
  case 89: //lpf lfo level v
    break;
  case 90: //lpf keybd level v (modulation based on freq of note played)
    break;
  case 101: //lfo rate
    lfoRate = 30 * (pow((value/127.),2)); //curved scaling so it's easier to input lower frequencies
    updateLfo();
    break;
  case 102: //dco lfo level 
    oscLfoLevel = (pow((value/127.),2)); //curved scaling so it's easier to input lower frequencies
    updateOscLfo();
    break;
    
  case 121: // controller reset
    resetAll();
    break;
  case 123: // all notes off
    allOff();
    break;
  case 124: // omni off v
    allOff();
    omniOn = false;
    break; 
  case 125: // omni on v
    allOff();
    omniOn = true;
    break;
  case 126: // mono v
    polyOn = false;
    portamentoOn = false;
    updatePolyMode();
    break;
  case 127: // poly v
    polyOn = true;
    portamentoOn = false;
    updatePolyMode();
    break;
  default:
#if SYNTH_DEBUG > 0
    SYNTH_COM.print("Unhandled Control Change: channel ");
    SYNTH_COM.print(channel);
    SYNTH_COM.print(", control ");
    SYNTH_COM.print(control);
    SYNTH_COM.print(", value ");
    SYNTH_COM.println(value);
#endif
    break;
  }
#if 1 //0
  SYNTH_COM.print("Control Change: channel ");
  SYNTH_COM.print(channel);
  SYNTH_COM.print(", control ");
  SYNTH_COM.print(control);
  SYNTH_COM.print(", value ");
  SYNTH_COM.println(value);
#endif
}
