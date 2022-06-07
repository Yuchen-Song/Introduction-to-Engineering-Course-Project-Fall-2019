#include<Servo.h>
Servo robotarm;
void setup() {
  // put your setup code here, to run once:
 robotarm.attach(9);
}

void grab()
{
  for(int i=160;i>=95;i--)
  {
    robotarm.write(i);
    delay(10);
  }
  delay(1000);
}
void drop()
{
  for(int i=95;i<=160;i++)
  {
    robotarm.write(i);
    delay(10);
  }
  delay(1000);
}
