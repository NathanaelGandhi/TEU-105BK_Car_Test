/* Nathanael Gandhi Nov 2019 */

//STEERING POSITIONS:
//Neutral:90
//Left: 63
//Right: 120
 
//THROTTLE POSITIONS
//Full Reverse: 0
//Full Ahead: 180
//Normal Reverse: 75
//Normal Ahead: 105
//Neutral: 98

// ESC IS IN REVERSE MODE, therefore actual outcome is opposite to intended, Serial output reflects ACTUAL outcome.
 
#include <Servo.h>
 
Servo steering;
Servo throttle;
Servo alarm;

int AccelerationSpeed = 105;
int ReverseSpeed = 75;
int SpeedNeutral = 98;
int StoppedTop = 103;
int StoppedBot = 93;
int SteeringNeutral = 90;
int LeftTurn = 120;
int RightTurn = 63;
 
 
void setup() {
  steering.attach(9);
  throttle.attach(10);
  alarm.attach(11);
  Serial.begin(9600);
}
 
void Stop() {
  throttle.write(SpeedNeutral);
  Serial.println("Throttle at neutral");
  Serial.println('\n');
}
 
void loop() {
  alarm.write(90);
  steering.write(SteeringNeutral);
  throttle.write(SpeedNeutral);
  int i = SpeedNeutral;
  int j = SteeringNeutral;
  bool iDir = true;
  bool jDir = true;
  bool drive = true;
  int loop = 0;
  Serial.println("Starting TEU-105BK Car Test Sequence");
  delay(3000);
  while(drive)
  {
    if(i==AccelerationSpeed)
    {
      iDir = false;
    }
    if(i==ReverseSpeed)
    {
      iDir = true;
    }
    if(j==RightTurn)
    {
      jDir = true;
    }
    if(j==LeftTurn)
    {
      jDir = false;
    }
    if(iDir)
    {
      i++;
    }
    else
    {
      i--;
    }
    if(jDir)
    {
      j++;
    }
    else
    {
      j--;
    }
    Serial.print("Loop: ");Serial.print(loop);
    if(j>SteeringNeutral)
    {
      Serial.print(" Left : ");
    }
    else
    {
      Serial.print(" Right: ");
    }
    Serial.print(j);
        if(i<StoppedTop && i >= StoppedBot)
    {
      Serial.print(" Stopped: ");
    }
    else
    {
      if(i>StoppedBot)
      {
        Serial.print(" Backwards: ");
      }
      else
      {
        Serial.print(" Forwards: ");
      }
    }
    Serial.println(i);
    
    steering.write(j);
    throttle.write(i);
    loop++;
    delay(500);
  }
  Stop();
}
