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
			    if(tmp == 0x01) {state = increment;}
			    else if(tmp == 0x03) {state = reset;}
			    else {state = wait;}
		    case increment:
			    if(tmp = 0x01) {state = increment;}
			    else if(tmp == 0x02) {state = decrement;}
			    else if(tmp == 0x03) {state = reset;}
			    else {state = wait;}
			    break;
		    case decrement:
			    if(tmp == 0x01) {state = increment;}
			    else if (tmp == 0x02) {state = decrement;}
			    else if(tmp == 0x03) {state = reset;}
			    else (state = wait;)
			    break;
		    case wait:
			    if(tmp == 0x01) {state = increment;}
                            else if(tmp == 0x02) {state = decrement;}
                            else if(tmp == 0x03) {state = reset;}
			    else {state = wait;}
                            break;
		    case reset:
			    if(tmp == 0x01) {state = increment;}
                            else if(tmp == 0x02) {state = decrement;}
                            else if(tmp == 0x03) {state = reset;}
			    else {state = wait;}
                            break;
		    default:
			    state = wait;
			    break;
	    }

	    switch(state){
	
		    case :
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
