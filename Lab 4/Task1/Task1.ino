// L298n module IO Pin
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 128

void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void setup() {
  Serial.begin(9600); //set baud rate
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}
void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
} 


//Repeat indefinitely
void loop() {
  forward();  //forward
  delay(3000);//delay 3 s
  stop();  //stop
  delay(1000); //delay 1 s
  back();     // back
  delay(3000); //delay 3s
  stop(); //stop
  delay(1000); //delay 1 s
}
