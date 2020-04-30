
#include <SoftwareSerial.h>
// external libraries should be put inside #if ... #endif
//    internal headers not.
#define LS 2 // left sensor
#define RS 3 // right sensor
#define LM1 5 // left motor M1a
#define LM2 4 // left motor M2a
#define RM1 7 // right motor M2a
#define RM2 6 // right motor M2b

#define POS 11 // Motion
int value1,value2,value3=1,trig = 0;

SoftwareSerial bt(9,10);

void setup() {
  pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
pinMode(POS, INPUT);
Serial.begin(9600);
bt.begin(38400);
}

void loop() {
Serial.println(trig);
value1 = digitalRead(POS);
if(value1==1){
  if(value3==0){
  value3=1;
  }
  else{
  value3=0;
  }
  delay(400);
}
if(bt.available()){
  value2=bt.read();
  Serial.println(value2);
 trig = 1;
}
if(trig==0 || trig==1 && value3==1){
if(digitalRead(LS) && digitalRead(RS)) // Move Forward on line Slowly.
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, HIGH);
digitalWrite(RM2,LOW);
delay(100);
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
delay(400);
}}
if(value3==0 && trig==1)
{
if(digitalRead(LS) && digitalRead(RS)) // Move Forward on line Faster.
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
}
}
if(!(digitalRead(LS)) && (digitalRead(RS))){ 
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
}
if(digitalRead(LS) && !(digitalRead(RS))){
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
}
if(!(digitalRead(LS)) && !(digitalRead(RS))) // Move Backward on line
{
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
}
if(value1==1){
trig=0;
}
}
