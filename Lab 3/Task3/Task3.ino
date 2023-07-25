const int trigPin = 3;                    
const int echoPin = 5;                    
void setup() {
  Serial.begin(9600);                      
  pinMode(trigPin, OUTPUT);                  
  pinMode(echoPin, INPUT);                  
}
long ultrasonicDistanceInCM() {              
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);                      
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);                    
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration / 50;
}
void loop() {
 Serial.println(ultrasonicDistanceInCM());
 delay(100);
}
