/*
 *
 *  Created on: 2014/12/30
 *      Author: Nurahmadie
 */

#ifndef ADMSP_H_
#define ADMSP_H_

#include <msp430.h>

#define P_IN	1
#define P_OUT	2
#define P_SW	3

extern unsigned int duty_cycle_at[];

inline void Pin1_select_peripheral(int bits) {
	P1DIR	|= bits;                // Set <bits> direction (output)
	P1SEL	|= bits;                // Select <bits> for peripheral use
}

inline void Pin1_switch_setup(int bits) {
    // Enable interrupt on Pin 1.<bits>
    // on Hi-Lo transition
    P1IE  |= bits;
    P1IES |= bits;

    // Enable pull-up resistor on Pin 1.<bits>
    P1OUT |= bits;
    P1REN |= bits;

    // Clear interrupt flag on Pin 1.<bits>
    // so we can accept more interrupt
    P1IFG &= ~bits;
}

inline void Pin1_setup(int direction, int bits) {
	switch(direction) {
	case P_SW:
		Pin1_switch_setup(bits);
		break;
	case P_IN:
		// TODO
		break;
	case P_OUT:
		P1DIR |= bits;
		P1OUT &= ~bits;
		break;
	default:
		break;
	}
}

inline void PWM1_std_setup(int period, int duty_cycle) {
	TA0CTL	 = TASSEL_2 | MC_1;     		// SMCLK, upmode
	TA0CCTL1 = OUTMOD_7 | CCIE;      		// TACCR1 reset/set
	TA0CCR0  = period-1; 			        // PWM Period
	TA0CCR1	 = duty_cycle;		            // TACCR1 initial PWM Duty Cycle
}

// You should define SERVO_MIN, SERVO_MAX, and SERVO_STEPS yourself
inline void init_servo_angle_lut() {
	int i = 0;
	unsigned int servo_stepval, servo_stepnow;

	// Calculate the step value and define the current step, defaults to maximum.
	servo_stepval 	= ((SERVO_MAX - SERVO_MIN) / SERVO_STEPS);
	servo_stepnow	= SERVO_MAX;

	// Fill up the LUT
	for (; i < SERVO_STEPS + 1; i++) {
		duty_cycle_at[i] = servo_stepnow;
		servo_stepnow -= servo_stepval;
	}
}


#endif /* ADMSP_H_ */
