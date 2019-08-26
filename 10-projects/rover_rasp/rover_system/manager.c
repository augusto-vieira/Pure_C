#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <manager.h>
#include <queue.h>
#include <shared_memory.h>

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
      offset = 0;
      break;

    case SERVO_ID:
      offset = sizeof(data) * 1;
      break;
    
    default: 
      ret = -1;
  }

  if(ret != 0){
    return ret;
  }

  data.id = id;
  memcpy(data.command, command, sizeof(data.command));

  if(shared_memory_write((void *)&data, offset, sizeof(data)) != 0){
    fprintf(stderr, "shared_memory_write error\n");
  }
}
