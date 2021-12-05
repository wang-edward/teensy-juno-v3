#include <Mux.h>


using namespace admux;
extern Mux mux_array[] = {
    Mux(Pin(24, INPUT, PinType::Analog),Pinset(29,30,31,32)), 
    Mux(Pin(25, INPUT, PinType::Analog),Pinset(29,30,31,32)),
    Mux(Pin(26, INPUT, PinType::Analog),Pinset(29,30,31,32))
};

const int num_params = 22;

const int DELAY_LENGTH = 1;

//virtual params

parameter hpf_resonance (76, -1, -1, [](int value) -> int {
    return value*4.1/127.+0.9;
});

parameter lpf_mod_wheel_level (1, -1, -1, [](int value) -> int {
    return (value/127.)*2;
});

//REAL PARAMS

parameter master_volume (8, 1, 8, [](int value) -> int {
    return value/127.;
});

parameter lfo_rate (101, 0, 0, [](int value) -> int {
    return 30 * (pow((value/127.),2));
});

parameter lfo_delay (104, 0, 1, [](int value) -> int {
    return 2000 * (pow((value/127.),2));
});

parameter osc_lfo_level (102, 0, 2, [](int value) -> int {
    return (pow((value/127.),2));
});

parameter pulse_width (24, 0, 3, [](int value) -> int {
    return (value/127.)*0.9+0.05;
});

parameter sub_level (86, 0, 4, [](int value) -> int {
    return value/127.;
});

parameter noise_level (87, 0, 5, [](int value) -> int {
    return max(0.01,value/127.);
});




parameter hpf_frequency (75, 0, 6, [](int value) -> int {
    return pow(value,2);
});

// 20-AUDIO_SAMPLE_RATE_EXACT/2.5
parameter lpf_frequency (14, 0, 7, [](int value) -> int {
    return std::min((int)(pow(value,2)),10000);
});

// 0.9-5.0
parameter lpf_resonance (15, 0, 8, [](int value) -> int {
    return value*4.1/127.+0.9;
});

parameter lpf_env_level (88, 0, 9, [](int value) -> int {
    return (value/127.) * 2;
});

parameter lpf_lfo_level (89, 0, 10, [](int value) -> int {
    return (value/127.) * 2;
});

parameter lpf_keyboard_level (90, 0, 11, [](int value) -> int {
    return (value/127.) * 2;
});

parameter channel_volume (7, 0, 12, [](int value) -> int {
    return value/127.;
});

parameter flanger_offset(26, 0, 13, [](int value) -> int {
    return int(value/127.*8)*DELAY_LENGTH/8;
});

parameter flanger_depth(27, 0, 14, [](int value) -> int {
    return int(value/127.*8)*DELAY_LENGTH/8;
});

parameter flanger_frequency(28, 0, 15, [](int value) -> int {
    return value/127.*10.;
});

parameter flanger_frequency_fine(29, 1, 0, [](int value) -> int {
    return value/127.;
});

parameter envelope_attack(12, 1, 1, [](int value) -> int {
    return 1000 * (pow((value/127.),2));
});

parameter envelope_decay(22, 1, 2, [](int value) -> int {
    return value*200./127.;
});

parameter envelope_sustain(22, 1, 3, [](int value) -> int {
    return value/127.;
});

parameter envelope_release(13, 1, 4, [](int value) -> int {
    return 1000 * (pow((value/127.),2));
});
