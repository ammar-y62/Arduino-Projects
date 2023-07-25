#include <Servo.h> 
Servo labservo;  
int potpin = 0;  
int val;   

void setup() {
  labservo.attach(9);
}
void loop() {
  val = analogRead(potpin);          
  val = map(val, 0, 1023, 0, 180);   
  labservo.write(val);                  
  delay(20);                           
}
