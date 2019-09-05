#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <manager.h>
#include <queue.h>
#include <shared_memory.h>
#include <rover_types.h>
#include <sema.h>
#include <signal.h>
#include <log.h>

#define ROVER_MANAGER   "ROVER_MANAGER"
static void signal_handler(int sig){
  if(sig == SIGTERM){
    queue_deinit();
    semaphore_delete();
    shared_memory_denit();
    exit(SIGTERM);
  }
}

int main()
{
  int ret = -1;
  queue_st queue;
  generic_st data;

  signal(SIGTERM, signal_handler);

  ret = queue_init();

  if(ret != 0){
    log(ROVER_MANAGER, "Queue init error.");
    exit(EXIT_FAILURE);
  }
  
  ret = semaphore_init();

  if(ret != 0){
    log(ROVER_MANAGER, "Semaphore init error.");
    exit(EXIT_FAILURE);
  }

  ret = shared_memory_init();
  if(ret != 0){
    log(ROVER_MANAGER, "Shared Memory Init");
    exit(EXIT_FAILURE);
  }

  while(1)
  {
    if(queue_recv(&queue, sizeof(queue.data_buffer)) != 0){
      log(ROVER_MANAGER, "Queue receive error.");
    } 

    //convert to generic type to analise which id is.
    memset(&data, 0, sizeof(data));
    memcpy(&data, queue.data_buffer, sizeof(data));

    if(manager(data.id, data.command) != 0){
      log(ROVER_MANAGER, "Error type no exist.");
    }

    memset(queue.data_buffer, 0, sizeof(queue.data_buffer));
  }
}

int manager(int id, const char *command)
{
  int offset;
  int ret = 0;
  int status = 0;
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
  data.status = 1;
  memcpy(data.command, command, sizeof(data.command));

  if(!semaphore_lock()){

    if(shared_memory_write((void *)&data, offset, sizeof(data)) != 0){
      log(ROVER_MANAGER, "Shared Memory write error.");
    }

    semaphore_unlock();
  }
}
