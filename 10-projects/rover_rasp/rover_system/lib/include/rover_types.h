#ifndef __ROVER_TYPES_H
#define __ROVER_TYPES_H 

typedef struct motor{
  int id;
  char command[512];
}motor_st;

typedef struct servo{
  int id;
  char command[512];
}servo_st;

#endif
