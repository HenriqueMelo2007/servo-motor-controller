#include <Servo.h>

#define btnState 10

Servo motor;
int ang = 0;

int lastValue = 0;

void btnMonitor();

void setup()
{
  motor.attach(9);

  pinMode(btnState, INPUT);
}

void loop()
{
  btnMonitor();
  motor.write(ang);
}

void btnMonitor()
{
  int state = digitalRead(btnState);

  if (state == 1 && lastValue == 0)
  {
    if (ang < 180)
    {
      ang += 45;
    }
    else
    {
      ang = 0;
    }
  }

  lastValue = state;
}