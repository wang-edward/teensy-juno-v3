struct Preset {
    byte position;

    bool polyOn;
    bool omniOn;
    bool velocityOn;

    bool pulseOn;
    bool sawOn;
    bool noiseOn;
    bool subOn;

    bool pwmLfoOn;
    
    float lfoRate;
    float lfoDelay; 
    float pulseWidth; 
    float oscLfoLevel;
    float noiseLevel;
    float subLevel;

    bool  sustainPressed;
    float channelVolume;
    float panorama;
    float pitchBend;
    float pitchScale;
    int   octCorr;

    float lpfFreq; 
    float lpfReso; 
    float lpfLfoLevel; 
    float lpfEnvLevel; 
    float lpfKbdLevel; 
    float lpfModWheelLevel; 

    float lpfOctaveControl;
    float sumLpfLevels; 
    float maxLpfMod;

    float hpfFreq; 
    float hpfReso;

    bool  envOn;
    float envDelay;    
    float envAttack;   
    float envHold;     
    float envDecay;    
    float envSustain;
    float envRelease;  

    bool  flangerOn;
    int   flangerOffset;
    int   flangerDepth;
    float flangerFreqCoarse;
    float flangerFreqFine;

    bool     portamentoOn = false;
    uint16_t portamentoTime;
    int8_t   portamentoDir;
    float    portamentoStep;
    float    portamentoPos;
};

