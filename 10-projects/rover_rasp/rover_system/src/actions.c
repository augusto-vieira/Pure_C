#include <string.h>
#include <motors.h>

typedef void *(*ActionFunction)(void *args);

const char *action_list[] =
{
  "stop\n",
  "left\n",
  "right\n",
  "go\n"
};

const int action_list_len = sizeof(action_list)/sizeof(action_list[0]) ;

static const ActionFunction actions[] = 
{
  motor_stop,
  motor_turn_left,
  motor_turn_right,
  motor_forward
};

int action_select(const char *action, void *args)
{
  void *ret;
  for (int i = 0; i < action_list_len; i++)
  {
    if(strcmp(action, action_list[i]) == 0)
    {
      ret = actions[i](args);
      break;
    }
  }
  if(ret == NULL)
    return 0;
  else
    return *(int *)ret;
}
