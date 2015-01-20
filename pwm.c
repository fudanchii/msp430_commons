#include <msp430.h>
#include <msp430/g2553/pwm.h>

#define __PWM_SETUP(i, ccr1, p, d, ie) do { \
	if (pwm_set[i] == 0) { \
		TA##i##CTL  = TASSEL_2 | MC_1; \
		TA##i##CCTL1 = OUTMOD_7 | ie; \
		pwm_set[i] = 1; \
	} \
	TA##i##CCR0 = p - 1; \
	ccr1 = d; \
} while(0)

static char pwm_set[2] = {0,0};

#define  __PWM1_SETUP(t, p, d, ie) \
	__PWM_SETUP(0, t, p, d, ie)

#define __PWM2_SETUP(t, p, d, ie) \
	__PWM_SETUP(1, t, p, d, ie)

inline void PWM1_1_nointr_setup(int period, int duty_cycle) {
	__PWM1_SETUP(TA0CCR1, period, duty_cycle, 0);
}

inline void PWM1_1_std_setup(int period, int duty_cycle) {
	__PWM1_SETUP(TA0CCR1, period, duty_cycle, CCIE);
}

inline void PWM1_2_nointr_setup(int period, int duty_cycle) {
	__PWM1_SETUP(TA0CCR2, period, duty_cycle, 0);
}

inline void PWM1_2_std_setup(int period, int duty_cycle) {
	__PWM1_SETUP(TA0CCR2, period, duty_cycle, CCIE);
}

inline void PWM2_1_nointr_setup(int period, int duty_cycle) {
	__PWM2_SETUP(TA1CCR1, period, duty_cycle, 0);
}

inline void PWM2_1_std_setup(int period, int duty_cycle) {
	__PWM2_SETUP(TA1CCR1, period, duty_cycle, CCIE);
}

inline void PWM2_2_nointr_setup(int period, int duty_cycle) {
	__PWM2_SETUP(TA1CCR2, period, duty_cycle, 0);
}

inline void PWM2_2_std_setup(int period, int duty_cycle) {
	__PWM2_SETUP(TA1CCR2, period, duty_cycle, CCIE);
}
