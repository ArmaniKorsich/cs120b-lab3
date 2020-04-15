/*	Author: akors001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFE; PORTB = 0X00;
	DDRD = 0x00; PORTD = 0xFF;

	unsigned short weight = 0x00;
	unsigned char B0 = 0x00;
	/* Insert your solution below */
    while (1) {
	weight = 0x00;	
	B0 = 0x00;
	PORTB = 0x00;	

	weight = PIND;
	weight = weight  << 1;
	B0 = (PINB & 0x01);
	weight = weight | B0;

	if (weight >= 70)
	{
		PORTB = PORTB | 0x02; 
	}
	else if (weight >= 5)
	{
		PORTB = PORTB | 0x04;
	}
	else
	{
		PORTB = PORTB & 0xF9; //clear bits 1 and 2.
	}
	PORTB = PORTB | B0;
	
    }
	
}
