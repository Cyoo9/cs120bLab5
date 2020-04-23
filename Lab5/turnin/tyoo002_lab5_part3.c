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
	unsigned char temp;
	switch(state) {
		case Start:
			temp = 0x00;
			PORTC = temp;
			state = off;
			break;
		case off:
		   if((~PINA & 0x01) == 0x01) {
			state = hold;
			if(PORTC == 0x00) {
			       	temp = 0x01;
		       		PORTC = temp;
			}
			else if(PORTC == 0x01) { 
				temp = 0x02;
				PORTC = temp;
		       	}
			else if(PORTC == 0x02) {
			        temp = 0x04;	
				PORTC = temp; 
			}
			else if(PORTC == 0x04) {
			       	temp = 0x08;
		       		PORTC = temp;
			}
			else if(PORTC == 0x08) { 
				temp = 0x10;
		       		PORTC = temp;
			}
			else if(PORTC == 0x10) {
				temp = 0x20;
		       		PORTC = temp;
			}
			else if(PORTC == 0x20) { 
				temp = 0x00;
		       		PORTC = temp;
			}
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
