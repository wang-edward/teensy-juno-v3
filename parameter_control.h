inline void updateHPF() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->hpf->frequency(hpfFreq);
    o->hpf->resonance(hpfReso);
  } while (++o < end);
}

inline void updateLPF() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpf->frequency(lpfFreq);
    o->lpf->resonance(lpfReso);
  } while (++o < end);
}

inline void updateSumLpfLevels() {
  sumLpfLevels = lpfEnvLevel + lpfLfoLevel + lpfKbdLevel + lpfModWheelLevel;
}

inline void calcMaxLpfMod() {
  maxLpfMod = log(20000/lpfFreq)/(lpfOctaveControl * log(2));
}

//inline float calcModLevel(float levelIn) {
//  updateSumLpfLevels(); //14.28 is log base 2 of 20k (upper bound)
//  return min((levelIn / sumLpfLevels) * (14.2877123 - (log(lpfFreq) / log(2)) / lpfOctaveControl), levelIn);
//}

inline void updateLpfEnvLevel() {
  lpfEnvGain = lpfEnvLevel/sumLpfLevels * maxLpfMod;

  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpfModMixer->gain(0,lpfEnvGain);
  } while (++o < end);
}

inline void updateLpfLfoLevel() {
  lpfLfoGain = lpfLfoLevel/sumLpfLevels * maxLpfMod;
  
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpfModMixer->gain(1,lpfLfoGain);
  } while (++o < end);
}

inline void updateLpfKbdLevel() {
  lpfKbdGain = lpfKbdLevel/sumLpfLevels * maxLpfMod;
  
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpfModMixer->gain(2,lpfKbdGain);
  } while (++o < end);
}

inline void updateLpfModWheelLevel() {
  lpfModWheelGain = lpfModWheelLevel/sumLpfLevels * maxLpfMod;
  
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lpfModMixer->gain(3,lpfModWheelGain);
  } while (++o < end);
}

inline void debugLpf() {
  Serial.print("env: "); Serial.println(lpfEnvGain);
  Serial.print("lfo: "); Serial.println(lpfLfoGain);
  Serial.print("kbd: "); Serial.println(lpfKbdGain);
  Serial.print("mod: "); Serial.println(lpfModWheelGain);
}

inline void updateLpfMod() {
  calcMaxLpfMod();
  updateSumLpfLevels();
  updateLpfEnvLevel();
  updateLpfLfoLevel();
  updateLpfKbdLevel();
  updateLpfModWheelLevel();
  
//  debugLpf();
}


inline void updateEnvelope() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
//    o->env->delay(envDelay);
    o->env->attack(envAttack);
//    o->env->hold(envHold);
    o->env->decay(envDecay);
    o->env->sustain(envSustain);
    o->env->release(envRelease);
      o->lpfEnv->attack(envAttack);
      o->lpfEnv->decay(envDecay);
      o->lpfEnv->sustain(envSustain);
      o->lpfEnv->release(envRelease);
  } while (++o < end);
}

inline void updateEnvelopeMode() {
// float env    = envOn ? 1 : 0;
// float noenv  = envOn ? 0 : 1;
// for (uint8_t i=0; i<2; ++i) {
//   // env
//   EnvMixer0.gain(i,env);
//   EnvMixer1.gain(i,env);
//   EnvMixer2.gain(i,env);
//   EnvMixer3.gain(i,env);
//
//   // no env
//   EnvMixer0.gain(i+2,noenv);
//   EnvMixer1.gain(i+2,noenv);
//   EnvMixer2.gain(i+2,noenv);
//   EnvMixer3.gain(i+2,noenv);
// }
}

void updateFlanger() {
  if (flangerOn) {
    AudioNoInterrupts();
    Serial.print("offset: "); Serial.println(flangerOffset);
    Serial.print("depth: "); Serial.println(flangerDepth);
    Serial.print("freqCoarse: "); Serial.println(flangerFreqCoarse);
    Serial.print("freqFine: "); Serial.println(flangerFreqFine);
    flangerL.voices(flangerOffset,flangerDepth,flangerFreqCoarse+flangerFreqFine);
    flangerR.voices(flangerOffset,flangerDepth,flangerFreqCoarse+flangerFreqFine);
    AudioInterrupts();
#if SYNTH_DEBUG > 0
    SYNTH_COM.print("Flanger: offset=");
    SYNTH_COM.print(flangerOffset);
    SYNTH_COM.print(", depth=");
    SYNTH_COM.print(flangerDepth);
    SYNTH_COM.print(", freq=");
    SYNTH_COM.println(flangerFreqCoarse+flangerFreqFine);
    SYNTH_COM.println(FLANGE_DELAY_PASSTHRU);
#endif
  } else {
    //noflange
    flangerL.voices(FLANGE_DELAY_PASSTHRU,0,0);
    flangerR.voices(FLANGE_DELAY_PASSTHRU,0,0);
  }
}

