#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>

static int ctx_speed = 0;
static int motors_init();
static int motor_setpower(int motor_id, int power);


int motors_init()
{
  int ret = -1;

  ret = wiringPiSetup();
  if(ret == -1){
    return ret;
  }
  return ret;
}

int motor_setpower(int motor_id, int power)
{
  if(power > 1023)
    power = 1023;
  ctx_speed = power;
  pwmWrite(motor_id, power);

  return 0;
}

int go_forward(int speed)
{
  motor_setpower(MOTOR_LEFT, speed);
  motor_setpower(MOTOR_RIGHT, speed);
  return 0;
}

int turn_left(void)
{
  motor_setpower(MOTOR_RIGHT, ctx_speed / 3); 
  return 0;
}

int turn_right(void)
{
  motor_setpower(MOTOR_LEFT, ctx_speed / 3); 
  return 0;
}

int go_stop()
{
  motor_setpower(MOTOR_LEFT, 0);
  motor_setpower(MOTOR_RIGHT, 0);
  return 0;

}

int main()
{

}
