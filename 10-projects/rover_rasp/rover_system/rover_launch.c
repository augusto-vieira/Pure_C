#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

const char *tasks[] = {
  "./motor_control",
  "./servo_control",
  "./manager",
  "./server"
};

int main()
{
  pid_t process_ret;

  for(int i = 0; i < ((sizeof(tasks))/sizeof(tasks[0])); i++){
    process_ret = fork();
    if(process_ret == 0){
      printf("launching %s\n", tasks[i]);
      execv(tasks[i], NULL);
    }
    else if(process_ret == -1){
      kill(process_ret, SIGKILL);
    }else{
      continue;
    }
  }
}
