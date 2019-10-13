/*	Author: cdiaz021
 *  Partner(s) Name: Jacob Halvorson
 *	Lab Section:
 *	Assignment: Lab 4  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpA;
unsigned char tmpB;
enum States {LOCKED, POUND, UNLOCKED} state;

void tick() {
    
    tmpA = 0xFF & PINA;

    switch (state) { //state transitions
	case LOCKED:
	 	if (tmpA == 0x04) {state = POUND;}
		else {state = LOCKED;}
		break;
	case POUND:
		if (tmpA == 0x02) {state = UNLOCKED;}
		else if (tmpA == 0x00) {state = POUND;}
		else {state = LOCKED;}
		break;
	case UNLOCKED:
		if (tmpA == 0x80) {state = LOCKED;}
		else {state = UNLOCKED;}
		break;
	default:
		state = LOCKED;
		break;
		
    }
    switch (state) {
        case LOCKED:
		tmpB = 0x00;		
                break;
        case POUND:
                break;
        case UNLOCKED:
		tmpB = 0x01;
                break;
        default:
                break;
    }	    	
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00; 

    /* Insert your solution below */
    state = LOCKED;  

    while (1) {
	tick();
	PORTB = tmpB;
    }
    return 1;
}