//!update
inline void updatePulseWidth() {
//  if (currentProgram!=WAVEFORM_PULSE) return;

  if (pwmLfoOn) {
    //amount of lfo mod gets controlled by pwm slider
    pwmMixer.gain(0,pulseWidth); //set lfo pwm
    pwmMixer.gain(1,0); // turn off manual pwm
  } else {
    //manually set pulse width
    pwmMixer.gain(1,pulseWidth);
    pwmMixer.gain(0,0); // turn off manual pwm
  }
  
//  Oscillator *o=oscs,*end=oscs+NVOICES;
//  do {
//    if (o->note < 0) continue;
//    o->pulseLFO->pulseWidth(pulseWidth);
//  } while(++o < end);
}

inline void updateLfo() {
  lfo.frequency(lfoRate);
}

inline void updateLfoDelay() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    o->lfoEnv->delay(lfoDelay);
  } while(++o < end);
}

inline void updateOscLfo() {
  oscLfoAmp.gain(oscLfoLevel);
}

inline void updatePitch() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    if (o->note < 0) continue;
    if (pulseOn) o->pulseLFO->frequency(noteToFreq(o->note));
    if (sawOn) o->saw->frequency(noteToFreq(o->note));
  } while(++o < end);
}

inline void updateOscOn (byte value) {
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
}

inline void updateOscVolume() {
  if (subLevel>0) {
    Oscillator *o=oscs,*end=oscs+NVOICES;
    float velocity;
    do {
      if (o->note < 0) continue;
      velocity = velocityOn ? o->velocity/127. : 1;
      o->sub->amplitude(velocity*channelVolume*GAIN_OSC*subLevel);
    } while(++o < end);
  }
  if (noiseLevel>0) {
    Oscillator *o=oscs,*end=oscs+NVOICES;
    float velocity;
    do {
      if (o->note < 0) continue;
      velocity = velocityOn ? o->velocity/127. : 1;
      o->noise->amplitude(velocity*channelVolume*GAIN_OSC*noiseLevel);
    } while(++o < end);
  }
}

inline void updateVolume() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  float velocity;
  do {
    if (o->note < 0) continue;
    velocity = velocityOn ? o->velocity/127. : 1;
    if (pulseOn) o->pulseLFO->amplitude(velocity*channelVolume*GAIN_OSC);
    if (sawOn) o->saw->amplitude(velocity*channelVolume*GAIN_OSC);
  } while(++o < end);
}

inline void updateMasterVolume() {
  // read the volume knob
  float vol = (float) analogRead(A1) / 1280.0;
  if( fabs(vol-masterVolume) > 0.01) {
    masterVolume = vol;
    sgtl5000_1.volume(masterVolume);
#if SYNTH_DEBUG > 0
    SYNTH_COM.print("Volume: ");
    SYNTH_COM.println(vol);
#endif
  }
}

inline void updatePan() {
  float norm  = (polyOn && !portamentoOn) ? GAIN_POLY : GAIN_MONO;
  float left=norm, right=norm;
  if (panorama < 0.5) right *= 2*panorama;
  else left *= 2*(1-panorama);

  for (uint8_t i=0; i<4; ++i) {
    mixerL.gain(i,left);
    mixerR.gain(i,right);
  }
}

inline void updatePolyMode() {
  allOff();
  updateEnvelopeMode();
  updatePan();
}

inline void updatePortamento()
{
//  Serial.print("portamento pos:"); Serial.println(portamentoPos);
//  Serial.print("portamento dir:"); Serial.println(portamentoDir);
//  Serial.print("portamento time:"); Serial.println(portamentoTime);
//  Serial.print("portamento step:"); Serial.println(portamentoStep);
  if (portamentoDir == 0) return;
  if (oscs->note < 0) {
    portamentoDir = 0;
    return;
  }
  if (portamentoDir < 0) {
    portamentoPos -= portamentoStep;
    if (portamentoPos < oscs->note) {
      portamentoPos = oscs->note;
      portamentoDir = 0;
    }
  }
  else {
    portamentoPos += portamentoStep;
    if (portamentoPos > oscs->note) {
      portamentoPos = oscs->note;
      portamentoDir = 0;
    }
  }
  if (pulseOn)oscs->pulseLFO->frequency(noteToFreq(portamentoPos));
  if (sawOn)oscs->saw->frequency(noteToFreq(portamentoPos));
  if (subLevel>0)oscs->sub->frequency(noteToFreq(portamentoPos));
}

void resetAll() {
  polyOn     = true;
  omniOn     = false;
  velocityOn = true;

//  sawOn = true;
//  pulseOn = true;
//  noiseLevel = 1;
//  subLevel = 1;

//  filterMode     = FILTEROFF;
  sustainPressed = false;
  channelVolume  = 1.0;
  panorama       = 0.5;
  pulseWidth     = 0.5;
  pitchBend      = 0;
  pitchScale     = 1;
//  octCorr        = currentProgram == WAVEFORM_PULSE ? 1 : 0;

  // filter
  lpfFreq = 10000.;
  lpfReso = 0.9;
//  lpfAtt  = 1.;
  hpfFreq = 50.;
  hpfReso = 0.9;

  // envelope
  envOn      = true;
  envDelay   = 0;
  envAttack  = 20;
  envHold    = 0;
  envDecay   = 0;
  envSustain = 1;
  envRelease = 0;

  // FX
  flangerOn         = false;
  flangerOffset     = DELAY_LENGTH/4;
  flangerDepth      = DELAY_LENGTH/16;
  flangerFreqCoarse = 0;
  flangerFreqFine   = .5;

  // portamento
  portamentoOn   = false;
  portamentoTime = 1000;
  portamentoDir  = 0;
  portamentoStep = 0;
  portamentoPos  = -1;

  updatePolyMode();
  updateFlanger();
//  updateFilterMode();
  updateEnvelope();
//  updatePan();
}

