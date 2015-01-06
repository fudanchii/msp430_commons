#include <msp430.h>
#include <msp430/g2553/pwm.h>

static inline void _PWM1_std_setup(int period, int duty_cycle, int ie) {
	TA0CTL   = TASSEL_2 | MC_1;			// SMCLK, upmode
	TA0CCTL1 = OUTMOD_7 | ie;			// TACCR1 reset/set
	TA0CCR0  = period-1;				// PWM Period
	TA0CCR1  = duty_cycle;				// TACCR1 initial PWM Duty Cycle
}

inline void PWM1_nointr_setup(int period, int duty_cycle) {
	_PWM1_std_setup(period, duty_cycle, 0);
}

inline void PWM1_std_setup(int period, int duty_cycle) {
	_PWM1_std_setup(period, duty_cycle, CCIE);
}

