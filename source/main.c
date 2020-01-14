/*	Author: kvi001
 *  Partner(s) Name: Brittiney Sempasa
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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmp1 = 0x00;
	unsigned char tmp2 = 0x00;
	unsigned char cntavail = 0x04;

    /* Insert your solution below */
    while (1) {
	// 2.2 answer
	tmp1 = PINA & 0x0F; // check if PINA is 0000 1111 
	if (tmp1 & 0x01) {
		cntavail = cntavail - 1;
	} 		

	if (tmp1 & 0x02) { // checks if tmp1(PINA) is 0010
                cntavail = cntavail - 1;
        }

	if (tmp1 & 0x04) {  // checks if tmp1(PINA) is 0100
                cntavail = cntavail - 1;
        }

	if (tmp1 & 0x08) {  // checks if tmp1(PINA) is 1000
                cntavail = cntavail - 1;
        }
	
	PORTB = cntavail & 0x0F; //assign PORTC to num cntavail
	/*
	// 2.1 answer
	tmp1 = PINA & 0x01; // see if PINA is 0x01
	tmp2 = PINA & 0x02; // see if PINA is 0x02
	PORTB = ((!tmp2) & tmp1); // assigns PORTB with 1 if PINA1 = 0 and PINA0 = 1 
	
	// first attemp 2.1
	tmpA = PINA & 0x03;
	if (tmpA == 0x01) {
		PORTB = 0x01;
	} else {
		PORTB = 0x00;
	}*/	
    }
    return 1;
}
