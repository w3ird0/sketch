#include <Stepper.h>
// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 5, 3,4,2);

void setup() {
  // set the motor speed at 60 RPMS:
  stepper.setSpeed(150);

  // Initialize the Serial port:
  Serial.begin(9600);

}

void loop() {
  // Step forward 100 steps:
  Serial.println("Forward");
  stepper.step(200);
  //delay(500);

  // Step backward 100 steps:
  //Serial.println("Backward");
  //stepper.step(-200);
  //delay(500); 

}

