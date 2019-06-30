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

uint8_t LED_state = 1;					// 0 = off, 1 = on

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

#if HW_VERSION == 1.2
ISR(INT0_vect){
	uint8_t piD = 0;
	piD = readPortIn(2);				// Read the INT0 state
	if(piD & 0x04 != 0){				// Rising edge of INT0
		// Immediately force all output pins low
		// PORTD &= 0xE4;
		// PORTC &= 0xC0;
		// PORTB &= 0x03;
		// Turn off LEDs (Logically)
		LED_state = 0;
	}else{								// Falling edge of INT0
		// Turn on LEDs
		LED_state = 1;
	}
}
#endif

int main(void){
/*******************
 *   Set up I/O    *
 *******************/
	// Set registers to default value
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0x00;
	
	// Set pin directions (1 is output, 0 is input)
#if HW_VERSION == 1.1
	DDRD = 0x1F;					// D Reg:	0001 1111
	DDRC = 0x3F;					// C Reg:	0011 1111			
	DDRB = 0x00;					// B Reg:	XX0X XX00
#elif HW_VERSION == 1.2
	DDRD = 0x1B;					// D Reg:	0001 1011
	DDRC = 0x3F;					// C Reg:	0011 1111			
	DDRB = 0x20;					// B Reg:	XX1X XX00
#endif
	
/*******************
 *    Variables    *
 *******************/
	uint8_t piB = 0x00;					// B register on a328p
	uint8_t piC = 0x00;					// C register on a328p
	uint8_t piD = 0x00;					// D register on a328p
	uint8_t chpCtrl = 0x00;				// DIYTIL311 external control word: HLD, D(8), C(4), B(2), A(1)
	
/*******************
 * Interrupt Blank *
 *******************/
#if HW_VERSION == 1.2
	DDRD &= 0xFB;					// Set INT0 as an input (also set in I/O)
	PORTD |= 0x04;					// Enable pull-up resistor
	EICRA = 0x01;					// Trigger INT0 on any change
	EIMSK = 0x01;					// Enable INT0
	// EICRA = 1<<ISC00;    			// Trigger INT0 on rising edge
	// EIMSK = 1<<INT0;     			// Enable INT0
	sei();							// Enable Global Interrupt
#endif
	
/*******************
 *    Main Loop    *
 *******************/
	while(1){
		// Loop here if the blanking pin is enabled (HIGH) to prevent aimlessly processing (multiplexing)
		do{
			// Read input ports
			piB = readPortIn(0);
			piC = readPortIn(1);
			piD = readPortIn(2);
			
		#if HW_VERSION == 1.1
			if(piB & 0x20 == 0){	// Check to see if BLNK has gone low
				LED_state = 1;
			}else{
				LED_state = 0;
			}
		#endif
			
		}while(LED_state != 0);
		
		// Set DIYTIL311 control word to register values
		chpCtrl |= (piD & 0x20 >> 1) & (piD & 0x80 >> 4) & (piD & 0x40 >> 4) & (piB & 0x02) & (piB & 0x01);
		
		// Process chpCtrl and call multiplexing function
		if(LED_state == 1){
			
		}
	}
}



/*


		// Set high bit of control word
	#if HW_VERSION == 1.1
		chpCtrl = (piB & 0x20);
	#elif HW_VERSION == 1.2
		chpCtrl = (piD & 0x04 << 3);
	#endif














































*/


// Nuclear (Album Version) - Zomboy 