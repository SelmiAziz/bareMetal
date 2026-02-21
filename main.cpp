#define F_CPU 16000000UL
#include <avr/io.h>
#include "DigitalPin.h"
#include "Led.h"
#include "Button.h"

// ----- Pin definitions -----
DigitalPin ledPin(&DDRD, &PORTD, &PIND, 4);      // PD4 = LED
DigitalPin buttonPin(&DDRD, &PORTD, &PIND, 3);   // PD3 = Button

Led led(ledPin);
Button<30> button(buttonPin);   // debounce = 30 ms (compile-time)

int main() {
    // Configure pins
    ledPin.begin(PinMode::OUTPUT);
    buttonPin.begin(PinMode::INPUT_PULLUP);

    while (1) {
        if (button.getPin().read()) {
            led.on();        // toggle LED on each press
        }else{
        	led.off();
        }
        // no _delay_ms() here; debounce handled by Button template
    }

    return 0;
}
