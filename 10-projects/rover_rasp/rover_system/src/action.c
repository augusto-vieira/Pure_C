#include <string.h>
#include <motors.h>

typedef void *(*ActionFunction)(void *args);

static const ActionFunction actions[] = 
{
  motor_stop,
  motor_turn_left,
  motor_turn_right,
  motor_forward
};

int action_select(const char *action)
{
  void *ret;
  for (int i = 0; i < action_list_len; i++)
  {
    if(strcmp(action, action_list[i] == 0))
    {
      ret = actions[i]();
    }
  }
  return *(int *)ret;
}
