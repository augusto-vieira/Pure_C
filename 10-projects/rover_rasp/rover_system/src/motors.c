#include <motors.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <wiringPi.h>
//#include <softPwm.h>

static int ctx_speed = 0;
static int motors_init();
static int motor_setpower(int motor_id, int power);


int motors_init()
{
  int ret = -1;

  //ret = wiringPiSetup();
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
  //pwmWrite(motor_id, power);

  return 0;
}


void *motor_stop(void *args)
{
  (void)args;
  //motor_setpower(MOTOR_LEFT, 0);
  //motor_setpower(MOTOR_RIGHT, 0);
  printf("Motor stop.\n");
  return NULL;
}

void *motor_turn_left(void *args)
{
  (void)args;
//  motor_setpower(MOTOR_RIGHT, ctx_speed / 3); 
  printf("Motor Turning Left.\n");
  return NULL;
}

void *motor_turn_right(void *args)
{
  (void)args;
 // motor_setpower(MOTOR_LEFT, ctx_speed / 3); 
  printf("Motor Turning Right.\n");
  return NULL;
}

void *motor_forward(void *args)
{
  int *speed = (int *)args;
  printf("Motor Forward: %d\n");
  if(speed == NULL)
    return speed;
  printf("Motor Forward: %d\n", speed);
  //motor_setpower(MOTOR_LEFT, speed);
  //motor_setpower(MOTOR_RIGHT, speed);
  return NULL;
}
