const int Trigger = 8;
#define motorA1 5
#define motorA2 6
#define motorB1 10
#define motorB2 11
const int echo = 9;
long duracion, distancia;
void setup(){
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}
void loop(){
  int FI, FD;
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  FI=analogRead(A5);
  FD=analogRead(A6);
  int promF=(FI+FD)/2;
  int ad= abs(promF-FI);
  int ad2= abs(promF-FD);
  if( ad < 40 && ad2 < 40){
    Serial.println("ADELANTE");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH); 
  }
  else if(FD > FI){
    Serial.println("DERECHA");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, HIGH);
  }
  else if(FI > FD){
    Serial.println("IZQUIERDA");
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
  }
  delay(,.K);
}