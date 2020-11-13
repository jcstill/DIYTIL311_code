MCU = atmega328p
AVRDUDE_MCU = atmega328p
AVRDUDE_PROGRAMMER = usbtiny
AVRDUDE_FUSES = -U lfuse:w:0x62:m -U hfuse:w:0xd9:m -U efuse:w:0xff:m
DIR=$(dir)

Start:
	avr-gcc -mmcu=$(MCU) -o out.elf *.c
	avr-objcopy -j .text -j .data -O ihex out.elf out.hex
	avrdude -c $(AVRDUDE_PROGRAMMER) -p $(AVRDUDE_MCU) -U flash:w:out.hex

fuses:
	avrdude -c $(AVRDUDE_PROGRAMMER) -p $(AVRDUDE_MCU) $(AVRDUDE_FUSES)

clean:
	rm -f $(DIR)/*.elf $(DIR)/*.hex
