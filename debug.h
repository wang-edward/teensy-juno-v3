//#if SYNTH_DEBUG > 0
float   statsCpu = 0;
uint8_t statsMem = 0;

void oscDump(uint8_t idx) {
  SYNTH_COM.print("Oscillator ");
  SYNTH_COM.print(idx);
//  oscDump(oscs[idx]);
}

void oscDump(const Oscillator& o) {
  SYNTH_COM.print(" note=");
  SYNTH_COM.print(o.note);
  SYNTH_COM.print(", velocity=");
  SYNTH_COM.println(o.velocity);
}

inline void notesDump(int8_t* notes) {
  for (uint8_t i=0; i<NVOICES; ++i) {
    SYNTH_COM.print(' ');
    SYNTH_COM.print(notes[i]);
  }
  SYNTH_COM.println();
}

inline void printResources( float cpu, uint8_t mem) {
  SYNTH_COM.print( "CPU Usage: ");
  SYNTH_COM.print(cpu);
  SYNTH_COM.print( "%, Memory: ");
  SYNTH_COM.println(mem);
}

void performanceCheck() {
  static unsigned long last = 0;
  unsigned long now = millis();
  if ((now-last)>1000) {
    last = now;
    float cpu = AudioProcessorUsageMax();
    uint8_t mem = AudioMemoryUsageMax();
    if( (statsMem!=mem) || fabs(statsCpu-cpu)>1) {
      printResources( cpu, mem);
    }
    AudioProcessorUsageMaxReset();
    AudioMemoryUsageMaxReset();
    last = now;
    statsCpu = cpu;
    statsMem = mem;
  }
}

void printInfo() {
  SYNTH_COM.println();
  SYNTH_COM.print("Master Volume:        ");
  SYNTH_COM.println(masterVolume);
//  SYNTH_COM.print("Current Program:      ");
//  SYNTH_COM.println(currentProgram);
  SYNTH_COM.print("Poly On:              ");
  SYNTH_COM.println(polyOn);
  SYNTH_COM.print("Omni On:              ");
  SYNTH_COM.println(omniOn);
  SYNTH_COM.print("Velocity On:          ");
  SYNTH_COM.println(velocityOn);
  SYNTH_COM.println();
  SYNTH_COM.print("Sustain Pressed:      ");
  SYNTH_COM.println(sustainPressed);
  SYNTH_COM.print("Channel Volume:       ");
  SYNTH_COM.println(channelVolume);
  SYNTH_COM.print("Panorama:             ");
  SYNTH_COM.println(panorama);
  SYNTH_COM.print("Pulse Width:          ");
  SYNTH_COM.println(pulseWidth);
  SYNTH_COM.print("Pitch Bend:           ");
  SYNTH_COM.println(pitchBend);
  SYNTH_COM.println();
  SYNTH_COM.print("Filter Mode:          ");
//  SYNTH_COM.println(filterMode);
//  SYNTH_COM.print("Filter Frequency:     ");
//  SYNTH_COM.println(filtFreq);
//  SYNTH_COM.print("Filter Resonance:     ");
//  SYNTH_COM.println(filtReso);
//  SYNTH_COM.print("Filter Attenuation:   ");
//  SYNTH_COM.println(filtAtt);
  SYNTH_COM.println();
  SYNTH_COM.print("Envelope On:          ");
  SYNTH_COM.println(envOn);
  SYNTH_COM.print("Envelope Delay:       ");
  SYNTH_COM.println(envDelay);
  SYNTH_COM.print("Envelope Attack:      ");
  SYNTH_COM.println(envAttack);
  SYNTH_COM.print("Envelope Hold:        ");
  SYNTH_COM.println(envHold);
  SYNTH_COM.print("Envelope Decay:       ");
  SYNTH_COM.println(envDecay);
  SYNTH_COM.print("Envelope Sustain:     ");
  SYNTH_COM.println(envSustain);
  SYNTH_COM.print("Envelope Release:     ");
  SYNTH_COM.println(envRelease);
  SYNTH_COM.println();
  SYNTH_COM.print("Flanger On:           ");
  SYNTH_COM.println(flangerOn);
  SYNTH_COM.print("Flanger Offset:       ");
  SYNTH_COM.println(flangerOffset);
  SYNTH_COM.print("Flanger Depth:        ");
  SYNTH_COM.println(flangerDepth);
  SYNTH_COM.print("Flanger Freq. Coarse: ");
  SYNTH_COM.println(flangerFreqCoarse);
  SYNTH_COM.print("Flanger Freq. Fine:   ");
  SYNTH_COM.println(flangerFreqFine);
  SYNTH_COM.print("Delay Line Length:    ");
  SYNTH_COM.println(DELAY_LENGTH);
  SYNTH_COM.println();
  SYNTH_COM.print("Portamento On:        ");
  SYNTH_COM.println(portamentoOn);
  SYNTH_COM.print("Portamento Time:      ");
  SYNTH_COM.println(portamentoTime);
  SYNTH_COM.print("Portamento Step:      ");
  SYNTH_COM.println(portamentoStep);
  SYNTH_COM.print("Portamento Direction: ");
  SYNTH_COM.println(portamentoDir);
  SYNTH_COM.print("Portamento Position:  ");
  SYNTH_COM.println(portamentoPos);
}

void printAbout()
{
  SYNTH_COM.println();
  SYNTH_COM.println("TeensySynth v0.1");
#ifdef SYNTH_USBMIDI
  SYNTH_COM.println("USB_MIDI enabled");
#endif
  SYNTH_COM.println("UART_MIDI enabled");
}

void selectCommand(char c) {
  switch (c) {
  case '\r':
    SYNTH_COM.println();
    break;
  case 'b':
    // print voice statistics
    SYNTH_COM.print("Notes Pressed:");
    notesDump(notesPressed);
    SYNTH_COM.print("Notes On:     ");
    notesDump(notesOn);
    break;
  case 'o':
    // print oscillator status
    for (uint8_t i=0; i<NVOICES; ++i)
        oscDump(i);
    break;
  case 's':
    // print cpu and mem usage
    printResources(statsCpu,statsMem);
    break;
  case 'r':
    // reset parameters
    resetAll();
    break;
  case 'i':
    // print info
    printInfo();
    break;
  case '?':
    // print about
    printAbout();
    break;
  case '\t':
    // reboot Teensy
    *(uint32_t*)0xE000ED0C = 0x5FA0004;
    break;
  case ' ':
    // send note off
    allOff();
    break;
  default:
    break;
  }
}

//inline void printResources( float cpu, uint8_t mem) {
//  SYNTH_COM.print( "CPU Usage: ");
//  SYNTH_COM.print(cpu);
//  SYNTH_COM.print( "%, Memory: ");
//  SYNTH_COM.println(mem);
//}
//
//void performanceCheck() {
//  static unsigned long last = 0;
//  unsigned long now = millis();
//  if ((now-last)>1000) {
//    last = now;
//    float cpu = AudioProcessorUsageMax();
//    uint8_t mem = AudioMemoryUsageMax();
//    if( (statsMem!=mem) || fabs(statsCpu-cpu)>1) {
//      printResources( cpu, mem);
//    }
//    AudioProcessorUsageMaxReset();
//    AudioMemoryUsageMaxReset();
//    last = now;
//    statsCpu = cpu;
//    statsMem = mem;
//  }
//}
