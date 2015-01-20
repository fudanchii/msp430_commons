/*
 * pwm.h
 *
 *  Created on: 2015/01/05
 *      Author: adie
 */

#ifndef PWM_H_
#define PWM_H_

extern unsigned int PWM1_1_duty_cycle_at[];

// not available in MSP430G2553-IN20
extern unsigned int PWM1_2_duty_cycle_at[];

extern unsigned int PWM2_1_duty_cycle_at[];
extern unsigned int PWM2_2_duty_cycle_at[];


inline void PWM1_1_nointr_setup(int period, int duty_cycle);
inline void PWM1_1_std_setup(int period, int duty_cycle);

inline void PWM1_2_nointr_setup(int period, int duty_cycle);
inline void PWM1_2_std_setup(int period, int duty_cycle);

inline void PWM2_1_nointr_setup(int period, int duty_cycle);
inline void PWM2_1_std_setup(int period, int duty_cycle);

inline void PWM2_2_nointr_setup(int period, int duty_cycle);
inline void PWM2_2_std_setup(int period, int duty_cycle);


#define PWM1_1_set_duty_cycle(dc)		TA0CCR1 = (dc)

// not available in MSP430G2553-IN20
#define PWM1_2_set_duty_cycle(dc)		TA0CCR2 = (dc)

#define PWM2_1_set_duty_cycle(dc)		TA1CCR1 = (dc)
#define PWM2_2_set_duty_cycle(dc)		TA1CCR2 = (dc)

#endif /* PWM_H_ */
