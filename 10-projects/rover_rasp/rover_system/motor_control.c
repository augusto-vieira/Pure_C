#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <sema.h>
#include <rover_types.h>

int main()
{

  int update = 0;
  motor_st motores;


  int ret = shared_memory_init();
  if(ret != 0){
    fprintf(stderr, "Shared memory error\n");
    return EXIT_FAILURE;
  }

  ret = semaphore_init();
  if(ret != 0){
    fprintf(stderr, "semaphore init error\n");
    return EXIT_FAILURE;
  }
  


  while(1)
  {
    if(!semaphore_lock()){


      if(shared_memory_read((void *)&motores, MOTOR_OFFSET, sizeof(motores))){
        fprintf(stderr, "shared memory read\n");
      }

      update = motores.status;
      motores.status = 0;

      if(shared_memory_write((void *)&motores, MOTOR_OFFSET, sizeof(int) * 2) != 0){
        fprintf(stderr, "shared_memory_write error\n");
      }

      semaphore_unlock();    
    }

    if(update == 1){
      printf("%s\n", motores.command);
      update = 0;
    } 
    else{
      usleep(1000);
    }
  }
}
