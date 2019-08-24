#include <stdio.h>
#include <stdlib.h>
#include <shared_memory.h>

typedef struct shared_memory_context{
  int shmid;
}shared_memory_context_st;

static shared_memory_context_st shared_memory_ctx = {
  .shmid = -1;
};

int shared_memory_init(void)
{
  shared_memory_ctx.shmid = shmget((key_t)1234, sizeof(shared_memory_st), 0666 | IPC_CREAT);
  if(shared_memory_ctx.shmid == -1){
    fprintf(stderr, "shared_memory_init error\n");
    exit(EXIT_FAILURE);
  }
  
}

int shared_memory_write(void)
{

}

int shared_memory_read(void)
{

}

int shared_memory_denit(void)
{
  int ret = -1;
  if(shared_memory_ctx.shmid == -1){
    fprintf(stderr, "Shared Memory not initialize\n");
    return EXIT_FAILURE; 
  }

  ret = shmctl(shmid, IPC_RMID, 0);
  if(ret == -1){
    fprintf(stderr, "shared_memory_deinit\n");
    return EXIT_FAILURE;
  }
  shared_memory_ctx.shmid = -1;
  exit(EXIT_SUCCESS);

  
}
