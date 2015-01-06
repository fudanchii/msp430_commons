/*
 * pwm.h
 *
 *  Created on: 2015/01/05
 *      Author: adie
 */

#ifndef PWM_H_
#define PWM_H_

extern unsigned int PWM1_duty_cycle_at[];

inline void PWM1_nointr_setup(int period, int duty_cycle);
inline void PWM1_std_setup(int period, int duty_cycle);
#define PWM1_set_duty_cycle(dc)		TA0CCR1 = (dc)


#define INIT_SERVO_ANGLE_LUT(v,p) do { \
	int i = 0; \
	unsigned int servo_stepval, servo_stepnow; \
	servo_stepval = ((p##_MAX - p##_MIN) / p##_STEPS); \
	servo_stepnow = p##_MAX; \
	for (; i < p##_STEPS + 1; i++) {	\
		(v)[i] = servo_stepnow;	\
		servo_stepnow -= servo_stepval;	\
	}	\
} while(0);

#endif /* PWM_H_ */
