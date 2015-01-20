/*
 * servo.h
 *
 *  Created on: 2015/01/17
 *      Author: adie
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <msp430/g2553/pwm.h>

typedef struct t_servo {
	char	_timer;
	int 	_pin;
	int		current_position;
} Servo;

#define SERVO_MAXNUM	3

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

inline void Servo_nointr_setup(Servo*);
inline void Servo_std_setup(Servo*);
inline int Servo_allocated(void);
inline void Servo_set_position(Servo*, int);
inline void Servo_step_up(Servo*, int);
inline void Servo_step_down(Servo*, int);

#endif /* SERVO_H_ */
