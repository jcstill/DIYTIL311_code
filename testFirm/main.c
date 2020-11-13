#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
	// Set registers to default value
	DDRD = 0x00;
	DDRC = 0x00;
	DDRB = 0x00;
	// Set pin directions (1 is output, 0 is input)
	DDRD = 0x1F;						// D Reg:	0001 1111
	DDRC = 0x3F;						// C Reg:	0011 1111
	DDRB = 0x00;						// B Reg:	XXXX X000
	// Set pull-up resistors
	PORTD = 0xE0;						// D Reg:	1110 0000
	PORTC = 0x00;						// C Reg:	0000 0000
	PORTB = 0x07;						// B Reg:	0000 0111

	while(1){
	// //LED01
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001110;

	// //LED02
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011101;
	PORTC |= 0b00001110;

	// //LED03
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00101110;

	//LED04
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011110;

	//LED05
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00001100;
	PORTC |= 0b00011111;

	//LED06
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011101;

	//LED07
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010100;
	PORTC |= 0b00011111;

	//LED08
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011011;

	//LED09
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011000;
	PORTC |= 0b00011111;

	//LED10
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00010111;

	// //LED11
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00100111;

	// //LED12
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011101;
	PORTC |= 0b00000111;

	// //LED13
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00000111;

	// //LED14
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011010;
	PORTC |= 0b00001111;

	// //LED15
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001011;

	// //LED16
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010110;
	PORTC |= 0b00001111;

	// //LED17
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001101;

	// //LED18
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00001110;
	PORTC |= 0b00001111;

	// //LED19
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010101;
	PORTC |= 0b00001111;

	// //LED20
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010100;
	PORTC |= 0b00101111;
	}
}
















































// Nuclear (Album Version) - Zomboy 