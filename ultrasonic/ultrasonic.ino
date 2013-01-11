
int Trig_pin = 30;
int Echo_pin = 31;

void setup() {
   pinMode(Trig_pin,OUTPUT);
   pinMode(Echo_pin,INPUT);
   Serial.begin(9600);
}

void loop()
{
  long duration = timing();
  Serial.println(duration /29 / 2); //cm
  //duration / 74 / 2; //inches
  
  delay(100);
}

long timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  return pulseIn(Echo_pin,HIGH);
}




