#include  <ESP32Servo.h> // libreria para los servo motores 

// 180 horizontal MAXIMO
Servo horizontal; // declaramos el valor para el servo horizontal
int servoh = 180;        

int servohLimitHigh = 180; //limite en posicion superior
int servohLimitLow = 0; //limite para posicion inferior


Servo vertical;   // vertical servo 
int servov = 180;    
int servovLimitHigh = 180;
int servovLimitLow = 0;



int ldrlt = 32; // conexion a las resistencias LDR
int ldrrt = 33; 
int ldrld = 34; 
int ldrrd = 35; 

void setup()
{
  Serial.begin(9600);
  horizontal.attach(25); //servo horizontal pin digital 9
  vertical.attach(26); // servo vertical pin digital 10
  horizontal.write(180);
  vertical.write(180);
  delay(3000);
}

void loop() 
{
  int lt = analogRead(ldrlt); // top left (superior izquierdo)
  int rt = analogRead(ldrrt); // top right (superior derecho)
  int ld = analogRead(ldrld); // down left (inferior izquierdo)
  int rd = analogRead(ldrrd); // down rigt (inferior derecho)
  
  // int dtime = analogRead(4)/20; // Opcional si utilizamos potenciometros para la velocidad 
  // int tol = analogRead(5)/4;
  int dtime = 20;
  int tol = 20;
  
  int avt = (lt + rt) / 2; // valor superior maximo
  int avd = (ld + rd) / 2; // valor inferior maximo
  int avl = (lt + ld) / 2; // valor izquierdo maximo
  int avr = (rt + rd) / 2; // valor derecho maximo

  int dvert = avt - avd; // diferencia entre superior e inferior
  int dhoriz = avl - avr;// diferencia entre izquierdo y derecho
  
  
  Serial.print(avt);   // Imnprimir valores  de posicion en monitor serial
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");
  
    
  if (-1*tol > dvert || dvert > tol) // revisar la diferencia para cambiar al angulo vertical
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // revisar la diferencia para cambiar al angulo horizontal
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    
  }
  horizontal.write(servoh);
  }
   delay(dtime);

}