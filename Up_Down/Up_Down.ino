#include <ESP32Servo.h>

//pin assignment
static const int shoulderPin = 23;
static const int lowElbowPin = 22;
static const int highElbowPin = 13;
static const int highWristPin = 05;
static const int lowWristPin = 21;
static const int clawPin = 19;


 int shoulderPos = 93;
 int lowElbowPos = 110;
 int highElbowPos = 40;
 int highWristPos = 90;
 int lowWristPos= 90;
 
//class assignment
Servo shoulder;
Servo lowElbow;
Servo highElbow;
Servo highWrist;
Servo lowWrist;
Servo claw;

void setup() {
  Serial.begin(9600);
  shoulder.attach(shoulderPin, 900, 2100);
  lowElbow.attach(lowElbowPin,900, 2100);
  highElbow.attach(highElbowPin, 1500, 1900);
  highWrist.attach(highWristPin);
  lowWrist.attach(lowWristPin);
  claw.attach(clawPin);
  
 int shoulderPos = 93;
 int lowElbowPos = 110;
 int highElbowPos = 40;
 int highWristPos = 90;
 int lowWristPos= 90;
      //home position
      claw.write(20);
      shoulder.write(shoulderPos); 
      lowElbow.write(lowElbowPos);
      highElbow.write(highElbowPos);
      highWrist.write(highWristPos);
      lowWrist.write(lowWristPos);
      
}

void loop() {   
  //position 2
  for (int i=highWristPos; i < 120; i++) {
      highWrist.write(i);
      highWristPos = i; 
      delay(200);
      }
 for (int i=highElbowPos; i < 140; i++) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }
      delay(1000);
      claw.write(100);
      delay(2000);

  // return to home position
      claw.write(20);
      delay(1000);
  for (int i=highElbowPos; i > 40; i--) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }
  delay(1000);
}
