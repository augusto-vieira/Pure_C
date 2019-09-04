#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <sema.h>
#include <rover_types.h>

int main()
{

  servo_st servo;


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

      if(shared_memory_read((void *)&servo, SERVO_OFFSET, sizeof(servo))){
        fprintf(stderr, "shared memory read\n");
      }

      semaphore_unlock();    
    }

    if(servo.id == 1){
      printf("%s\n", servo.command);
    } 

  }
}
