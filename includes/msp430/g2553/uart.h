/*
 * uart.h
 *
 *  Created on: 2015/01/17
 *      Author: adie
 */

#ifndef UART_H_
#define UART_H_

#include #<msp430.h>

#define B9600	104
#define B112500	8

#define UART_rx_interrupt_enable()	IE2 |= UCA0RXIE
#define UART_tx_interrupt_enable()	IE2 |= UCA0TXIE
#define UART_rt_interrupt_enable()	IE2 |= UCA0RXIE | UCA0TXIE

inline void UART_setup(int bitrate);

#endif /* UART_H_ */
