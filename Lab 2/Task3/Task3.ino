int pwm = 2; 
int pm = A0; 
int x = 0;   
int y = 0;   

void setup()  
{
  pinMode(pwm, OUTPUT); 
  pinMode(pm, INPUT);  
}

void loop()
{
  y= analogRead(pm); 
  x= 1024-y;        
  digitalWrite(pwm, HIGH); 
  delayMicroseconds(x);   
  digitalWrite(pwm, LOW);  
  delayMicroseconds(y);  
}
