//DECLARACIONES
//#include <Arduino.h>
#define potenciometro 35
int valor=0;

//CONFIGURACIONES
void setup() {
  Serial.begin(115200);
  pinMode(23,OUTPUT);
}

//BUCLE PRINCIPAL
void loop() {
  valor=analogRead(potenciometro);
  Serial.println(valor);
  if(valor > 2045){
    digitalWrite(23,HIGH);
  }
  else{
    digitalWrite(23,LOW);
  }
  delay(50);
}

