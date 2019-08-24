#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>

int main()
{
  int ret = -1;
  queue_st queue;

  ret = queue_init();
  if(ret != 0){
    fprintf(stderr, "queue init\n");
    exit(EXIT_FAILURE);
  }

  while(1)
  {
    if(queue_recv(&queue, sizeof(queue.data_buffer)) != 0){
      fprintf(stderr, "queue recv error\n");
    } 

    printf("%s\n", queue.data_buffer);
    memset(queue.data_buffer, 0, sizeof(queue.data_buffer));
  }

}

