MCU = atmega328p
F_CPU = 16000000UL

CC = avr-g++
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

TARGET = main_cpp

# Source files
SOURCES = main.cpp DigitalPin.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET).hex

# Compile individual .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link all objects into an ELF
$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Convert ELF to HEX
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash to microcontroller
flash: $(TARGET).hex
	sudo avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:$<

# Clean generated files
clean:
	rm -f *.elf *.hex *.o
