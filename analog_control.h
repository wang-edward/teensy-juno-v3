// #include "pins.h"
void analogControl() {
//    if()
}

int readPot(int pin, double value) {
    int pos = analogRead(pin)/1023;
    if (pos != value) {
        return pos;
    }
    return -1;
}
