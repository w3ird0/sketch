
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoPin = 41;
int servoPos = 0;
int _sMid = 94;
int _sRight = 12;
int _sLeft = 180;
int Trig_pin = 30;
int Echo_pin = 31;
int _mLeft1 = 22;
int _mLeft2 = 23;
int _mRight1 = 24;
int _mRight2 = 25;
int LeftDistance =0;
int RightDistance =0;
int minsDist = 40;
int sideMinsDist = 30;
int _dist = 100;
int dir = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);
  pinMode(_mLeft1, OUTPUT);
  pinMode(_mLeft2, OUTPUT);
  pinMode(_mRight1, OUTPUT);
  pinMode(_mRight2, OUTPUT);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  middle();
}

void loop()
{
  //Serial.println(_dist);  
  if (_dist <= minsDist)
  {
    //Serial.println(_dist + 10000); 
    //delay(5);
    //_dist = distance(); 
    //if (_dist <= minsDist)
    //{ 
      //Serial.println(F("STOP MOVE!"));
      stopmove();
      delay(500);
      dir = 0;
      //Serial.println(F("SCAN NOW!"));
      scan();      
      delay(1000);
      turnNow();
      delay(1000);
      _dist=100;
    //}
  } 
  else
  {
    _dist = distance(); 
   //Serial.println(dist);
   //delay(500);
  }
  
  if (dir != 1)
  {
   forward(); 
   dir = 1;
  }
  
}

void turnNow()
{
  if (LeftDistance < sideMinsDist && RightDistance < sideMinsDist)
  {
   backward(); 
   delay(1000);
   stopmove();
   scan();
   turnNow();
   //return;
  }
  
  if (LeftDistance > RightDistance)
  {
    //Serial.println(F("Turn Left")); 
    turnleft(700);
  }
  else
  {
    //Serial.println(F("Turn Right")); 
    turnright(700);
  }
}



void scan()
{
  //Serial.begin(9600);  
  RTurn(_sMid, _sRight, true);  
  delay(1000);
  LTurn(_sRight, _sLeft, true);
  delay(1000);
  RTurn(_sLeft, _sMid, false);
  delay(1000);
}

void middle()
{
  //Serial.println(F("middle"));
  if (servoPos >= _sMid)
  {
    RTurn(_sMid,_sRight, false);
  } 
   else if (servoPos >= _sMid) {
    LTurn(_sRight,_sMid, false);
  }
  else
  {}
}

void LTurn(int startPos, int endPos, boolean setDistance)
{
  //Serial.println(F("turnRight"));
  for (int i=startPos;i<=endPos;i=i+2)
  {
   myservo.write(i);
   delay(20);
   if (setDistance) LeftDistance = distance(); 
   //LeftDistance = distance(); 
  }
}

void RTurn(int startPos, int endPos, boolean setDistance)
{
  //Serial.println(F("turnLeft"));
  for (int i=startPos;i>=endPos;i=i-2)
  {
   myservo.write(i);
   delay(20);
   if (setDistance) RightDistance = distance(); 
  }
}

void forward()
{
  moveMotor(HIGH, LOW, HIGH, LOW);
}

void turnright(int sec)
{
  moveMotor(HIGH, LOW, LOW, HIGH);
  delay(sec);
  stopmove();
}

void turnleft(int sec)
{
  moveMotor(LOW, HIGH, HIGH, LOW);  
  delay(sec);
  stopmove();
}

void backward()
{
  moveMotor(LOW, HIGH, LOW, HIGH);
}

void stopmove()
{
  moveMotor(LOW, LOW, LOW, LOW);
}

void moveMotor(int l1, int l2, int r1, int r2)
{
  digitalWrite(_mLeft1, l1);
  digitalWrite(_mLeft2, l2);
  digitalWrite(_mRight1, r1);
  digitalWrite(_mRight2, r2);
}
int distance()
{
  long duration = timing();
  int dst = (duration /29 / 2); //cm
  //Serial.println(dst);
  //delay(100); 
  return dst;
}

long timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trig_pin, LOW);
  return pulseIn(Echo_pin,HIGH);
}
