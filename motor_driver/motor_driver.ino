
int _mLeft1 = 31;
int _mLeft2 = 33;
int _mRight1 = 39;
int _mRight2 = 35;

void setup()
{
  pinMode(_mLeft1, OUTPUT);
  pinMode(_mLeft2, OUTPUT);
  pinMode(_mRight1, OUTPUT);
  pinMode(_mRight2, OUTPUT);
}

void loop()
{
  turnright(100);
  //moveAnalogMotor(250, 0, 250, 130);
  //forward();
  delay(2000);
  stopmove();
  delay(2000);
  //delay(2000);
  //backward();
  //delay(2000);
  //stopmove();
  //delay(2000);
  //turnleft();
  //delay(2000);
  //stopmove();
  //delay(2000);
  //turnright();
  //delay(2000);
  //stopmove();
  //delay(2000);
}


void forward()
{
  moveMotor(LOW, HIGH, LOW, HIGH);
}

void turnleft(int sec)
{
  moveMotor(HIGH, LOW, LOW, HIGH);
  delay(sec);
  stopmove();
}

void turnright(int sec)
{
  moveMotor(LOW, HIGH, HIGH, LOW);
  delay(sec);
  stopmove();
}

void backward()
{
  moveMotor(HIGH, LOW, HIGH, LOW);
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
