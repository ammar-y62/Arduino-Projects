int ledPin=2;
int potPin = A0; // potPin represents the Analog pin A0
int potVal; //Defines potVal as an integer

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600); // set up serial communication at 9600 bps
  

// put your setup code here, to run once:
}

void loop() {
  potVal = analogRead(potPin); // Reads the analog potentiometer pin and stores its value in potVal.
  Serial.println(potVal); // print line the potentiometer
  // Serial.println(value); // prints the value to Serial Monitor with ending line break
  
  digitalWrite(2, HIGH); // sets the voltage level to HIGH or on
  delay(potVal); // pauses program execution for 1000 milliseconds (1 sec)
  digitalWrite(2, LOW); // sets the voltage level to LOW or off
  delay(potVal); // pauses program execution for 1000 milliseconds (1 sec)

  // put your main code here, to run repeatedly:

}
