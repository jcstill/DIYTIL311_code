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
#ifndef __MAIN_H__
#define __MAIN_H__

#include <avr/io.h>
#include <avr/interrupt.h>

/*******************
 * Pin definitions *
 *******************/

// LED Columns
#define LED_COL_1 PORTD |= (0x02)
#define LED_COL_2 PORTD |= (0x01)
#define LED_COL_3 PORTC |= (0x20)
#define LED_COL_4 PORTC |= (0x10)

// LED Rows                
#define LED_ROW_1 PORTC |= (0x01)
#define LED_ROW_2 PORTD |= (0x10)
#define LED_ROW_3 PORTC |= (0x02)
#define LED_ROW_4 PORTD |= (0x08)
#define LED_ROW_5 PORTC |= (0x04)
#define LED_ROW_6 PORTD |= (0x04)
#define LED_ROW_7 PORTC |= (0x08)

// External Control Pins
#define EX_PIN_BLNK PINB & (0x20)
#define EX_PIN_HLD PIND & (0x20)
//#define EX_PIN_LEDSOURCE

// External Data Pins
#define EX_PIN_DI-A PIND & (0x80)
#define EX_PIN_DI-B PIND & (0x40)
#define EX_PIN_DI-C PINB & (0x02)
#define EX_PIN_DI-D PINB & (0x01)

// Resonator Pins
#define RES2
#define RES1

// For Programming
#define EX_PAD_MOSI
#define EX_PAD_MISO
#define EX_PAD_SCK
#define EX_PAD_RST

#endif