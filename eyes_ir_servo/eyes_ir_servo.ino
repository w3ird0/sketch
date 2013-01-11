#include <Servo.h> 

Servo myservo; 

int rightIRPin = 0; 
int leftIRPin = 1; 
int rIRReading; // Right Reading
int lIRReading; // Left Reading

int servoPin = 9;
int servoLoc = 0;
void setup(void) {
  //Serial.begin(9600); // For debugging purposes
  pinMode(rightIRPin, INPUT);
  pinMode(leftIRPin, INPUT);
  myservo.attach(servoPin); 
}

void loop(void) {
  int valRight = analogRead(rightIRPin);
  int valLeft = analogRead(leftIRPin);  
  valRight = constrain(valRight, 15, 600);  
  rIRReading = map(valRight, 15, 600, 0, 1024);
  
  valLeft = constrain(valLeft, 15, 600);  
  lIRReading = map(valLeft, 15, 600, 0, 1024);

  //Serial.println(rIRReading);
  //Serial.println(lIRReading);
  
  if (rIRReading > 50 && lIRReading > 50)
  {
  }
  else
  {
    if (rIRReading > 50)
    {
      myservo.write(setServoLoc(0));
    }
    if (lIRReading > 50)
    {
      myservo.write(setServoLoc(1));
    }
  }
  

  delay(50);
}

int setServoLoc(int dir)
{
  if (dir == 0)
  {
   if (servoLoc < 180) 
   {
     servoLoc = servoLoc + 20;
     return servoLoc;
   }
  } else {
   if (servoLoc > 0) 
   {
     servoLoc = servoLoc - 20;
     return servoLoc;
   }
  }
}

