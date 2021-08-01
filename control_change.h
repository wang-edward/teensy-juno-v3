void OnControlChange(uint8_t channel, uint8_t control, uint8_t value) {
//  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;
  switch (control) {
  case 0: // bank select, do nothing (switch sounds via program change only)
    break;
  case 5: // portamento time
  {
    float portamentoRange = portamentoStep*portamentoTime;
    portamentoTime = value*50;
    portamentoStep = portamentoRange/portamentoTime;
    break;
  }
  case 7: // volume
    channelVolume = value/127.;
    updateVolume();
    break;
  case 9: // fix volume
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
//  case 10: // pan
//    panorama = value/127.;
//    updatePan();
//    break;
  case 12: // attack
    envAttack = value*200./127.;
    updateEnvelope();
    break;
  case 13: // release
    envRelease = value*200./127.;
    updateEnvelope();
    break;
  case 14: // LOW PASS filter frequency
    //filtFreq = value/2.5*AUDIO_SAMPLE_RATE_EXACT/127.;
    lpfFreq = float(pow(value, 2));
    //filtFreq = float(pow(value, 3)/127.);
    updateLPF();
    break;
  case 15: // LOW PASS filter resonance
    lpfReso = value*4.1/127.+0.9;
    updateLPF();
    break;
  case 18: // poly mode
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
  case 19: // envelope mode
    allOff();
    envOn = !envOn;
    updateEnvelopeMode();
    break;
  case 20: // delay
    envDelay = value*200./127.;
    updateEnvelope();
    break;
  case 21: // hold
    envHold = value*200./127.;
    updateEnvelope();
    break;
  case 22: // decay
    envDecay = value*200./127.;
    updateEnvelope();
    break;
  case 23: // sustain
    envSustain = value/127.;
    updateEnvelope();
    break;
  case 24: // pulse width
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
  case 26: // flanger offset
    flangerOffset = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case 27: // flanger depth
    flangerDepth = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case 28: // flanger coarse frequency
    flangerFreqCoarse = value/127.*10.;
    updateFlanger();
    break;
  case 29: // flanger fine frequency
    flangerFreqFine = value/127.;
    updateFlanger();
    break;
  case 30: // pitch range in semitones
    pitchScale = 12./value;
    break;
  case 64: // sustain/damper pedal
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
  case 84: // portamento control (start note)
    portamentoPos = value;
    break;
  case 121: // controller reset
    resetAll();
    break;
  case 123: // all notes off
    allOff();
    break;
  case 124: // omni off
    allOff();
    omniOn = false;
    break;
  case 125: // omni on
    allOff();
    omniOn = true;
    break;
  case 126: // mono
    polyOn = false;
    portamentoOn = false;
    updatePolyMode();
    break;
  case 127: // poly
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
