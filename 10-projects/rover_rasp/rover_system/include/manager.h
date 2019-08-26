#ifndef __MANAGER_H
#define __MANAGER_H

typedef enum TYPE{
  MOTOR_ID = 0,
  SERVO_ID
}TYPE_e;

int manager(int id, const char *command);

#endif
