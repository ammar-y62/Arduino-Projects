  int motor = 2;
  int pushbuttonPin = 8; 
  int buttonState;
  void setup() {
  pinMode(2, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushbuttonPin);
  if (buttonState == HIGH) 
  {
    digitalWrite(motor, HIGH);
  }
  else 
  {
    digitalWrite(motor, LOW); 
  }
}
