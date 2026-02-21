#pragma once
#include<avr/io.h>

enum class PinMode {INPUT, OUTPUT, INPUT_PULLUP}; 

class DigitalPin{
private: 

	//input or output pin
	volatile uint8_t* ddr; 
	
	//to write on the pin
	volatile uint8_t* port; 
	
	//for reading pin
	volatile uint8_t* pinReg; 
	
	uint8_t bit; 

public:
	DigitalPin(volatile uint8_t* ddr,
						 volatile uint8_t* port,
						 volatile uint8_t* pinReg, 
						 uint8_t bit); 
	
	void begin(PinMode mode); 
	void write(bool value); 
	bool read() const; 
	void toggle();


};
