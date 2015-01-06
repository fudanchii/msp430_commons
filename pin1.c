/*
 *
 *  Created on: 2014/12/30
 *      Author: Nurahmadie
 */

#ifndef ADMSP_H_
#define ADMSP_H_

#include <msp430.h>
#include <msp430/pin1.h>

#define P_IN	1
#define P_OUT	2
#define P_SW	3


inline void Pin1_peripheral_select(int bits) {
	P1DIR |= bits;					// Set <bits> direction (output)
	P1SEL |= bits;					// Select <bits> for peripheral use
}

inline void Pin1_extswitch_enable(int bits) {
	// Enable interrupt on Pin 1.<bits>
	P1IE  |= bits;

	// Clear interrupt flag on Pin 1.<bits>
	// so we can accept more interrupt
	P1IFG &= ~bits;
}


inline void Pin1_extswitch_setup(int bits) {
	// set Pin1 interrupt on Hi-Lo transition
	P1IES |= bits;

	// Enable pull-up resistor on Pin 1.<bits>
	P1OUT |= bits;
	P1REN |= bits;

	Pin1_extswitch_enable(bits);
}

inline void Pin1_extswitch_disable(int bits) {
	P1IE &= ~bits;
	P1IFG = 0;
}

inline void Switch_disable() {
	Pin1_extswitch_disable(BIT3);
}

inline void Switch_enable() {
	Pin1_extswitch_enable(BIT3);
}

inline void Switch_setup() {
	Pin1_extswitch_setup(BIT3);
}

inline void Pin1_out_setup(int bits) {
	P1DIR |= bits;
	P1OUT &= ~bits;
}

inline void Pin1_extswitch_edgeflip(int bits) {
	P1IES ^= bits;
}

inline void Switch_edgeflip() {
	Pin1_extswitch_edgeflip(BIT3);
}

inline void GreenLED_setup() {
	Pin1_out_setup(BIT6);
}

inline void RedLED_setup() {
	Pin1_out_setup(BIT0);
}

#endif /* ADMSP_H_ */
