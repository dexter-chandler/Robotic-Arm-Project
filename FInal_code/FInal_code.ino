
#include <ESP32Servo.h>

//pin assignment buttons
#define BUTTON_RED 36 
#define BUTTON_GREEN 39
#define BUTTON_BLACK 34
#define BUTTON_WHITE 35 


//Button Variables
int lastStateRed = HIGH; // the previous state from the input pin
int lastStateGreen = HIGH;
int lastStateBlack = HIGH;
int lastStateWhite = HIGH;
int currentStateRed;     // the current reading from the input pin
int currentStateGreen;
int currentStateBlack;
int currentStateWhite; 

//pin assignment servos
static const int shoulderPin = 23;
static const int lowElbowPin = 22;
static const int highElbowPin = 13;
static const int highWristPin = 05;
static const int lowWristPin = 21;
static const int clawPin = 19;

//servo variable
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

  //Buttons assigned to Push to make
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_BLACK, INPUT_PULLUP);
  pinMode(BUTTON_WHITE, INPUT_PULLUP);

  //Servo class assignment and PWM cycles
  shoulder.attach(shoulderPin, 900, 2100);
  lowElbow.attach(lowElbowPin,900, 2100);
  highElbow.attach(highElbowPin, 1500, 1900);
  highWrist.attach(highWristPin);
  lowWrist.attach(lowWristPin);
  claw.attach(clawPin);


     
      
}

void loop() {   

  //button read
  currentStateRed = digitalRead(BUTTON_RED);
  currentStateGreen = digitalRead(BUTTON_GREEN);
  currentStateBlack = digitalRead(BUTTON_BLACK);
  currentStateWhite = digitalRead(BUTTON_WHITE);

  //Green Button press check
  if(lastStateGreen == HIGH && currentStateGreen == LOW){
  //home position

      shoulder.write(shoulderPos); 
      lowElbow.write(lowElbowPos);
      highElbow.write(highElbowPos);
      highWrist.write(highWristPos);
      lowWrist.write(lowWristPos);
    }
  else if (lastStateGreen == LOW && currentStateGreen == HIGH){}

  //White Button press check
  if(lastStateWhite == HIGH && currentStateWhite == LOW){
  // Lift out
      claw.write(15);
      delay(1000);
  for (int i=highElbowPos; i > 40; i--) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      } 
  }
  else if (lastStateWhite == LOW && currentStateWhite == HIGH){}

  //Red Button press check
  if(lastStateRed == HIGH && currentStateRed == LOW){
  delay(2000);
  //Position 1
  shoulder.write(105);
  delay(1000);
   for (int i=highWristPos; i < 120; i++) {
      highWrist.write(i);
      highWristPos = i; 
      delay(200);
      }
 for (int i=highElbowPos; i < 120; i++) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }
      delay(1000);
      claw.write(100);
      delay(1000);
 for (int i=highElbowPos; i < 140; i++) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }      
      delay(2000);


}
else if (lastStateRed == LOW && currentStateRed == HIGH){}

    //Black button press check
if(lastStateBlack == HIGH && currentStateBlack == LOW){
//position 2
    delay(2000);
    shoulder.write(82);
    delay(1000);
  for (int i=highWristPos; i < 120; i++) {
      highWrist.write(i);
      highWristPos = i; 
      delay(200);
      }
 for (int i=highElbowPos; i < 120; i++) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }
      delay(1000);
      claw.write(100);
      delay(1000);
 for (int i=highElbowPos; i < 140; i++) {
      highElbow.write(i);
      highElbowPos = i; 
      delay(10);
      }
      delay(2000);
}
      else if (lastStateBlack == LOW && currentStateBlack == HIGH){}
 


}
