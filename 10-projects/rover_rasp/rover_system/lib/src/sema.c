#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY 0x1111

typedef struct{
  int init;
  int sem_id;
}sem_context_t;

union semun{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, 1, SEM_UNDO};

static sem_context_t sem_ctx = 
{
  .init = -1,
  .sem_id = -1
};

int semaphore_init(void)
{
  union semun u;
  int ret;
  if(sem_ctx.init == 1)
    return 0;
  //ret = sem_init(&sem_ctx.mutex, 1, 1);
  //sem_ctx.mutex = sem_open(sem_name, O_CREAT, 0660, 1);
  sem_ctx.sem_id = semget(KEY, 1, 0666 | IPC_CREAT);
  if(sem_ctx.sem_id >= 0){
    sem_ctx.init = 1;
  }
  
  u.val = 1;
  ret = semctl(sem_ctx.sem_id, 0, SETVAL, u);
  if(ret < 0){
    fprintf(stderr, "semctl\n");
    sem_ctx.init = -1;
    return ret;
  }

  return 0;
}

int semaphore_lock(void)
{
  if(sem_ctx.init == -1)
    return -1;
  return semop(sem_ctx.sem_id, &p, 1); 
}

int semaphore_unlock(void)
{
  if(sem_ctx.init == -1)
    return -1;
  
  return semop(sem_ctx.sem_id, &v, 1); 
}

int semaphore_delete(void)
{
  int ret;
  if(sem_ctx.init == -1)
    return -1;

  //ret = sem_destroy(&sem_ctx.mutex);
  //ret = sem_unlink(sem_name);
  ret = semctl(sem_ctx.sem_id, 0, IPC_RMID, 0);
  if(ret < 0){
    return -1;
  }
  sem_ctx.init = -1;
  return 0;
}
