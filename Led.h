#pragma once
#include "DigitalPin.h"
#include <util/delay.h>
#include <stdint.h>

class Led {
private:
    DigitalPin& pin;

public:
    Led(DigitalPin& pin_) : pin(pin_) {}

    void on() { pin.write(true); }
    void off() { pin.write(false); }
    void toggle() { pin.toggle(); }

    // template blink
    template<uint16_t delay_ms>
    void blink() {
        toggle();
        _delay_ms(delay_ms); // compile-time constant
    }
};
