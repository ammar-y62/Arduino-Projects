// #define R digitalRead(10)
// #define M digitalRead(4)
// #define L !digitalRead(2)
int L = 2;
int R = 10;


void setup() {
  Serial.begin(9600);
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop() {

  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  int L_read = digitalRead(L);
  int R_read = digitalRead(R);
  // digitalWrite(3, LOW);
  // digitalWrite(5, LOW);
  if (L_read == 0) {
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
  } 
  if (R_read == 0) {
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
  }
  // }
  // // if (R_read == 0 && L_read == 0 ) {
  // //   digitalWrite(3, LOW);
  // //   digitalWrite(5, LOW);
  // }
  
}