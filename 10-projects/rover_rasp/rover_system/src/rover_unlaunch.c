#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <file.h>
#include <log.h>

#define ROVER_UNLAUNCH "ROVER_UNLAUNCH"

int main()
{

  int ret ;
  char buff[80];

  file_t tasks[10]; 
  int size = 10;

  ret = readfile("pid_processes.dat", tasks, &size);
  if(ret != 0){
    log(ROVER_UNLAUNCH, "Error readfile");
    return EXIT_FAILURE;
  }

  for(int i = 0; i < size; i++){

    printf("name: %s, pid[%d]\n", tasks[i].name, tasks[i].pid);
    memset(buff, 0, sizeof(buff));
    snprintf(buff, sizeof(buff), "kill %d", tasks[i].pid);
    system(buff);
  } 

  return EXIT_SUCCESS;
}
