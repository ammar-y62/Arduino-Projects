#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
int pin[] = {IN1,IN2,IN3,IN4};
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
}
void loop() {
  delay(2000);
  int mat[8][4] = { {1,0,0,0},
                   {1,1,0,0},
                   {0,1,0,0},
                   {0,1,1,0},
                   {0,0,1,0},
                   {0,0,1,1},
                   {0,0,0,1},
                   {1,0,0,1}
                  };

  for (int x = 0 ; x<360; x++){ //need to complete 4096 steps for half step rev 4rows*8teeth*64(gear reduction)*2 (halfstep) 
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 4; j++) {
        digitalWrite(pin[j], mat[i][j]);
      }
      delayMicroseconds(2000);
    }
  }                
}
