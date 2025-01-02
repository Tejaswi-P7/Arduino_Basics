const int motor1PWM = 10;  // PWM control pin for motor 1
const int motor1Dir1 = 8; // Direction control pin 1 for motor 1
const int motor1Dir2 = 7; // Direction control pin 2 for motor 1

const int motor2PWM = 9;  // PWM control pin for motor 2
const int motor2Dir1 = 5; // Direction control pin 1 for motor 2
const int motor2Dir2 = 4; // Direction control pin 2 for motor 2
int trig = 12;
int echo = 11;

int timeInMicro;
int distanceInCm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);  // Corrected typo
  pinMode(echo, INPUT);   // Corrected typo
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1Dir1, OUTPUT);
  pinMode(motor1Dir2, OUTPUT);

  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2Dir1, OUTPUT);
  pinMode(motor2Dir2, OUTPUT);
}

void loop() {
  // to send signals
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // to receive signals 
  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = timeInMicro / 29 / 2;

  Serial.println(distanceInCm);  // Corrected typo
  delay(100);

  if(distanceInCm < 15)
{
  moveForward();
}
else
{
  stopMotors();
}

delay(100);
}

void moveForward() {
  digitalWrite(motor1Dir1, HIGH);
  digitalWrite(motor1Dir2, LOW);
  analogWrite(motor1PWM, 255);

  digitalWrite(motor2Dir1, HIGH);
  digitalWrite(motor2Dir2, LOW);
  analogWrite(motor2PWM, 255);
  Serial.println("going");
  
  delay(2000);
}

void stopMotors() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, LOW);
  analogWrite(motor1PWM, 0);

  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, LOW);
  analogWrite(motor2PWM, 0);
}


