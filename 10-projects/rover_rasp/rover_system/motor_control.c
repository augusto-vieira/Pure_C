#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shared_memory.h>

int main()
{
  shared_memory_st data = {
    .dummy = 0,
  };

  int ret = shared_memory_init();
  if(ret != 0){
    fprintf(stderr, "Shared memory error\n");
    return EXIT_FAILURE;
  }

  while(1)
  {
    if(shared_memory_read((void *)&data, 0, sizeof(data))){
      fprintf(stderr, "shared memory read\n");
      continue;
    }

    if(data.dummy != 0){
      printf("data.dummy: %d\n", data.dummy);
    }
    else{
      printf("not receiving\n");
    }
  }
}
