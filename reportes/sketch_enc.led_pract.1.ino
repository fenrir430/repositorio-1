const int boton = 23; 
int   anterior;     
void setup() {
  Serial.begin(9600);
 
  pinMode(boton,INPUT_PULLUP);
  anterior = digitalRead(boton);
}
  
void loop() {
 
  int estado = digitalRead(boton);
 
  if ( anterior==LOW && estado==HIGH ) {
    Serial.println("Hemos pulsado");
  }
  
  anterior=estado;
}