inline void oscOn(Oscillator& osc, int8_t note, uint8_t velocity) {
  float v = velocityOn ? velocity/127. : 1;
  float freq = noteToFreq(note);
  float amp = v*channelVolume*GAIN_OSC;
  if (osc.note!=note) {
//    //set osc frequencies
//    if (pulseOn) osc.pulseLFO->frequency(noteToFreq(note));
//    if (sawOn) osc.saw->frequency(noteToFreq(note));
//    
//    notesAdd(notesOn,note);
//    if (envOn && !osc.velocity) osc.env->noteOn();
//    
//    //turn oscillators on
//    if (pulseOn) osc.pulseLFO->amplitude(v*channelVolume*GAIN_OSC);
//    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
//    if (noiseOn) osc.noise->amplitude(v*channelVolume*GAIN_OSC);
////    if (subOn) osc.sub->amplitude

    notesAdd(notesOn,note);
    if (envOn && !osc.velocity) osc.env->noteOn();

    if (pulseOn) {
      osc.pulseLFO->frequency(freq);
      osc.pulseLFO->amplitude(amp);
    }
    if (sawOn) {
      osc.saw->frequency(freq);
      osc.saw->amplitude(amp);
    }
    if (subLevel>0) {
      osc.sub->frequency(freq/2);
      osc.sub->amplitude(amp * subLevel);
    }
    if (noiseLevel>0) {
      osc.noise->amplitude(amp * noiseLevel);
    }

    Serial.print("oscialltor volume: ");
    Serial.println(amp);
    Serial.print("sub volume: ");
    Serial.println(amp*subLevel);
    Serial.print("noise volume: ");
    Serial.println(amp*noiseLevel);
    if (pulseOn) Serial.println("pulseON");
    if (sawOn) Serial.println("SAWON");
    
    osc.velocity = velocity;
    osc.note = note;
  } else if (velocity > osc.velocity) {
    //turn oscillators on
    if (pulseOn) osc.pulseLFO->amplitude(amp);
    if (sawOn) osc.saw->amplitude(amp);
    if (subLevel>0) osc.sub->amplitude(amp * subLevel);
    if (noiseLevel>0) osc.noise->amplitude(amp * noiseLevel);
    osc.velocity = velocity;
  }
}

inline void oscOff(Oscillator& osc) {
  Serial.println("OSCOFFFFF");
  if (envOn) {
    osc.env->noteOff();
    Serial.println("ENV NOTE OFF");
  }
  else {
    //turn oscillators off
    if (pulseOn) osc.pulseLFO->amplitude(0);
    if (sawOn) osc.saw->amplitude(0);
    if (noiseOn) osc.noise->amplitude(0);
  }
  notesDel(notesOn,osc.note);
  osc.note = -1;
  osc.velocity = 0;
}

inline void allOff() {
  Oscillator *o=oscs,*end=oscs+NVOICES;
  do {
    oscOff(*o);
    o->pulseLFO->amplitude(0);
    o->saw->amplitude(0);
    o->noise->amplitude(0);
    o->env->noteOff();
  } while(++o < end);
  notesReset(notesOn);
}
