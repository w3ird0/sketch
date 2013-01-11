// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoPin = 40;
int servoPos = 0;
int _sMid = 94;
int _sRight = 12;
int _sLeft = 180;
 
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  middle();
} 
 
void loop() 
{ 
  delay(5000);
  scan();
} 

void scan()
{
  Serial.begin(9600);  
  RTurn(_sMid, _sRight);  
  delay(1000);
  LTurn(_sRight, _sLeft);
  delay(1000);
  RTurn(_sLeft, _sMid);
  delay(1000);
}

void middle()
{
  //Serial.println(F("middle"));
  if (servoPos >= _sMid)
  {
    RTurn(_sMid,_sRight);
  } 
   else if (servoPos >= _sMid) {
    LTurn(_sRight,_sMid);
  }
  else
  {}
}

void LTurn(int startPos, int endPos)
{
  //Serial.println(F("turnRight"));
  for (int i=startPos;i<=endPos;i=i+2)
  {
   myservo.write(i);
   delay(20);
  }
}

void RTurn(int startPos, int endPos)
{
  Serial.println(F("turnLeft"));
  for (int i=startPos;i>=endPos;i=i-2)
  {
   myservo.write(i);
   delay(20);
  }
}
