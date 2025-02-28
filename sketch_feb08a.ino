#include <HX711.h>
 // Librería para el amplificador de instrumentación HX711

#define DOUT  2      // Pin DOUT del HX711 al pin digital 2 del Arduino
#define SCK   3      // Pin SCK del HX711 al pin digital 3 del Arduino

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, SCK);
}

void loop() {
  if (scale.is_ready()) {
    long weight = scale.get_units();  // Obtener la lectura en unidades (gramos en este caso)
    
    Serial.print("Peso en gramos: ");
    Serial.println(weight);
    
    delay(1000);  // Puedes ajustar la frecuencia de las lecturas según tus necesidades
  } else {
    Serial.println("El HX711 no está listo.");
  }
}
