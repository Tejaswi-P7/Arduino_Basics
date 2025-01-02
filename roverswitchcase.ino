// Define the pins connected to the L298N motor driver
const int motor1PWM = 10;  // PWM control pin for motor 1
const int motor1Dir1 = 8; // Direction control pin 1 for motor 1
const int motor1Dir2 = 7; // Direction control pin 2 for motor 1

const int motor2PWM = 9;  // PWM control pin for motor 2
const int motor2Dir1 = 5; // Direction control pin 1 for motor 2
const int motor2Dir2 = 4; // Direction control pin 2 for motor 2

void setup() {
  // Set the motor control pins as outputs
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1Dir1, OUTPUT);
  pinMode(motor1Dir2, OUTPUT);

  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2Dir1, OUTPUT);
  pinMode(motor2Dir2, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 's': // Stop
        stopMotors();
        break;
      case 'f': // Move forward
        moveForward();
        break;
      case 'b': // Move backward
        moveBackward();
        break;
      case 'r':  //move right
        Right();
        break;
      case 'l':  //move right
        Left();
        break;
      
    }
  }
}

// Function to run both motors forward
void moveForward() {
  digitalWrite(motor1Dir1, HIGH);
  digitalWrite(motor1Dir2, LOW);
  analogWrite(motor1PWM, 255);

  digitalWrite(motor2Dir1, HIGH);
  digitalWrite(motor2Dir2, LOW);
  analogWrite(motor2PWM, 255);
  
  delay(2000);
}
 void Left(){

  digitalWrite(motor1Dir1,HIGH);
  digitalWrite(motor1Dir2,LOW);
  analogWrite(motor1PWM,255);

  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, HIGH);
  analogWrite(motor2PWM, 255);
  
 }
 
 void Right(){

  digitalWrite(motor1Dir1,LOW);
  digitalWrite(motor1Dir2,HIGH);
  analogWrite(motor1PWM,255);

  digitalWrite(motor2Dir1, HIGH);
  digitalWrite(motor2Dir2, LOW);
  analogWrite(motor2PWM, 255);
  
 }
// Function to run both motors backward
void moveBackward() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, HIGH);
  analogWrite(motor1PWM, 255);

  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, HIGH);
  analogWrite(motor2PWM, 255);
}

// Function to stop both motors
void stopMotors() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, LOW);
  analogWrite(motor1PWM, 0);

  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, LOW);
  analogWrite(motor2PWM, 0);
}