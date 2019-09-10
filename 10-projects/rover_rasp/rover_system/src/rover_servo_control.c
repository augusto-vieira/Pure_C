#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <sema.h>
#include <rover_types.h>
#include <log.h>

#define ROVER_SERVO   "ROVER_SERVO"

int main()
{

  int update = 0;
  servo_st servo;


  int ret = shared_memory_init();
  if(ret != 0){
    log(ROVER_SERVO, "Shared Memory Init Error.");
    return EXIT_FAILURE;
  }

  ret = semaphore_init();
  if(ret != 0){
    log(ROVER_SERVO, "Semaphore Init Error.");
    return EXIT_FAILURE;
  }

  while(1)
  {
    if(!semaphore_lock()){

      if(shared_memory_read((void *)&servo, SERVO_OFFSET, sizeof(servo))){
        log(ROVER_SERVO, "Shared Memory Read Error.");
      }

      update = servo.status;
      servo.status = 0;

      if(shared_memory_write((void *)&servo, SERVO_OFFSET, sizeof(int) * 2)){
        log(ROVER_SERVO, "Shared Memory Write Error.");
      }

      semaphore_unlock();    
    }

    if(update == 1){
      log(ROVER_SERVO, servo.command);
      update = 0;
    } 
    else{
      usleep(1000);
    }

  }
}
