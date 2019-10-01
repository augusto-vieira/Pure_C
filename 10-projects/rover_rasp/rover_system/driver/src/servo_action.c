#include <servo_action.h>
#include <servo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *movements[] = {
  "center",
  "left",
  "right"
};

static int movements_amount = sizeof(movements) / sizeof(movements[0]);

static int servo_action(const char *command);

int servo_action_select(const char *action, int action_len)
{
  char command[10] = {0};
  char data[10] = {0};
  char *p = NULL;
  int position = 0;
  int ret = 0;

  sscanf(action, "%s", command);

  if(!strncmp(command, "move", 4)){
    p = action + strlen(command) + 1; //points to next string
    strncpy(data, p, 10);
    //call functions
    ret = servo_action(p);

  }else if(!strncmp(command, "graus", 5)){
    sscanf(action, "%s %d", data, &position);
    //call function
    ret = SERVO_setAngle(position);
  }

  return ret;
}

static int servo_action(const char *command)
{
  int ret = 1;
  for(int i = 0; i < movements_amount; i++){
    if(strncmp(command, "center", 5)){
      ret = SERVO_setAngle(CENTER);
      break;
    }else if(!strncmp(command, "left", 4)){
      ret = SERVO_setAngle(LEFT);
      break;
    }else if(!strncmp(command, "right", 5)){
      ret = SERVO_setAngle(RIGHT);
      break;
    }
  }

  return ret;
}
