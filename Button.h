#pragma once
#include "DigitalPin.h"
#include <util/delay.h>
#include <stdint.h>

template<uint16_t debounceDelay = 20>
class Button {
private:
    DigitalPin& pin;

public:
    Button(DigitalPin& pin_) : pin(pin_) {}

    bool isPressed() const {
        if (!pin.read()) {           
            _delay_ms(debounceDelay); 
            return !pin.read();       
        }
        return false;                 
    }
    
    DigitalPin& getPin() const{
    	return this->pin;
    }
};
