#include "DigitalPin.h"

DigitalPin::DigitalPin(volatile uint8_t* ddr, 
											 volatile uint8_t* port,
											 volatile uint8_t* pinReg, 
											 uint8_t bit)
				: ddr(ddr), port(port), pinReg(pinReg), bit(bit)
{
}

void DigitalPin::begin(PinMode mode)
{
	if(mode == PinMode::OUTPUT)
	{
		*ddr |= (1<<bit); 
	}else{
		*ddr &= ~(1<<bit); 
		
		if(mode == PinMode::INPUT_PULLUP)
			*port |= (1<<bit); 
		else
			*port &= ~(1<<bit); 
	}
}

void DigitalPin::write(bool value)
{
	if(value)
		*port |= (1<<bit); 
	else
		*port &= ~(1<<bit);
}

bool DigitalPin::read() const
{
	return (*pinReg & (1<<bit)) != 0;
}
