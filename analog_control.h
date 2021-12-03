// #include "pins.h"

Mux[] muxArr = {
    Mux mux0(Pin(24, INPUT, PinType::Analog),Pinset(29,30,31,32)), 
    Mux mux1(Pin(25, INPUT, PinType::Analog),Pinset(29,30,31,32)),
    Mux mux2(Pin(26, INPUT, PinType::Analog),Pinset(29,30,31,32));
};



void analogControl() {
    int temp = simpleReadPot(0,1) * (pow((value/1023.),2));
    if (lfoRate!=temp) {
        
    }
    
    readPot(0, 0, lfoRate, 30 * (pow((value/1023.),2)), updateLfo());
    readPot(0, 1, lfoDelay, 2000 * (pow((value/1023.),2)), updateLfoDelay());
    readPot(0, 2, oscLfoLevel, (pow((value/1023.),2)), updateOscLfo());
    readPot(0, 3, pulseWidth, value,1023);


  int data = (1023-mux.read(0))/8;

}

int simpleReadPot(int muxNum, int muxPos) {
    return muxArr[muxNum].read(muxPos);
}

int readPot(int muxNum, int muxPos, int parameter, int scalar, void (*updateFunc)()) {
    int pos = muxArr[muxNum].read(muxPos);
    parameter = pos * scalar;
    updateFunc();
}

// int readPot(int pin, double value) {
//     int pos = analogRead(pin)/1023;
//     if (pos != value) {
//         return pos;
//     }
//     return -1;
// }