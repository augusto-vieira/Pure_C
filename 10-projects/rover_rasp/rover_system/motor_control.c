#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>
#include <rover_types.h>
#include <signal.h>

static int update = 0;

void need_update(int num)
{
  update = 1;
}

int main()
{

  motor_st motores;

  signal(SIGUSER1, need_update);

  int ret = shared_memory_init();
  if(ret != 0){
    fprintf(stderr, "Shared memory error\n");
    return EXIT_FAILURE;
  }

  while(1)
  {
    if(shared_memory_read((void *)&motores, 0, sizeof(motores))){
      fprintf(stderr, "shared memory read\n");
    }

    

  //  if(data.dummy != 0){
  //    printf("data.dummy: %d\n", data.dummy);
  //  }
  //  else{
  //    printf("not receiving\n");
  //  }
  }
}
