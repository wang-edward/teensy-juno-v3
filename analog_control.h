#include "global_variables.h"
#include "pins.h"
void analogControl() {
    if (analogRead(channelVolumePin)/127 != channelVolume) {
        onControlChange(0,7)
    }
}