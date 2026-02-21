#define F_CPU 16000000UL       // definisce la frequenza CPU per _delay_ms
#include <avr/io.h>
#include <util/delay.h>
#include "DigitalPin.h"        // includiamo l’header della classe

// ----- Pin definiti -----
DigitalPin led(&DDRD, &PORTD, &PIND, 4);     // PD4 = LED
DigitalPin button(&DDRD, &PORTD, &PIND, 3);  // PD3 = Bottone

int main() {
    // Configurazione pin
    led.begin(PinMode::OUTPUT);
    button.begin(PinMode::INPUT_PULLUP);

    while (1) {
        // Leggi bottone
        if (button.read()) {    // LOW = premuto (pull-up attivo)
            led.write(true);     // accendi LED
        } else {
            led.write(false);    // spegni LED
        }

        _delay_ms(20);           // piccolo debounce
    }

    return 0;
}
