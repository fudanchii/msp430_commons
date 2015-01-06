/*
 * watchdog.c
 *
 *  Created on: 2015/01/06
 *      Author: adie
 */

#include <msp430.h>
#include <msp430/watchdog.h>

inline void Watchdog_enable(int timing) {
	WDTCTL = timing;
	IFG1 &= ~WDTIFG;
	IE1  |=  WDTIE;
}

inline void Watchdog_disable() {
	Watchdog_hold();
	IE1   &= ~WDTIE;
}
