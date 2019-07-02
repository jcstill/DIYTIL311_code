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

uint8_t readPortIn(uint8_t x){
	if(x == 0){
		return PINB;					// Read B register inputs
	}else if(x == 1){
		return PINC;					// Read C register inputs
	}else if(x == 2){
		return PIND;					// Read D register inputs
	}else{
		return 0;						// Fallback to 0
	}
}
void matrixDown(void){
	// Turn off LED matrix
	PORTD &= 0xE0;
	PORTC &= 0x00;
	PORTB &= 0x23;
}
void led1(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led2(void){
	matrixDown();
	PORTD |= 0x01;						// LED_COL_2 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led3(void){
	matrixDown();
	PORTC |= 0x20;						// LED_COL_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led4(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led5(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led6(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led7(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led8(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led9(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led10(void){
	matrixDown();
	PORTC |= 0x10;						// LED_COL_4 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
}
void led11(void){
	matrixDown();
	PORTC |= 0x20;						// LED_COL_3 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x08;						// LED_ROW_4 on
}
void led12(void){
	matrixDown();
	PORTD |= 0x01;						// LED_COL_2 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x08;						// LED_ROW_4 on
}
void led13(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
}
void led14(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led15(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led16(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led17(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTD |= 0x10;						// LED_ROW_2 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led18(void){
	matrixDown();
	PORTD |= 0x02;						// LED_COL_1 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTC |= 0x02;						// LED_ROW_3 on
	PORTD |= 0x08;						// LED_ROW_4 on
	PORTC |= 0x04;						// LED_ROW_5 on
	PORTD |= 0x04;						// LED_ROW_6 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led19(void){
	matrixDown();
	PORTD |= 0x01;						// LED_COL_2 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void led20(void){
	matrixDown();
	PORTC |= 0x20;						// LED_COL_3 on
	PORTC |= 0x01;						// LED_ROW_1 on
	PORTC |= 0x08;						// LED_ROW_7 on
}
void writeDisplay(uint8_t x &= 0x0F){
	uint8_t i = 0;						// For loop variable
	uint8_t ledFac = 1;					// Factor of how many times the loop runs
	
	// Multiplexing - Each for loop has a different length based on how many LEDs are displayed AND how many pins need to be toggled
	if(x == 0x00){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x01){
		for(i=0; i<ledFac; i++){
			led4();
			led5();
			led6();
			led7();
			led8();
			led9();
			led10();
		}
	}else if(x == 0x02){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x03){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x04){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x05){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x06){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x07){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x08){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x09){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0A){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0B){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0C){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0D){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0E){
		for(i=0; i<ledFac; i++){
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
		}
	}else if(x == 0x0F){
		for(i=0; i<ledFac; i++){
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
	matrixDown();						// Clear Display
}

void aminate(void){
	// Small "boot" animation
	uint8_t length = 500;
	uint8_t i = 0;
	led1();
	for(i=0;i<length;i++);
	led2();
	for(i=0;i<length;i++);
	led3();
	for(i=0;i<length;i++);
	led4();
	for(i=0;i<length;i++);
	led5();
	for(i=0;i<length;i++);
	led6();
	for(i=0;i<length;i++);
	led7();
	for(i=0;i<length;i++);
	led8();
	for(i=0;i<length;i++);
	led9();
	for(i=0;i<length;i++);
	led10();
	for(i=0;i<length;i++);
	led11();
	for(i=0;i<length;i++);
	led12();
	for(i=0;i<length;i++);
	led13();
	for(i=0;i<length;i++);
	led14();
	for(i=0;i<length;i++);
	led15();
	for(i=0;i<length;i++);
	led16();
	for(i=0;i<length;i++);
	led17();
	for(i=0;i<length;i++);
	led18();
	for(i=0;i<length;i++);
	led19();
	for(i=0;i<length;i++);
	led20();
	for(i=0;i<length;i++);
}

