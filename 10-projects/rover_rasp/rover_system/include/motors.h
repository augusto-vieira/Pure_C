#ifndef _MOTORS_H
#define _MOTORS_H

#define MOTOR_LEFT  1
#define MOTOR_RIGHT 2


void *motor_stop(void *args);
void *motor_turn_left(void *args);
void *motor_turn_right(void *args);
void *motor_forward(void *args);

#endif 
