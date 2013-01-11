
int IRPin = 0; 
int IRReading; // Left Reading
//int ledPin = 8;

void setup(void) {
  Serial.begin(9600); // For debugging purposes
  pinMode(IRPin, INPUT);
  //pinMode(ledPin, OUTPUT);
}

void loop(void) {
  int val = analogRead(IRPin);
  //val = constrain(val, 30, 250);  
  //IRReading = map(val, 30, 200, 0, 255);
  //Serial.println(IRReading);
  //analogWrite(ledPin, IRReading);
  Serial.println(val);
  delay(500);
}

