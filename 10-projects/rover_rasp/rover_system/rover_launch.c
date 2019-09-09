#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <log.h>

#define ROVER_LAUNCH "ROVER_LAUNCH"

typedef struct process_table{
  pid_t process_id;
  char task_name[20];
}process_table_t;

process_table_t tasks[] = 
{
  { .process_id = -1, .task_name = "./motor_control"},
  { .process_id = -1, .task_name = "./servo_control"},
  { .process_id = -1, .task_name = "./manager"},
  { .process_id = -1, .task_name = "./server"},
};

static int process_amount = sizeof(tasks)/sizeof(tasks[0]);

static void init_fail(const process_table_t *process, int process_amount);

int main()
{

  for(int i = 0; i < (process_amount); i++){
    tasks[i].process_id = fork();
    if(tasks[i].process_id == 0){
      char buffer[128] = {0};
      snprintf(buffer, sizeof(buffer), "%s pid[%d]", tasks[i].task_name, getpid());
      log(ROVER_LAUNCH, buffer);
      execv(tasks[i].task_name, NULL);
    }
    else if(tasks[i].process_id == -1){
      init_fail(tasks, process_amount);
    }else{
      continue;
    }
  }
  exit(0);
}

static void init_fail(const process_table_t *process, int process_amount)
{
  if(!process){
  
  }

  if(process_amount <= 0){
  
  }

  for(int i = 0; i < process_amount; i++){
    if(process[i].process_id != -1){
      kill(process[i].process_id, SIGKILL);
    }
  }
  exit(1);

}
