// set SYNTH_DEBUG to enable debug logging (0=off,1=most,2=all messages)
#define SYNTH_DEBUG 2

// define MIDI channel
#define SYNTH_MIDICHANNEL 1

// inital poly mode (POLY, MONO or PORTAMENTO)
#define SYNTH_INITIALMODE POLY

// define tuning of A4 in Hz
#define SYNTH_TUNING 440

// gain at oscillator/filter input stage (1:1)
// keep low so filter does not saturate with resonance
#define GAIN_OSC 0.5

// gain in final mixer stage for polyphonic mode (4:1)
// (0.25 is the safe value but larger sounds better :) )
//#define GAIN_POLY 1.
#define GAIN_POLY 0.25

// gain in final mixer stage for monophonic modes
//#define GAIN_MONO 1.
#define GAIN_MONO 0.25

// define delay lines for modulation effects
#define DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
short delaylineL[DELAY_LENGTH];
short delaylineR[DELAY_LENGTH];

// audio memory
#define AMEMORY 50

// switch between USB and UART MIDI
#if defined USB_MIDI || defined USB_MIDI_SERIAL
#define SYNTH_USBMIDI
#endif

#define SYNTH_COM Serial

MIDI_CREATE_DEFAULT_INSTANCE();

float   masterVolume   = 0.6;
//uint8_t currentProgram = WAVEFORM_SAWTOOTH;

bool  polyOn;
bool  omniOn;
bool  velocityOn;

bool  sustainPressed;
float channelVolume;
//float panorama;
float pulseWidth; // 0.05-0.95
float pitchBend;  // -1/+1 oct
float pitchScale;
int   octCorr;

// filter
//FilterMode_t filterMode;
float lpfFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float lpfReso; // 0.9-5.0
//float lpfAtt;  // 0-1

float hpfFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float hpfReso; // 0.9-5.0
//float hpfAtt;  // 0-1

// envelope
bool  envOn;
float envDelay;   // 0-200
float envAttack;  // 0-200
float envHold;    // 0-200
float envDecay;   // 0-200
float envSustain; // 0-1
float envRelease; // 0-200

// FX
bool  flangerOn;
int   flangerOffset;
int   flangerDepth;
float flangerFreqCoarse;
float flangerFreqFine;

// portamento
bool     portamentoOn;
uint16_t portamentoTime;
int8_t   portamentoDir;
float    portamentoStep;
float    portamentoPos;