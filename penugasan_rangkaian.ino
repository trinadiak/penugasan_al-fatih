// PROGRAMMER AL-FATIH

#include <Servo.h>

const int button3 = 3;
const int button4 = 4; 
const int button5 = 5;
const int button6 = 6;
const int button7 = 7;
const int motor = 12;
int buttonState = 0; 

Servo servo1;

int speed1=0,speed2=0,x=0, pwm=0;

// setup
void setup(){
  Serial.begin(9600);
  // pin input
  pinMode(button3,INPUT); // pushbutton belok kanan
  pinMode(button4,INPUT); // pushnbutton mundur
  pinMode(button5,INPUT); // pushbutton maju
  pinMode(button6,INPUT); // pushbutton belok kiri
  pinMode(button7,INPUT); // gripper 180 degree
  // pin output
  pinMode(8,OUTPUT); // DC A
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); // DC B
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT); // micro servo (gripper)
  servo1.attach(motor);
  servo1.write(0);
}
// loop
void loop(){
  if(digitalRead(button3)== HIGH){ // pushbutton ON, DC belok kanan
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  else if(digitalRead(button4)== HIGH){ // pushbutton ON, DC mundur
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else if(digitalRead(button5) == HIGH){ // pushbutton ON, DC maju
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  else if(digitalRead(button6) == HIGH){ // pushbutton ON, DC belok kiri
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(digitalRead(button7) == HIGH){ // pushbutton ON, servo gripper putar 180
    servo1.write(180);
    delay(1000);
  }
  else if(digitalRead(button3) == LOW ){ // pushbutton OFF, set low semua output 
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    servo1.write(0);
    delay(1000);
  }
}
