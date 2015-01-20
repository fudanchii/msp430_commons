/*
 * servo.c
 *
 *  Created on: 2015/01/17
 *      Author: adie
 */
#include <msp430.h>
#include <msp430/g2553/pwm.h>
#include <msp30/g2553/servo.h>

static int _servo_allocated = 0;

inline void Servo_nointr_setup(Servo *srv) {
	_servo_allocated += 1;
	switch (_servo_allocated) {
	case 1:
		INIT_SERVO_ANGLE_LUT(PWM1_1_duty_cycle_at, SERVO1_1);
		PWM1_1_nointr_setup(SERVO1_PERIOD, PWM1_1_duty_cycle_at[0]);
		break;
	case 2:
#ifdef MSP430G2553IN20
		INIT_SERVO_ANGLE_LUT(PWM2_1_duty_cycle_at, SERVO2_1);
		PWM2_1_nointr_setup(SERVO2_PERIOD, PWM2_1_duty_cycle_at[0]);
		break;
	case 3:
		INIT_SERVO_ANGLE_LUT(PWM2_2_duty_cycle_at, SERVO2_2);
		PWM2_2_nointr_setup(SERVO2_PERIOD, PWM2_2_duty_cycle_at[0]);
		break;
#else
		INIT_SERVO_ANGLE_LUT(PWM1_2_duty_cycle_at, SERVO1_2);
		PWM1_2_nointr_setup(SERVO1_PERIOD, PWM1_2_duty_cycle_at[0]);
		break;
	case 3:
		INIT_SERVO_ANGLE_LUT(PWM2_1_duty_cycle_at, SERVO2_1);
		PWM2_1_nointr_setup(SERVO2_PERIOD, PWM2_1_duty_cycle_at[0]);
		break;
	case 4:
		INIT_SERVO_ANGLE_LUT(PWM2_2_duty_cycle_at, SERVO2_2);
		PWM2_2_nointr_setup(SERVO2_PERIOD, PWM2_2_duty_cycle_at[0]);
		break;
#endif
	}
}

int Servo_allocated() {
	return _servo_allocated;
}
