#include <Servo.h>

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo9;
Servo myservo10;
Servo myservo11;
Servo myservo12;

void setup() {
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  myservo5.attach(5);
  myservo9.attach(9);
  myservo10.attach(10);
  myservo11.attach(11);
  myservo12.attach(12);

  delay(500);

  // Move servos to initial positions
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(90);
  myservo9.write(90);
  myservo10.write(90);
  myservo11.write(90);
  myservo12.write(90);
  delay(1000);
}

void loop() {
  moveServosToPosition(180); // Move servos to 180 degrees
  delay(2000); // Wait for 1 second
  moveServosToPosition(90); // Move servos back to 0 degrees
  delay(2000); // Wait for 1 second
}

// Function to move all servos to a specified position
void moveServosToPosition(int angle) {
 myservo2.write(angle); //err
  myservo3.write(angle); //er
  myservo4.write(angle);
  myservo5.write(angle);
  myservo9.write(angle);
  myservo10.write(angle);
  myservo11.write(angle);
  myservo12.write(angle); 
}