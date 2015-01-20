/*
 * uart.c
 *
 *  Created on: 2015/01/17
 *      Author: adie
 */

#include <msp430.h>
#include <msp430/port1.h>
#include <msp430/g2553/uart.h>

inline void UART_setup(int bitrate) {
	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0 = bitrate;
	UCA0BR1 = 0;
	UCA0MCTL = UCBRS2 + UCBRS0;
	UCA0CTL1 &= ~UCSWRST;
}
