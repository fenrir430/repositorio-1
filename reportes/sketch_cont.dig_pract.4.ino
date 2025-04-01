//Matriz de numeros 
byte Digit[10][8] = { 
     { 1,1,1,1,1,1,0,0 },    // 0
     { 0,1,1,0,0,0,0,0 },    // 1
     { 1,1,0,1,1,0,1,0 },    // 2
     { 1,1,1,1,0,0,1,0 },    // 3
     { 0,0,1,0,0,1,1,0 },    // 4
     { 1,0,1,1,0,1,1,0 },    // 5
     { 1,0,1,1,1,1,1,0 },    // 6
     { 1,1,1,0,0,0,0,0 },    // 7
     { 1,1,1,1,1,1,1,0 },    // 8
     { 1,1,1,0,0,1,1,0 }     // 9
};

void setup(){  
  Serial.begin(115200);
  //Declara los segmentos de cada digito y sus "transistores"
  for (int i=12; i<24; i++)
  pinMode(i, OUTPUT);
}

void Display(int pos, int N){  //Transistores
  /*  
      La variable "pos" esta en funcion a la posicion del digito (0,1,2,3)
      Mientars que la variable N es la que se encarga de encernder los digitos (darle corriente a los transistores)
  */
      // Apaga todos los digitos con el fin de actualizarlos
       digitalWrite(19 ,LOW);        
       digitalWrite(21,LOW);
       digitalWrite(22,LOW);
       digitalWrite(23,LOW);
  
      for (int i= 0 ; i<8 ; i++)    // Esto en base a la cantidad de segmentos por digito
            digitalWrite(i+12 , Digit[N][i]) ;
      digitalWrite(pos + 19, HIGH);      // Enciende el digito pos
}

  void CalculaDigitos(int Num){
    /*
      Con base al caluculo de el contador, se calculan los sigitos y el resultado en unidades, decentas, etc., se plasmara en los displays
    */
      int Digito0 = Num % 10 ;            //Unidades
      int Digito1 = (Num % 100) / 10;     //Decenas 
      int Digito2 = (Num % 1000) / 100;   //Centenas
      int Digito3 = (Num  / 1000);        //Miles

      //Encendido de digitos
      Display(3 , Digito3);  
      Display(2 , Digito2);
      Display(1 , Digito1);
      Display(0 , Digito0);
   }
void loop()
   {
       CalculaDigitos( millis() / 100); //Contador en centesimas de segundo
       delay(5);
   }