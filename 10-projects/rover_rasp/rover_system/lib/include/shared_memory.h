#ifndef __SHARED_MEMORY_H
#define __SHARED_MEMORY_H

#define MAX_COMMAND_SIZE      512

typedef struct shared_memory_st{
  int id;
  char command[MAX_COMMAND_SIZE];
}shared_memory_st;

int shared_memory_init(void);
int shared_memory_write(void *buffer, int offset, int size);
int shared_memory_read(void *buffer, int offset, int size);
int shared_memory_denit(void);

#endif

