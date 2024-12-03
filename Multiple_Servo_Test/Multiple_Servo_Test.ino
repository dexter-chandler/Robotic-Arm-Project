#include <ESP32Servo.h>

static const int shoulderPin = 23;
static const int lowElbowPin = 22;
static const int highElbowPin = 01;
static const int highWristPin = 03;
static const int lowWristPin = 21;
static const int clawPin = 19;
Servo shoulder;
Servo lowElbow;
Servo highElbow;
Servo highWrist;
Servo lowWrist;
Servo claw;

void setup() {

  Serial.begin(115200);
  shoulder.attach(shoulderPin);
  lowElbow.attach(lowElbowPin);
  highElbow.attach(highElbowPin);
  highWrist.attach(highWristPin);
  lowWrist.attach(lowWristPin);
  claw.attach(clawPin);
}

void loop() {
   for(int posDegrees = 120; posDegrees >= 0; posDegrees--) {
    shoulder.write(posDegrees);
    lowElbow.write(posDegrees);
    highElbow.write(posDegrees);
    highWrist.write(posDegrees);
    lowWrist.write(posDegrees);
    claw.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
  for(int posDegrees = 0; posDegrees <= 120; posDegrees++) {
    shoulder.write(posDegrees);
    lowElbow.write(posDegrees);
    highElbow.write(posDegrees);
    highWrist.write(posDegrees);
    lowWrist.write(posDegrees);
    claw.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }

 

}
