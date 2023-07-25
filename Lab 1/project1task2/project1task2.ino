int ledPin = 2; //  ledPin is an integer that takes the value 2, representing the pin number
int pushbuttonPin = 8; 
int buttonState;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(pushbuttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(pushbuttonPin);

if (buttonState == HIGH) {
digitalWrite(ledPin, HIGH); // power ledPin and turn ledPin on if button is pressed
 }
 else {
digitalWrite(ledPin, LOW); //do not power ledPin if button is not pressed
 }
}
