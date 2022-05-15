anchal0404/Sun-Tracking-Solar-Panel



#include <Servo.h>
Servo servo ;
int LDRE = 0;
int LDRW = 1;
int E = 0;
int W = 0;
int error = 0;
int calibration = 600;
int servoposition = 90;
void setup()
{
  servo.attach(9);
}
void loop()
{
  east = calibration + analogRead(LDRE);
  west = analogRead(LDRE);
  if (E < 350 && W < 350)
  {
    while (servoposition <= 150)
    {
      servoposition++;
      servo.write(servoposition);
      delay(100);
    }
  }
  error = E - W;
  if (error > 15)
  {
    if (servoposition <= 150)
    {
      servoposition++;
      servo.write(servoposition);
    }
  }
  else if (error < -15)
  {
    if (servoposition > 20)
    {
      servoposition--;
      servo.write(servoposition);
    }
  }
  delay(100);
}