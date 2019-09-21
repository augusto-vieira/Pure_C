#include <stdio.h>
#include <stdlib.h>
#include <servo.h>

int main()
{
  SERVO_init();

  SERVO_setAngle(CENTER);

  for(int i = 0; i < RIGHT; i++)
  {
    SERVO_setAngle(i);
  }

  for(int i = LEFT; i > 0; i-=5)
  {
    SERVO_setAngle(i);
  }

  SERVO_setAngle(CENTER);
  

  return EXIT_SUCCESS;
}

