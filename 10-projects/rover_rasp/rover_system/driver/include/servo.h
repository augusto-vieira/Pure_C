#ifndef __SERVO_H
#define __SERVO_H

#define SERVO_PIN   18
#define PWM_RANGE   1000
#define PWM_CLOCK   384

#define LEFT        29
#define RIGHT       118
#define CENTER      73

int SERVO_init(void);
int SERVO_setAngle(int angle);

#endif
