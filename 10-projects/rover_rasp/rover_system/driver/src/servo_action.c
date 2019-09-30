#include <servo_action.h>
#include <stdio.h>
#include <stdlib.h>

typedef int(*ServoActionExec)(void *args);

int servo_action_select(const char *action, int action_len)
{
  char command[10];
  char data[10];
  char *p = NULL;
  int position;

  sscanf(action, "%s", command);

  if(!strncmp(command, "move", 4)){
    p = action + strlen(command) + 1; //points to next string


  }else if(!strncmp(command, "graus", 5)){

  }
}


