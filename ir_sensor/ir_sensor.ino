
int IRPin = 8; 
int IRReading; // Left Reading

void setup(void) {
  Serial.begin(9600); // For debugging purposes
  //pinMode(IRPin, INPUT);
}

void loop(void) {
  IRReading = analogRead(IRPin);
  Serial.println
  (IRReading);
  delay(1000);
}

