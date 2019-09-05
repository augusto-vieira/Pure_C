#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <shared_memory.h>

typedef struct shared_memory_context{
  int shmid;
  void *share_mem;
}shared_memory_context_st;

static shared_memory_context_st shared_memory_ctx = {
  .shmid = -1,
  .share_mem = NULL
};

int shared_memory_init(void)
{
  shared_memory_ctx.shmid = shmget((key_t)1234, sizeof(shared_memory_st), 0666 | IPC_CREAT);
  if(shared_memory_ctx.shmid == -1){
    return (EXIT_FAILURE);
  }

  shared_memory_ctx.share_mem = shmat(shared_memory_ctx.shmid, (void *)0, 0);
  if(shared_memory_ctx.share_mem == (void *)-1){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int shared_memory_write(void *buffer, int offset, int size)
{
  if(shared_memory_ctx.shmid == -1){
    return EXIT_FAILURE; 
  }

  if(buffer == NULL)
    return EXIT_FAILURE;

  if(offset < 0)
    return EXIT_FAILURE;

  if(size <= 0)
    return EXIT_FAILURE;

  memcpy((shared_memory_ctx.share_mem + offset), buffer, size);
  return EXIT_SUCCESS;
}

int shared_memory_read(void *buffer, int offset, int size)
{
  if(shared_memory_ctx.shmid == -1){
    return EXIT_FAILURE; 
  }

  if(buffer == NULL)
    return EXIT_FAILURE;

  if(offset < 0)
    return EXIT_FAILURE;

  memcpy(buffer, (shared_memory_ctx.share_mem + offset), size);
  return EXIT_SUCCESS;
}

int shared_memory_denit(void)
{
  int ret = -1;
  if(shared_memory_ctx.shmid == -1){
    return EXIT_FAILURE; 
  }

  ret = shmctl(shared_memory_ctx.shmid, IPC_RMID, 0);
  if(ret == -1){
    return EXIT_FAILURE;
  }
  shared_memory_ctx.shmid = -1;
  return EXIT_SUCCESS;
}
