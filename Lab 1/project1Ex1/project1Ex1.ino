int ledPin1 = 2;  //  ledPin is an integer that takes the value 2, representing the pin number
int ledPin2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  digitalWrite(ledPin1, HIGH);  // power ledPin and turn ledPin on if button is pressed
  delay(1000);
  digitalWrite(ledPin2, HIGH);  //do not power ledPin if button is not pressed
  delay(1000);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(1000);

  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin1, LOW);
    delay(500);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin2, HIGH);
    delay(500);
    digitalWrite(ledPin2, LOW);
    delay(500);
  }
}