#ifndef __SHARED_MEMORY_H
#define __SHARED_MEMORY_H

#include <rover_types.h>

typedef struct shared_memory_st{
  motor_st motors;
  servo_st servo; 
}shared_memory_st;

typedef struct generic{
  long int id;
  char command[512];
}generic_st;

int shared_memory_init(void);
int shared_memory_write(void *buffer, int offset, int size);
int shared_memory_read(void *buffer, int offset, int size);
int shared_memory_denit(void);

#endif

