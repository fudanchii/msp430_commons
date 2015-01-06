/*
 * commons.h
 *
 *  Created on: 2015/01/06
 *      Author: adie
 */

#ifndef COMMONS_H_
#define COMMONS_H_

#include <msp430.h>
#include <msp430/pin1.h>
#include <msp430/watchdog.h>

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
