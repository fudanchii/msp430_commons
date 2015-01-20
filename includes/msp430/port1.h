/*
 *
 *  Created on: 2015/01/06
 *      Author: adie
 */

#ifndef MSP430_Port1_H_
#define MSP430_Port1_H_

inline void Port1_peripheral_select(int bits);
inline void Port1_peripheral_select2(int bits);
inline void Port1_extswitch_disable(int bits);
inline void Port1_extswitch_enable(int bits);
inline void Port1_extswitch_setup(int bits);
inline void Port1_extswitch_edgeflip(int bits);

inline void Switch_disable(void);
inline void Switch_enable(void);
inline void Switch_setup(void);
inline void Switch_edgeflip(void);

inline void	GreenLED_setup(void);
#define GreenLED_on()	P1OUT |= BIT6
#define GreenLED_off()	P1OUT &= ~BIT6
#define GreenLED_toggle() P1OUT ^= BIT6

inline void RedLED_setup(void);
#define RedLED_on()		P1OUT |= BIT0
#define RedLED_off()	P1OUT &= ~BIT0
#define RedLED_toggle()	P1OUT ^= BIT0

#endif /* MSP430_Port1_H_ */
