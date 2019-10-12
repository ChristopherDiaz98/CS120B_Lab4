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

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;	PORTA = 0xFF;
    DDRC = 0xFF;	PORTC = 0x00; 

    /* Insert your solution below */
    unsigned char tmp = 0x00;
    unsigned char cnt = 0x00;
    unsigned char inc = 0x00;
    unsigned char dec = 0x00;
    enum States {start,increment,decriment,wait,reset} state;

    while (1) {

	    tmp = PINA & 0xFF;
	    inc = 0x00;
	    dec = 0x00;

	    switch(state){

		    case start:
			    if(tmp == 0x01) {state = incriment;}
			    else if(tmp == 0x02) {state = deccriment;}
			    else 
			    break;
		    case B0_ON:
			    if(tmp == 0x01) {state = waitB1;}
			    else {state = B0_ON;}
			    break;
		    case waitB0:
			    if(tmp == 0x01) {state = waitB0;}
			    else {state = B0_ON;}
			    break;
		    case B1_ON:
			    if(tmp == 0x01) {state = waitB0;}
			    else {state = B1_ON;}
			    break;
		    case waitB1:
			    if(tmp == 0x01) {state = waitB1;}
			    else {state = B1_ON;}
			    break;
		    default:
			    state = B0_ON;
			    break;
	    }

	    switch(state){
	
		    case B0_ON:
			    LED_0 = 0x01;
			    LED_1 = 0x00;
			    break;
		    case waitB0:
			    LED_0 = 0x01;
			    LED_1 = 0x01;
			    break;
		    case B1_ON:
			    LED_0 = 0x00;
			    LED_1 = 0x02;
			    break;
		    case waitB1:
			    LED_0 = 0x00;
			    LED_1 = 0x02;
			    break;
		    default:
			    break;
	    }

	    PORTC = LED_0 | LED_1;
    }
    return 1;
}
