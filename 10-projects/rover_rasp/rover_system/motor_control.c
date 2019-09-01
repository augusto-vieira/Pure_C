#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <sema.h>
#include <rover_types.h>

int main()
{

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

      printf("Reading share memory.\n");
      sleep(2);

      if(shared_memory_read((void *)&motores, 0, sizeof(motores))){
        fprintf(stderr, "shared memory read\n");
      }

      semaphore_unlock();    
    }

    if(motores.id == 0){
      printf("%s\n", motores.command);
    } 

    

  //  if(data.dummy != 0){
  //    printf("data.dummy: %d\n", data.dummy);
  //  }
  //  else{
  //    printf("not receiving\n");
  //  }
  }
}
