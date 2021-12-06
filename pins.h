//int channelVolumePin = 14;
//pinMode(channelVolumePin, INPUT);
Mux muxArray[] = {
    Mux(Pin(24, INPUT, PinType::Analog),Pinset(29,30,31,32)), 
    Mux(Pin(25, INPUT, PinType::Analog),Pinset(29,30,31,32)),
    Mux(Pin(26, INPUT, PinType::Analog),Pinset(29,30,31,32))
};
