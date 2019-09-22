#include <stdio.h>
#include <stdlib.h>
#include <servo.h>

int main()
{
  SERVO_init();

  SERVO_setAngle(CENTER);

  for(int i = LEFT; i < RIGHT; i++)
  {
    SERVO_setAngle(i);
  }

  for(int i = RIGHT; i >= LEFT; i--)
  {
    SERVO_setAngle(i);
  }

  SERVO_setAngle(CENTER);
  

  return EXIT_SUCCESS;
}

