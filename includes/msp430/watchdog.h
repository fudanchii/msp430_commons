/*
 * msp430_watchdog.h
 *
 *  Created on: 2015/01/05
 *      Author: adie
 */

#ifndef MSP430_WATCHDOG_H_
#define MSP430_WATCHDOG_H_

#define Watchdog_hold()		WDTCTL = WDTPW + WDTHOLD
inline void Watchdog_disable();
inline void Watchdog_enable(int);


#endif /* MSP430_WATCHDOG_H_ */
