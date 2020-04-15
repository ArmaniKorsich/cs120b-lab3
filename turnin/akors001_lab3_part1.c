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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0XFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char count = 0x00;
	unsigned short i = 0x01;
    /* Insert your solution below */
    while (1) {

	count = 0x00;
	PORTC = 0x00;

	for (i = 0x01; i <= 0x80; i = 2 * i)
	{
		if ((PINA & i) == i)
		{
			count = count + 1;
		}
		if ((PINB & i) == i)
		{
			count = count + 1;
		}		

	}

	PORTC = count;
	
    }
    return 1;
}
