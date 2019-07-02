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

/********************************************************************************
 *                               Pin definitions                                *
 *                                                                              *
 *  // LED Columns                                                              *
 *  LED_COL_1				PORTD	=	(0x02)	|	(0b00000010)	|	(1<<1)  *
 *  LED_COL_2				PORTD	=	(0x01)	|	(0b00000001)	|	(1<<0)  *
 *  LED_COL_3				PORTC	=	(0x20)	|	(0b00100000)	|	(1<<5)  *
 *  LED_COL_4				PORTC	=	(0x10)	|	(0b00010000)	|	(1<<4)  *
 *                                                                              *
 *  // LED Rows                                                                 *
 *  LED_ROW_1				PORTC	=	(0x01)	|	(0b00000001)	|	(1<<0)  *
 *  LED_ROW_2				PORTD	=	(0x10)	|	(0b00010000)	|	(1<<4)  *
 *  LED_ROW_3				PORTC	=	(0x02)	|	(0b00000010)	|	(1<<1)  *
 *  LED_ROW_4				PORTD	=	(0x08)	|	(0b00001000)	|	(1<<3)  *
 *  LED_ROW_5				PORTC	=	(0x04)	|	(0b00000100)	|	(1<<2)  *
 *  LED_ROW_6				PORTD	=	(0x04)	|	(0b00000100)	|	(1<<2)  *
 *  LED_ROW_7				PORTC	=	(0x08)	|	(0b00001000)	|	(1<<3)  *
 *                                                                              *
 *  // External Control Pins                                                    *
 *  EX_PIN_BLNK				PINB	=	(0x20)	|	(0b00100000)	|	(1<<5)  *
 *  EX_PIN_HLD				PIND	=	(0x20)	|	(0b00100000)	|	(1<<5)  *
 *                                                                              *
 *  // External Data Pins                                                       *
 *  EX_PIN_DI-A				PIND	=	(0x80)	|	(0b10000000)	|	(1<<7)  *
 *  EX_PIN_DI-B				PIND	=	(0x40)	|	(0b01000000)	|	(1<<6)  *
 *  EX_PIN_DI-C				PINB	=	(0x02)	|	(0b00000010)	|	(1<<1)  *
 *  EX_PIN_DI-D				PINB	=	(0x01)	|	(0b00000001)	|	(1<<0)  *
 *                                                                              *
 *  // Resonator Pins                                                           *
 *  RES2					??PINB	=	(0x40)	|	(0b01000000)	|	(1<<6)  *
 *  RES1					??PINB	=	(0x80)	|	(0b10000000)	|	(1<<7)  *
 *                                                                              *
 *  // For Programming                                                          *
 *  EX_PAD_MOSI				??PINB	=	(0x04)	|	(0b00000100)	|	(1<<2)  *
 *  EX_PAD_MISO				??PINB	=	(0x08)	|	(0b00001000)	|	(1<<3)  *
 *  EX_PAD_SCK				??PINB	=	(0x10)	|	(0b00010000)	|	(1<<4)  *
 *  EX_PAD_RST				??PINC	=	(0x40)	|	(0b01000000)	|	(1<<6)  *
 *                                                                              *
 ********************************************************************************/

// Function Declarations
uint8_t readPortIn(uint8_t);
void matrixDown(void);
void led1(void);
void led2(void);
void led3(void);
void led4(void);
void led5(void);
void led6(void);
void led7(void);
void led8(void);
void led9(void);
void led10(void);
void led11(void);
void led12(void);
void led13(void);
void led14(void);
void led15(void);
void led16(void);
void led17(void);
void led18(void);
void led19(void);
void led20(void);
void writeDisplay(uint8_t);
void aminate(void);


#endif