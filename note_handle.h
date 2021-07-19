struct Oscillator {
  AudioSynthWaveform*  pulseLFO;
  AudioSynthWaveform*  saw;
  AudioSynthWaveform*  sub;
  AudioSynthNoiseWhite*          noise;

  AudioMixer4*                  oscMixer;
  
  AudioFilterStateVariable*     hpf;
  AudioFilterStateVariable*     lpf;

  AudioEffectEnvelope*          env;
  
  int8_t  note;
  uint8_t velocity;
};

#define NVOICES 8
Oscillator oscs[NVOICES] = {
  { &pulseLFO0, &saw0, &sub0, &noise0, &oscMixer0, &hpf0, &lpf0, &env0, -1, 0},
  { &pulseLFO1, &saw1, &sub1, &noise1, &oscMixer1, &hpf1, &lpf1, &env1, -1, 0},
  { &pulseLFO2, &saw2, &sub2, &noise2, &oscMixer2, &hpf2, &lpf2, &env2, -1, 0},
  { &pulseLFO3, &saw3, &sub3, &noise3, &oscMixer3, &hpf3, &lpf3, &env3, -1, 0},
  { &pulseLFO4, &saw4, &sub4, &noise4, &oscMixer4, &hpf4, &lpf4, &env4, -1, 0},
  { &pulseLFO5, &saw5, &sub5, &noise5, &oscMixer5, &hpf5, &lpf5, &env5, -1, 0},
  { &pulseLFO6, &saw6, &sub6, &noise6, &oscMixer6, &hpf6, &lpf6, &env6, -1, 0},
  { &pulseLFO7, &saw7, &sub7, &noise7, &oscMixer7, &hpf7, &lpf7, &env7, -1, 0},
};

int8_t notesOn[NVOICES]      = { -1, -1, -1, -1, -1, -1, -1, -1, };
int8_t notesPressed[NVOICES] = { -1, -1, -1, -1, -1, -1, -1, -1, };

inline void notesReset(int8_t* notes) {
  memset(notes,-1,NVOICES*sizeof(int8_t));
}

inline void notesAdd(int8_t* notes, uint8_t note) {
  int8_t *end=notes+NVOICES;
  do {
    if(*notes == -1) {
      *notes = note;
      break;
    }
  } while (++notes < end);
}

inline int8_t notesDel(int8_t* notes, uint8_t note) {
  int8_t lastNote = -1;
  int8_t *pos=notes, *end=notes+NVOICES;
  while (++pos < end && *(pos-1) != note);
  if (pos-1 != notes) lastNote = *(pos-2);
  while (pos < end) {
    *(pos-1) = *pos;
    if (*pos++ == -1) break;
  }
  if (*(end-1)==note || pos == end)
      *(end-1) = -1;
  return lastNote;
}

inline bool notesFind(int8_t* notes, uint8_t note) {
  int8_t *end=notes+NVOICES;
  do {
    if (*notes == note) return true;
  } while (++notes < end);
  return false;
}

inline float noteToFreq(float note) {
  // Sets all notes as an offset of A4 (#69)
//  if (portamentoOn) note = portamentoPos;     no portamento for now
//  return SYNTH_TUNING*pow(2,(note - 69)/12.+pitchBend/pitchScale+octCorr);
  return SYNTH_TUNING*pow(2,(note - 69)/12.); //no pitch bend for now
}
