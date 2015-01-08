/*
 * commons.h
 *
 *  Created on: 2015/01/06
 *      Author: adie
 */

#ifndef COMMONS_H_
#define COMMONS_H_

#include <msp430.h>
#include <msp430/port1.h>
#include <msp430/watchdog.h>

#define PIN0	BIT0
#define PIN1	BIT1
#define PIN2	BIT2
#define PIN3	BIT3
#define PIN4	BIT4
#define PIN5	BIT5
#define PIN6	BIT6
#define PIN7	BIT7
#define PIN8	BIT8
#define PIN9	BIT9
#define PINA	BITA
#define PINB	BITB
#define PINC	BITC
#define PIND	BITD
#define PINE	BITE
#define PINF	BITF

#ifndef PRAGMA
#define PRAGMA(p)	_Pragma(#p)
#endif

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)

#define ISR_Vector(iname)	PRAGMA(vector=iname)
#define ISR_Define(func)	__interrupt void func

#elif defined(__GNUC__)

#define ISR_Vector(iname)	void __attribute__ ((interrupt(iname)))
#define ISR_Define(func)	func
#endif

inline void basic_setup(void);

#endif /* COMMONS_H_ */
