#ifndef __SERVO_H
#define __SERVO_H

#define SERVO_PIN   18
#define PWM_RANGE   2000
#define PWM_CLOCK   192

int SERVO_init(void);
int SERVO_setAngle(int angle);

#endif
