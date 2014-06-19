#include <Servo.h>    // Use Servo library, included with IDE

Servo myServo;        // Create Servo object to control the servo 

void setup() { 
  myServo.attach(9);  // Servo is connected to digital pin 9 


}
void loop() { 
  int counterclockhold = 2000;
  int clockwisehold = 500;
  int neutralhold = 5000;
  myServo.write(180);   // Rotate servo counter clockwise
  delay(counterclockhold);          // Wait specified time
  myServo.write(90);     // Rotate servo to neutral
  delay(neutralhold);
  myServo.write(0);    // Rotate servo to clockwise
  delay(clockwisehold);         // Wait specified time
  myServo.write(90);
  delay(neutralhold);
}
