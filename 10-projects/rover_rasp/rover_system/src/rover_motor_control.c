#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <sema.h>
#include <rover_types.h>
#include <log.h>

#define ROVER_MOTOR   "ROVER_MOTOR"

int main()
{

  int update = 0;
  motor_st motores;


  int ret = shared_memory_init();
  if(ret != 0){
    log(ROVER_MOTOR, "Shared Memory Error.");
    return EXIT_FAILURE;
  }

  ret = semaphore_init();
  if(ret != 0){
    log(ROVER_MOTOR, "Semaphore Init Error.");
    return EXIT_FAILURE;
  }
  


  while(1)
  {
    if(!semaphore_lock()){


      if(shared_memory_read((void *)&motores, MOTOR_OFFSET, sizeof(motores))){
        log(ROVER_MOTOR, "Shared Memory Read.");
      }

      update = motores.status;
      motores.status = 0;

      if(shared_memory_write((void *)&motores, MOTOR_OFFSET, sizeof(int) * 2) != 0){
        log(ROVER_MOTOR, "Shared Memory Write Error.");
      }

      semaphore_unlock();    
    }

    if(update == 1){
      log(ROVER_MOTOR, motores.command);
      update = 0;
    } 
    else{
      usleep(1000);
    }
  }
}
