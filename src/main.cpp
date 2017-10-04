#include <Arduino.h>
#include <Dynamixel_Serial.h>
#include <SoftwareSerial.h>
#define SERVO_ControlPin 0x02
#define SERVO_SET_Baudrate 57600
#define LED13 0x0D
#define CW_LIMIT_ANGLE 0x001        // lowest clockwise angle is 1, as when set to 0 it set servo to wheel mode
#define CCW_LIMIT_ANGLE 0xFFF       // Highest anit-clockwise angle is 0XFFF, as when set to 0 it set servo to wheel mode

SoftwareSerial mySerial(10, 11); // RX, TX

void setup(){
  pinMode(LED13, OUTPUT);

  digitalWrite(LED13, HIGH);
  mySerial.begin(SERVO_SET_Baudrate);
  Serial.begin(115200);

  Dynamixel.begin(mySerial);
  Dynamixel.setDirectionPin(SERVO_ControlPin);
  Dynamixel.setHoldingTorque(0x02, true);
  Dynamixel.setHoldingTorque(0x03, true);
  Dynamixel.setHoldingTorque(0x01, true);
  Dynamixel.setNGoalPositions(-500, 2048, 2048, -1, -1);
  Dynamixel.setGoalPosition(0x02, 2048);
  //Dynamixel.setHoldingTorque(0x01,true);
  //Dynamixel.setGoalPosition(0x01, -1026);
}


void loop(){

}
