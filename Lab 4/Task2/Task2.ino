#include <Servo.h>  //servo library
Servo myservo;      // create servo object

int Echo  = A4;  
int Trig  = A5; 

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 128
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Serial.println("Back");
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  // Serial.println("Left");
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Serial.println("Right");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  
} 
long ultrasonicDistanceInCM() {               // distance in cm using the Ultrasonic sensor
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);                       
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);                      
  digitalWrite(Trig, LOW);
  long duration = pulseIn(Echo, HIGH);
  return duration / 50;
}


void setup() { 
  myservo.attach(3);
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

} 

void loop() { 
  
    myservo.write(90);  //setservo position according to scaled value
    delay(500); 
    middleDistance = ultrasonicDistanceInCM();

    if(middleDistance <= 15) {     
      stop();
      delay(1000);
      back();  
      delay(500);  
      stop();                  
      myservo.write(0);          
      delay(1000);      
      rightDistance = ultrasonicDistanceInCM();
      
      delay(500);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = ultrasonicDistanceInCM();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right();
        delay(500);
      }
      else if(rightDistance < leftDistance) {
        left();
        delay(500);
      }
    }  
    else {
        forward();
    }                     
}