inline void updatePreset(Preset preset) {
  polyOn = preset.polyOn;
  omniOn = preset.omniOn;
  velocityOn = preset.velocityOn;

  pulseOn = preset.pulseOn;
  sawOn = preset.sawOn;
//  noiseOn = preset.sawOn;
//  subOn = preset.subOn;
  
  pwmLfoOn = preset.pwmLfoOn;

  lfoRate = preset.lfoRate;
  lfoDelay = preset.lfoDelay;
  pulseWidth = preset.pulseWidth;
  oscLfoLevel = preset.oscLfoLevel;
  noiseLevel = preset.noiseLevel;
  subLevel = preset.subLevel;

//  sustainPressed = preset.sustainPressed;
  channelVolume = preset.channelVolume;
  panorama = preset.panorama;
  pitchBend = preset.pitchBend; // do this
  octCorr = preset.octCorr; // do this

  lpfFreq = preset.lpfFreq;
  lpfReso = preset.lpfReso;
  lpfLfoLevel = preset.lpfLfoLevel;
  lpfEnvLevel = preset.lpfEnvLevel;
  lpfKbdLevel = preset.lpfKbdLevel;
  lpfModWheelLevel = preset.lpfModWheelLevel;

  lpfOctaveControl = preset.lpfOctaveControl;
//  sumLpfLevels = preset.sumLpfLevels;
//  maxLpfMod = preset.maxLpfMod;

  //updateHpf()
  hpfFreq = preset.hpfFreq;
  hpfReso = preset.hpfReso;

  //updateEnvelope()
  envOn = preset.envOn;
  envDelay = preset.envDelay;
  envAttack = preset.envAttack;
  envHold = preset.envHold;
  envDecay = preset.envDecay;
  envSustain = preset.envSustain;
  envRelease = preset.envRelease;

  //updateFlanger()
  flangerOn = preset.flangerOn;
  flangerOffset = preset.flangerOffset;
  flangerDepth = preset.flangerOffset;
  flangerFreqCoarse = preset.flangerFreqCoarse;
  flangerFreqFine = preset.flangerFreqFine;

  //updatePortamento()
  portamentoOn = preset.portamentoOn;
  portamentoTime = preset.portamentoTime;
  portamentoDir = preset.portamentoDir;
  portamentoStep = preset.portamentoStep;
  portamentoPos = preset.portamentoPos;

  updatePolyMode(); //idk lol
//  updateOscOn();
  updateLfo();
  updateLfoDelay();
  updatePulseWidth();
  updateOscVolume();
  updatePan();
  //pitch bend and octCorr
  updateLPF();

  updateLpfMod(); // calcs max, updates sum, updates 4 input levels
  updateHPF();
  
  updateEnvelope(); // env and lpf env
  
  updateFlanger();
  
  updatePortamento();
}

//#define MAX_FILE_SIZE 1024
//#define JSON_BUFFER_SIZE 200
//
//inline void loadPreset () {
//  //write -----
////  File file = SD.open(preset_data.json, FILE_WRITE);
////  DynamicJsonDocument<256> doc;
////  doc["hello"] = "world";
////  serializeJson(doc, file);
////  file.close();
//
//
//  char json[MAX_FILE_SIZE];
//  readFile("gg.json", json, MAX_FILE_SIZE);
//
//  Serial.println(json); // <- SHOW ME THE OUTPUT OF THIS!!!!!
//
//  StaticJsonBuffer<JSON_BUFFER_SIZE> jsonBuffer;
//}
//
//void readFile(const char *fileName, char *buffer, size_t maxSize) {
//  File file = SD.open(fileName, FILE_READ);
//  file.readBytes(buffer, maxSize);
//  file.close();
//}

//inline void updateFilterMode() {
//  Serial.print("FILTER MODE");
//  Oscillator *o=oscs,*end=oscs+NVOICES;
//  do {
//    for (uint8_t fm=0; fm<FILTERMODE_N; ++fm) {
//      if (fm == filterMode) o->mix->gain(fm,filtAtt);
//      else                  o->mix->gain(fm,0);
//    }
//  } while (++o < end);
//}

//inline void updateFilter() {
//  Oscillator *o=oscs,*end=oscs+NVOICES;
//  do {
//    o->filt->frequency(filtFreq);
//    o->filt->resonance(filtReso);
//  } while (++o < end);
//}
