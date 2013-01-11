//int potPin = 2;    // select the input pin for sound sensor  
int ledPin = 0;   // select the pin for the LED  
int val = 0;  
int amp = 0;  
  
  int _mic = 3;
  
void setup() {  
pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT  
//Serial.begin(9600);
}  
  
void loop() {  
  val = analogRead(_mic);  
  amp = (val >= 512) ? val - 512 : 512 - val; 
  if (amp > 100)
  {
    analogWrite(ledPin, amp);
    delay(1);
  }
  else
  {
    analogWrite(ledPin, 0);
  }
  //Serial.println(amp);
}  
