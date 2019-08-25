#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <shared_memory.h>

int main()
{
  int ret = -1;
  queue_st queue;
  shared_memory_st data = {
    .dummy = 0,
  };
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

    data.dummy = 1;
    if(shared_memory_write((void *)&data, 0, sizeof(data)) != 0){
      fprintf(stderr, "shared_memory_write error\n");
      continue;
    }

    sleep(1); 

    data.dummy = 0;
    if(shared_memory_write((void *)&data, 0, sizeof(data)) != 0){
      fprintf(stderr, "shared_memory_write error\n");
      continue;
    }

    sleep(1);
    printf("%s\n", queue.data_buffer);
    memset(queue.data_buffer, 0, sizeof(queue.data_buffer));
  }

}

