#include <stdlib.h>
#include <wiringPi.h>
#include <servo.h>

int SERVO_init(void)
{

  int ret = -1;
  ret = wiringPiSetupGPIO();
  if(ret){
    return EXIT_FAILURE;
  }
  pinMode(SERVO_PIN, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(PWM_RANGE);
  pwmSetClock(PWM_CLOCK);
  return EXIT_SUCCESS;
}

int SERVO_setAngle(int angle)
{
  pwmWrite(SERVO_PIN, angle); 
  return EXIT_SUCCESS;
}
