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

int main(void){
/*******************
 *   Set up I/O    *
 *******************/
	// Set registers to default value
	DDRD = 0x00;
	DDRC = 0x00;
	DDRB = 0x00;
	// Set pin directions (1 is output, 0 is input)
	DDRD = 0x1F;						// D Reg:	0001 1111
	DDRC = 0x3F;						// C Reg:	0011 1111
	DDRB = 0x00;						// B Reg:	XX0X XX00
	// Set pull-up resistors
	PORTD = 0xE0;						// D Reg:	1110 0000
	PORTC = 0x00;						// D Reg:	0000 0000
	PORTB = 0x07;						// D Reg:	0000 0111


	while(1){
		writeDisplay(0x02);
	}

/*******************
 *    Variables    *
 *******************/
	unsigned char piB = 0x00;					// B register on a328p
	unsigned char piC = 0x00;					// C register on a328p
	unsigned char piD = 0x00;					// D register on a328p
	unsigned char chpCtrl = 0x00;				// DIYTIL311 external control word: X, X, X, X, D(8), C(4), B(2), A(1)
	unsigned char LED_state = 1;				// 0 = off, 1 = on

/*******************
 * Boot Animation  *
 *******************/
	//aminate();

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
			
			// Check to see if BLNK has gone low
			if((piB & 0x04) == 0){
				LED_state = 1;			// LEDs on
			}else{
				LED_state = 0;			// LEDs off
				// Immediately force all output pins low
				PORTD &= 0xE0;			// D Reg:	1110 0000
				PORTC &= 0x00;			// C Reg:	0000 0000
				// Wait here some time
				for(uint8_t i=0;i<100; i++){}
			}
		}while(LED_state == 0);
		
		// Process HLD
		if((piD & 0x20) == 0){
			// Update DIYTIL311 external control word to register values
			chpCtrl = 0x00;
			chpCtrl |= ((piD & 0x80) >> 4) | ((piD & 0x40) >> 4) | (piB & 0x02) | (piB & 0x01);
		}
		
		// Call multiplexing function
		writeDisplay(chpCtrl);
	}
}























































// Nuclear (Album Version) - Zomboy 