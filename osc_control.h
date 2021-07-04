inline void oscOn(Oscillator& osc, int8_t note, uint8_t velocity) {
  float v = velocityOn ? velocity/127. : 1;
  if (osc.note!=note) {
    //set osc frequencies
    if (pulseOn) osc.pulseLFO->frequency(noteToFreq(note));
    if (sawOn) osc.saw->frequency(noteToFreq(note));
    
    notesAdd(notesOn,note);
    if (envOn && !osc.velocity) osc.env->noteOn();
    
    //turn oscillators on
    if (pulseOn) osc.pulseLFO->amplitude(v*channelVolume*GAIN_OSC);
    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    if (noiseOn) osc.noise->amplitude(v*channelVolume*GAIN_OSC);
    Serial.println(v*channelVolume*GAIN_OSC);
    osc.velocity = velocity;
    osc.note = note;
  } else if (velocity > osc.velocity) {
    //turn oscillators on
    if (pulseOn) osc.pulseLFO->amplitude(v*channelVolume*GAIN_OSC);
    if (sawOn) osc.saw->amplitude(v*channelVolume*GAIN_OSC);
    if (noiseOn) osc.noise->amplitude(v*channelVolume*GAIN_OSC);
    osc.velocity = velocity;
  }
}

inline void oscOff(Oscillator& osc) {
  if (envOn) osc.env->noteOff();
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
