#ifndef _MOTORS_H
#define _MOTORS_H

#define MOTOR_LEFT  1
#define MOTOR_RIGHT 2


int go_forward(int speed);
int turn_left(void);
int turn_right(void);
int go_stop();

#endif 
