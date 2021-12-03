// #include "Arduino.h"
class Param {
    public:
        
        int value;
        int oldValue; // old value

    //static values
        int control; // midi control number
        int muxPos; // mux position to read from
        int muxNum; // which mux to read from
        double scalar; // amount to modify inputted value by
        
        void check() {
            if (value!=oldValue) {
                oldValue = read();
            } else {
                
            }
            if (read()!= oldValue) {

                }
                value = analogRead();
            
        }
        void update(void (*func) ()) {
            value = oldValue;
            func(value);
        }
        int updateOld() {
            oldValue = read();
        }
        int read() {
            return muxArr[muxNum].read(muxPos);
        }
};