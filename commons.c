/*
 * commons.c
 *
 *  Created on: 2015/01/06
 *      Author: adie
 */

#include <msp430/commons.h>

inline void basic_setup() {
	Watchdog_hold();
	Switch_setup();
	RedLED_setup();
	GreenLED_setup();
}
