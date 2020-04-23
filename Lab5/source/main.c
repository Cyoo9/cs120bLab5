/*	Author: lab
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
      DDRC = 0xFF; PORTC = 0x00;
      unsigned char temp;
    /* Insert your solution below */
    while (1) {
	temp = ~PINA & 0x0F;
	if(temp == 0) {
		PORTC = 0x40;
	}
	
	else if(((temp & 0x01) == 1) || ((temp & 0x02) == 2)) { 
		PORTC = 0x60;
	}
	else if(((temp & 0x03) == 3) || ((temp & 0x04) == 4)) {
		PORTC = 0x70; 
	}
	else if(((temp & 0x05) == 5) || ((temp & 0x06) == 6)) {
		PORTC = 0x38;
	}
	else if(((temp & 0x07) == 7) || ((temp & 0x08) == 8) || ((temp & 0x09) == 9)) {
		PORTC = 0x3C;
	}
	else if(((temp & 0x0A) == 10) || ((temp & 0x0B) == 11) || ((temp & 0x0C) == 12)) {
		PORTC = 0x3E;
	}
	else if(((temp & 0x0D) == 13) || ((temp & 0x0E) == 14) || ((temp & 0x0F) == 15)) {
		PORTC = 0x3F;
	}

    }

    return 0;
}
