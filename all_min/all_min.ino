
#include <Servo.h> 

//CLASS
Servo MyServo;  // create servo object to control a servo 

//PINS
int ServoPin = 41;
int TrigPin = 30;
int EchoPin = 31;
int MotorLeft1Pin = 22;
int MotorLeft2Pin = 23;
int MotorRight1Pin = 24;
int MotorRight2Pin = 25;

//VARIABLES
int _servoPosition = 0;
int _servoMiddle = 94;
int _servoRight = 12;
int _servoLeft = 180;
int _leftDistance =0;
int _rightDistance =0;
int _minimumDistance = 20;
int _minimumSideDistance = 20;
int _currentDistance = 100;
int _direction = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(MotorLeft1Pin, OUTPUT);
  pinMode(MotorLeft2Pin, OUTPUT);
  pinMode(MotorRight1Pin, OUTPUT);
  pinMode(MotorRight2Pin, OUTPUT);
  MyServo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object 
  ServoMiddleStop();
}

void loop()
{
   
  if (_currentDistance <= _minimumDistance)
  {
    Serial.print(F("CURRENT DISTANCE = ")); 
    Serial.println(_currentDistance); 
    //Serial.println(_currentDistance + 10000); 
    //delay(5);
    //_currentDistance = PingDistance(); 
    //if (_currentDistance <= _minimumDistance)
    //{ 
      Serial.println(F("STOP MOVE!"));
      MotorStop();
      delay(100);
      _direction = 0;
      Serial.println(F("SCAN NOW!"));
      ServoScan();      
      delay(1000);
      MotorStartTurn();
      delay(1000);
      _currentDistance=100;
    //}
  } 
  else
  {
    _currentDistance = PingDistance(); 
   //Serial.println(dist);
   //delay(500);
  }
  
  if (_direction != 1)
  {
   MotorForward(); 
   _direction = 1;
  }
  
}

void MotorStartTurn()
{
  if (_leftDistance < _minimumSideDistance && _rightDistance < _minimumSideDistance)
  {
   MotorBackward(); 
   delay(1000);
   MotorStop();
   ServoScan();
   MotorStartTurn();
   //return;
  }
  
  if (_leftDistance > _rightDistance)
  {
    Serial.println(F("Turn Left")); 
    MotorTurnLeft(600);
  }
  else
  {
    Serial.println(F("Turn Right")); 
    MotorTurnRight(700);
  }
}



void ServoScan()
{
  //Serial.begin(9600);  
  ServoRightTurn(_servoMiddle, _servoRight, true);  
  delay(1000);
  ServoLeftTurn(_servoRight, _servoLeft, true);
  delay(1000);
  ServoRightTurn(_servoLeft, _servoMiddle, false);
  delay(1000);
}

void ServoMiddleStop()
{
  //Serial.println(F("ServoMiddleStop"));
  if (_servoPosition >= _servoMiddle)
  {
    ServoRightTurn(_servoMiddle,_servoRight, false);
  } 
   else if (_servoPosition >= _servoMiddle) {
    ServoLeftTurn(_servoRight,_servoMiddle, false);
  }
  else
  {}
}

void ServoLeftTurn(int startPos, int endPos, boolean setDistance)
{
  for (int i=startPos;i<=endPos;i=i+5)
  {
   MyServo.write(i);
   delay(20);
   if (setDistance) _leftDistance = PingDistance();    
  }
  if (setDistance) 
   {
     Serial.print(F("Left Distance = "));
     Serial.println(_leftDistance); 
   }  
}

void ServoRightTurn(int startPos, int endPos, boolean setDistance)
{ 
  for (int i=startPos;i>=endPos;i=i-5)
  {
   MyServo.write(i);
   delay(20);
   if (setDistance) _rightDistance = PingDistance(); 
  }
  if (setDistance)
  {
    Serial.print(F("Right Distance = "));
    Serial.println(_rightDistance);  
  }  
}

void MotorForward()
{
  SetMotor(HIGH, LOW, HIGH, LOW);
}

void MotorTurnRight(int sec)
{
  SetMotor(LOW, HIGH, HIGH, LOW);  
  delay(sec);
  MotorStop();
}

void MotorTurnLeft(int sec)
{
  SetMotor(HIGH, LOW, LOW, HIGH); 
  delay(sec);
  MotorStop();
}

void MotorBackward()
{
  SetMotor(LOW, HIGH, LOW, HIGH);
}

void MotorStop()
{
  SetMotor(LOW, LOW, LOW, LOW);
}

void SetMotor(int l1, int l2, int r1, int r2)
{
  digitalWrite(MotorLeft1Pin, l1);
  digitalWrite(MotorLeft2Pin, l2);
  digitalWrite(MotorRight1Pin, r1);
  digitalWrite(MotorRight2Pin, r2);
}
int PingDistance()
{
  long duration = PingTiming();
  int dst = (duration /29 / 2); //cm
  //Serial.println(dst);
  //delay(100); 
  return dst;
}

long PingTiming()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(TrigPin, LOW);
  return pulseIn(EchoPin,HIGH);
}
