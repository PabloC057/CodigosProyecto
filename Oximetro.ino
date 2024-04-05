//Oxímetro

#include <SoftwareSerial.h>

// Configuración del pin RX y TX para la comunicación serial con el oxímetro
const int oximetroRX = 2; // Pin RX del oxímetro conectado al pin 2 del Arduino
const int oximetroTX = 3; // Pin TX del oxímetro conectado al pin 3 del Arduino

SoftwareSerial oximetroSerial(oximetroRX, oximetroTX);

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial con el monitor serial
  oximetroSerial.begin(9600); // Iniciar comunicación serial con el oxímetro
}

void loop() {
  if (oximetroSerial.available()) {
    // Si hay datos disponibles desde el oxímetro
    char dato = oximetroSerial.read(); // Leer el dato recibido
    Serial.print("Dato del oximetro: ");
    Serial.println(dato); // Mostrar el dato en el monitor serial
  }
  delay(1000);
}
