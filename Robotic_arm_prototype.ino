#include <Servo.h>

// Servo object declarations
Servo baseServo;      // Black Servo 1
Servo shoulderServo;  // Black Servo 2
Servo elbowServo;     // Blue Servo 1
Servo gripperServo;   // Blue Servo 2

// Pin Assignments
const int PIN_BASE     = 6;   // Black Servo 1 (D6)
const int PIN_SHOULDER = 9;   // Black Servo 2 (D9)
const int PIN_ELBOW    = 10;  // Blue Servo 1  (D10)
const int PIN_GRIPPER  = 11;  // Blue Servo 2  (D11)

// Smooth motion to avoid current spikes on laptop USB
void smoothMove(Servo &motor, int targetAngle, int stepDelay = 25) {
  int currentAngle = motor.read();
  if (currentAngle < targetAngle) {
    for (int angle = currentAngle; angle <= targetAngle; angle++) {
      motor.write(angle);
      delay(stepDelay);
    }
  } else {
    for (int angle = currentAngle; angle >= targetAngle; angle--) {
      motor.write(angle);
      delay(stepDelay);
    }
  }
}

void setup() {
  // Staggered attachment to prevent high startup current
  baseServo.attach(PIN_BASE);
  baseServo.write(90);       // Home: Center
  delay(300);

  shoulderServo.attach(PIN_SHOULDER);
  shoulderServo.write(90);   // Home: Upright
  delay(300);

  elbowServo.attach(PIN_ELBOW);
  elbowServo.write(90);      // Home: Center
  delay(300);

  gripperServo.attach(PIN_GRIPPER);
  gripperServo.write(30);    // Home: Open claw
  delay(1000);
}

void loop() {
  // 1. Base moves right
  smoothMove(baseServo, 50);
  delay(500);

  // 2. Shoulder bends forward
  smoothMove(shoulderServo, 70);
  delay(500);

  // 3. Elbow reaches down
  smoothMove(elbowServo, 115);
  delay(500);

  // 4. Gripper closes (Grab)
  smoothMove(gripperServo, 85);
  delay(800);

  // 5. Shoulder & Elbow lift back up
  smoothMove(shoulderServo, 90);
  delay(300);
  smoothMove(elbowServo, 90);
  delay(500);

  // 6. Base rotates to drop position (Left)
  smoothMove(baseServo, 130);
  delay(500);

  // 7. Shoulder reaches to drop
  smoothMove(shoulderServo, 70);
  delay(300);
  smoothMove(elbowServo, 110);
  delay(500);

  // 8. Gripper opens (Release)
  smoothMove(gripperServo, 30);
  delay(800);

  // 9. Return to default Home position
  smoothMove(shoulderServo, 90);
  delay(300);
  smoothMove(elbowServo, 90);
  delay(300);
  smoothMove(baseServo, 90);
  delay(2500); // Wait 2.5s before repeating loop
}
