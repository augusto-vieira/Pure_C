#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <log.h>
#include <file.h>

#define ROVER_LAUNCH "ROVER_LAUNCH"

file_t tasks[] = 
{
  { .pid = -1, .name = "./motor_control"},
  { .pid = -1, .name = "./servo_control"},
  { .pid = -1, .name = "./manager"},
  { .pid = -1, .name = "./server"},
};

static int process_amount = sizeof(tasks)/sizeof(tasks[0]);

static void init_fail(const file_t *process, int process_amount);

int main()
{
  int ret;

  for(int i = 0; i < (process_amount); i++){
    tasks[i].pid = fork();
    if(tasks[i].pid == 0){
      char buffer[128] = {0};
      snprintf(buffer, sizeof(buffer), "%s pid[%d]", tasks[i].name, getpid());
      log(ROVER_LAUNCH, buffer);
      execv(tasks[i].name, NULL);
    }
    else if(tasks[i].pid == -1){
      init_fail(tasks, process_amount);
    }else{
      continue;
    }
  }

  ret = writefile("pid_processes.dat", tasks, process_amount);
  if(ret){
    log(ROVER_LAUNCH, "Error to write file.");
    return EXIT_FAILURE;
  }
  exit(0);
}

static void init_fail(const file_t *process, int process_amount)
{
  if(!process){
  
  }

  if(process_amount <= 0){
  
  }

  for(int i = 0; i < process_amount; i++){
    if(process[i].pid != -1){
      kill(process[i].pid, SIGKILL);
    }
  }
  exit(1);

}
