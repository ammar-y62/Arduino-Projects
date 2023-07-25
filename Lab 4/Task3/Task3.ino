
#include <IRremote.h>

#define F 16736925  // FORWARD
#define B 16754775  // BACK
#define L 16720605  // LEFT
#define R 16761405  // RIGHT
#define UNKNOWN_F 5316027     // FORWARD
#define UNKNOWN_B 2747854299  // BACK
#define UNKNOWN_L 1386468383  // LEFT
#define UNKNOWN_R 553536955   // RIGHT


#define RECV_PIN  12

#define ENA 5   // Left  wheel speed
#define ENB 6   // Right wheel speed

#define IN1 7   // Left  wheel forward
#define IN2 8   // Left  wheel reverse
#define IN3 9   // Right wheel reverse
#define IN4 11  // Right wheel forward
#define carSpeed 128  

IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long val;
unsigned long preMillis;


#include <Servo.h>  //servo library
Servo myservo;      // servo object to control servo

int Echo = A4;  
int Trig = A5; 
int rightDistance = 0, leftDistance = 0, middleDistance = 0;


 void forward(){ 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void back(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void left(){
  analogWrite(ENA,carSpeed);
  analogWrite(ENB,carSpeed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
}
void right(){
  analogWrite(ENA,carSpeed);
  analogWrite(ENB,carSpeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void stop(){
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
  return duration /50;
}

void setup() {
    myservo.attach(3);  //servo on pin 3 to servo object
  Serial.begin(9600); 
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  stop();
  irrecv.enableIRIn();  
}

void loop() {
  if ( ultrasonicDistanceInCM() < 15){ {
   myservo.write(90);  //set servo position front
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
      myservo.write(100);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = ultrasonicDistanceInCM();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right();
        delay(100);
      }
      else if(rightDistance < leftDistance) {
        left();
        delay(100);
      }
    }  
    else {
        forward();
    }      
}
  }
else{
  if (irrecv.decode(&results)){ 
    // preMillis = millis();
    val = results.value;
    Serial.println(val);
    irrecv.resume();
    delay(150);
    if(val ==UNKNOWN_F ){
      forward();
    }
    // switch(val){
    //   case F: 
    //   case UNKNOWN_F: forward(); break;
    //   case B: 
    //   case UNKNOWN_B: back(); break;
    //   case L: 
    //   case UNKNOWN_L: left(); break;
    //   case R: 
    //   case UNKNOWN_R: right();break;
    // }
  }
  // else{
  //   if(millis() - preMillis > 500){
  //     stop();
  //     preMillis = millis();
  //   }
  // }
  
} 

}
