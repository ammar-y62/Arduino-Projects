#include <Servo.h>
Servo labservo; 
int posdeg = 0;   

void setup() {
  labservo.attach(3); 
  labservo.write(posdeg);
  delay(100);  
}

void loop() {
  for (posdeg = 0; posdeg <= 180; posdeg += 5) 
  {
    labservo.write(posdeg);             
    delay(10);         
  }
  delay(10);
  for (posdeg = 180; posdeg >= 0; posdeg -= 5) 
  { 
    labservo.write(posdeg);            
    delay(10);                      
  }
  delay(10);
}
