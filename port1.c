/*
 *
 *  Created on: 2014/12/30
 *      Author: Nurahmadie
 */

#ifndef ADMSP_H_
#define ADMSP_H_

#include <msp430/commons.h>

#define P_IN	1
#define P_OUT	2
#define P_SW	3


inline void Port1_peripheral_select(int bits) {
	P1DIR |= bits;					// Set <bits> direction (output)
	P1SEL |= bits;					// Select <bits> for peripheral use
}

inline void Port1_peripheral_select2(int bits) {
	P1DIR  |= bits;
	P1SEL2 |= bits;
}

inline void Port1_extswitch_enable(int bits) {
	// Enable interrupt on Pin 1.<bits>
	P1IE  |= bits;

	// Clear interrupt flag on Pin 1.<bits>
	// so we can accept more interrupt
	P1IFG &= ~bits;
}


inline void Port1_extswitch_setup(int bits) {
	// set Pin1 interrupt on Hi-Lo transition
	P1IES |= bits;

	// Enable pull-up resistor on Pin 1.<bits>
	P1OUT |= bits;
	P1REN |= bits;

	Port1_extswitch_enable(bits);
}

inline void Port1_extswitch_disable(int bits) {
	P1IE &= ~bits;
	P1IFG = 0;
}

inline void Switch_disable() {
	Port1_extswitch_disable(PIN3);
}

inline void Switch_enable() {
	Port1_extswitch_enable(PIN3);
}

inline void Switch_setup() {
	Port1_extswitch_setup(PIN3);
}

inline void Port1_out_setup(int bits) {
	P1DIR |= bits;
	P1OUT &= ~bits;
}

inline void Port1_extswitch_edgeflip(int bits) {
	P1IES ^= bits;
}

inline void Switch_edgeflip() {
	Port1_extswitch_edgeflip(PIN3);
}

inline void GreenLED_setup() {
	Port1_out_setup(PIN6);
}

inline void RedLED_setup() {
	Port1_out_setup(PIN0);
}

#endif /* ADMSP_H_ */
