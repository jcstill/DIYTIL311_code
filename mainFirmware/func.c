/*
*	Firmware for the programmable replica of the TIL311
*	This file is a part of the DIYTIL311 source code.
*
*	Copyright (C) 2019  Jacob Still and Alex Golubow
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*	Project page: https://hackaday.io/project/166086-diytil311
*	Code: https://github.com/jcstill/DIYTIL311
*	
*/

#include "main.h"

unsigned char readPortIn(unsigned char x){
	switch(x){
		case 1:
			asm("nop");
			return PINB;
			break;
		case 2:
			asm("nop");
			return PINC;
			break;
		case 3:
			asm("nop");
			return PIND;
			break;
		default:
			return 0;
	}
}
void led1(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001110;
}
void led2(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011101;
	PORTC |= 0b00001110;
}
void led3(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00101110;
}
void led4(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011110;
}
void led5(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00001100;
	PORTC |= 0b00011111;
}
void led6(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011101;
}
void led7(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010100;
	PORTC |= 0b00011111;
}
void led8(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00011011;
}
void led9(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011000;
	PORTC |= 0b00011111;
}
void led10(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00010111;
}
void led11(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011100;
	PORTC |= 0b00100111;
}
void led12(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011101;
	PORTC |= 0b00000111;
}
void led13(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00000111;
}
void led14(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011010;
	PORTC |= 0b00001111;
}
void led15(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001011;
}
void led16(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010110;
	PORTC |= 0b00001111;
}
void led17(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00011110;
	PORTC |= 0b00001101;
}
void led18(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00001110;
	PORTC |= 0b00001111;
}
void led19(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010101;
	PORTC |= 0b00001111;
}
void led20(){
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTD |= 0b00010100;
	PORTC |= 0b00101111;
}

void writeDisplay(uint8_t x){
	x &= 0x0F;
	uint8_t i;							// For loop variable
	uint8_t ledFac = 1;					// Factor of how many times the loop runs
	
	// Multiplexing - Each for loop has a different length based on how many LEDs are displayed AND how many pins need to be toggled
	if(x == 0x00){
			led2();
			led3();
			led5();
			led6();
			led7();
			led8();
			led9();
			led11();
			led12();
			led14();
			led15();
			led16();
			led17();
			led18();
	}else if(x == 0x01){
			led4();
			led5();
			led6();
			led7();
			led8();
			led9();
			led10();
	}else if(x == 0x02){
			led1();
			led2();
			led3();
			led5();
			led6();
			led10();
			led11();
			led12();
			led13();
			led14();
			led15();
			led19();
			led20();
	}else if(x == 0x03){
			led1();
			led2();
			led3();
			led5();
			led6();
			led8();
			led9();
			led11();
			led12();
			led13();
			led19();
			led20();
	}else if(x == 0x04){
			led1();
			led5();
			led6();
			led7();
			led8();
			led9();
			led10();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x05){
			led1();
			led2();
			led3();
			led4();
			led8();
			led9();
			led11();
			led12();
			led13();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x06){
			led2();
			led3();
			led8();
			led9();
			led11();
			led12();
			led14();
			led15();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x07){
			led1();
			led2();
			led3();
			led4();
			led5();
			led6();
			led7();
			led8();
			led9();
			led10();
	}else if(x == 0x08){
			led2();
			led3();
			led5();
			led6();
			led8();
			led9();
			led11();
			led12();
			led14();
			led15();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x09){
			led2();
			led3();
			led5();
			led6();
			led7();
			led8();
			led9();
			led11();
			led12();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x0A){
			led2();
			led3();
			led5();
			led6();
			led7();
			led8();
			led9();
			led10();
			led13();
			led14();
			led15();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x0B){
			led1();
			led2();
			led3();
			led5();
			led6();
			led8();
			led9();
			led11();
			led12();
			led13();
			led14();
			led15();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x0C){
			led2();
			led3();
			led4();
			led10();
			led11();
			led12();
			led14();
			led15();
			led16();
			led17();
			led18();
	}else if(x == 0x0D){
			led1();
			led2();
			led3();
			led5();
			led6();
			led7();
			led8();
			led9();
			led11();
			led12();
			led13();
			led14();
			led15();
			led16();
			led17();
			led18();
	}else if(x == 0x0E){
			led1();
			led2();
			led3();
			led4();
			led10();
			led11();
			led12();
			led13();
			led14();
			led15();
			led16();
			led17();
			led18();
			led19();
			led20();
	}else if(x == 0x0F){
			led1();
			led2();
			led3();
			led4();
			led13();
			led14();
			led15();
			led16();
			led17();
			led18();
			led19();
			led20();
	}
}

// void aminate(void){
// 	// Small "boot" animation
// 	uint8_t length = 500;
// 	uint8_t i = 0;
// 	led1();
// 	for(i=0;i<length;i++);
// 	led2();
// 	for(i=0;i<length;i++);
// 	led3();
// 	for(i=0;i<length;i++);
// 	led4();
// 	for(i=0;i<length;i++);
// 	led5();
// 	for(i=0;i<length;i++);
// 	led6();
// 	for(i=0;i<length;i++);
// 	led7();
// 	for(i=0;i<length;i++);
// 	led8();
// 	for(i=0;i<length;i++);
// 	led9();
// 	for(i=0;i<length;i++);
// 	led10();
// 	for(i=0;i<length;i++);
// 	led11();
// 	for(i=0;i<length;i++);
// 	led12();
// 	for(i=0;i<length;i++);
// 	led13();
// 	for(i=0;i<length;i++);
// 	led14();
// 	for(i=0;i<length;i++);
// 	led15();
// 	for(i=0;i<length;i++);
// 	led16();
// 	for(i=0;i<length;i++);
// 	led17();
// 	for(i=0;i<length;i++);
// 	led18();
// 	for(i=0;i<length;i++);
// 	led19();
// 	for(i=0;i<length;i++);
// 	led20();
// 	for(i=0;i<length;i++);
// }

