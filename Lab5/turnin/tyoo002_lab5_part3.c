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

enum States {Start, off, on, hold} state;


void Tick() {
	switch(state) {
		case Start:
			PORTC = 0x00;
			state = off;
			break;
		case off:
		   if((~PINA & 0x01) == 0x01) {
			state = hold;
			if(PORTC == 0x00) { PORTC = 0x01; }
			else if(PORTC == 0x01) { PORTC = 0x02; }
			else if(PORTC == 0x02) { PORTC = 0x04; }
			else if(PORTC == 0x04) { PORTC = 0x08; }
			else if(PORTC == 0x08) { PORTC = 0x10; }
			else if(PORTC == 0x10) { PORTC = 0x20; }
			else if(PORTC == 0x20) { PORTC = 0x00; }
		   }
		   else {
			state = off;
		   }
		   break;
		case hold:
			if((~PINA & 0x01) == 0x01) { state = hold; }
			else { state = off; }
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    state = Start;
    while (1) {
        Tick();
    }
    return 0;
}
