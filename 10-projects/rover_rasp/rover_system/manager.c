#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <manager.h>
#include <queue.h>
#include <shared_memory.h>
#include <rover_types.h>
#include <sema.h>

int main()
{
  int ret = -1;
  queue_st queue;
  generic_st data;

  ret = queue_init();

  if(ret != 0){
    fprintf(stderr, "queue init\n");
    exit(EXIT_FAILURE);
  }
  
  ret = semaphore_init();

  if(ret != 0){
    fprintf(stderr, "sema init\n");
    exit(EXIT_FAILURE);
  }

  ret = shared_memory_init();
  if(ret != 0){
    fprintf(stderr, "shared memory init\n");
    exit(EXIT_FAILURE);
  }

  while(1)
  {
    if(queue_recv(&queue, sizeof(queue.data_buffer)) != 0){
      fprintf(stderr, "queue recv error\n");
    } 

    //convert to generic type to analise which id is.
    memset(&data, 0, sizeof(data));
    memcpy(&data, queue.data_buffer, sizeof(data));

    if(manager(data.id, data.command) != 0){
      fprintf(stderr, "Error type no exist\n");
    }

    memset(queue.data_buffer, 0, sizeof(queue.data_buffer));
  }
}

int manager(int id, const char *command)
{
  int offset;
  int ret = 0;
  generic_st data;

  switch(id){
    case MOTOR_ID:
      offset = MOTOR_OFFSET;
      break;

    case SERVO_ID:
      offset = SERVO_OFFSET;
      break;
    
    default: 
      ret = -1;
  }

  if(ret != 0){
    return ret;
  }

  data.id = id;
  memcpy(data.command, command, sizeof(data.command));

  if(!semaphore_lock()){

    printf("Writing on share memory.\n");
    sleep(1);

    if(shared_memory_write((void *)&data, offset, sizeof(data)) != 0){
      fprintf(stderr, "shared_memory_write error\n");
    }

    semaphore_unlock();
  }
}
