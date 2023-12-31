#include "CytronMotorDriver.h"
CytronMD motorLeft(PWM_PWM,11,10);
CytronMD motorRight(PWM_PWM,9,3);

long duration;
long distance;

#define BUTTON 2
#define TRIGPIN 5
#define ECHOPIN 4
#define IR_LEFT A0
#define IR_RIGHT A1

void robotStop(){
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
}

void robotMove(int speedLeft, int speedRight){
  motorLeft.setSpeed(speedLeft);
  motorRight.setSpeed(speedRight);
}

void setup(){
  pinMode(IR_LEFT,INPUT);
  pinMode(IR_RIGHT,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  pinMode(BUTTON,INPUT_PULLUP);
}

void loop(){

while(true){
    digitalWrite(TRIGPIN,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN,LOW);

    duration = pulseIn(ECHOPIN,HIGH);
    distance = duration*0.017;

if (distance > 15){
      if(digitalRead(IR_LEFT)==LOW && digitalRead(IR_RIGHT)==LOW){
    robotMove(100,100);
  }
  else if (digitalRead (IR_LEFT)==HIGH && digitalRead(IR_RIGHT)==LOW){
    robotMove(100,100);
  }
  else if (digitalRead(IR_LEFT)==HIGH){
    robotMove(0,150);
  }
  else if (digitalRead(IR_RIGHT)==HIGH){
    robotMove(150,0);
  }
  else {
    robotMove(150,150);
  }
}
else{
  robotStop();
}
}
}
