
int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
int ledLevel = 0;

void setup()
{
 pinMode(switchPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

void loop()
{
  boolean bSwitch = digitalRead(switchPin);
  if (bSwitch == HIGH && lastButton == LOW)
  {
    ledLevel = ledLevel + 51;
    lastButton = HIGH;
  }
  else
  {
    lastButton = bSwitch;
  }
  if (ledLevel > 255) ledLevel = 0;
  analogWrite(ledPin, ledLevel);
}


/*
int switchPin = 8;
int ledPin = 13;
boolean lastButton = LOW;
boolean ledOn = false;

void setup()
{
 pinMode(switchPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

void loop()
{
  boolean bSwitch = digitalRead(switchPin);
  if (bSwitch == HIGH && lastButton == LOW)
  {
    ledOn = !ledOn;
    lastButton = HIGH;
  }
  else
  {
    lastButton = bSwitch;
  }
  digitalWrite(ledPin, ledOn);
}
*/
/*
// for press on / release off
int switchPin = 8;
int ledPin = 13;

void setup()
{
 pinMode(switchPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

void loop()
{
  if (digitalRead(switchPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
*/
