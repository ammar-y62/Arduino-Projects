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
  delay(3000);
  int mat[][4] = { {1,0,0,0},
                   {1,1,0,0},
                   {0,1,0,0},
                   {0,1,1,0},
                   {0,0,1,0},
                   {0,0,1,1},
                   {0,0,0,1},
                   {1,0,0,1}
                  };
   int mat2[][4] = {{1,0,0,1},
                   {0,0,0,1},
                   {0,0,1,1},
                   {0,0,1,0},
                   {0,1,1,0},
                   {0,1,0,0},
                   {1,1,0,0},
                   {1,0,0,0}
                  };

  for (int x = 0 ; x<512; x++){ 
    for (int s = 0; s < 8; s++){  
      for (int p = 0; p < 4; p++) {
        digitalWrite(pin[p], mat[s][p]);
      }
      delayMicroseconds(2500);
    }
  }
        for (int x = 0 ; x<512; x++){
    for (int s = 0; s < 8; s++){
      for (int p = 0; p < 4; p++) {
        digitalWrite(pin[p], mat2[s][p]);
      }
      delayMicroseconds(2500);
    }
  }          
}
