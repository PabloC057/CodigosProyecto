//Temperatura

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin de datos conectado al sensor DS18B20
const int pinDatos = 2;

// Instanciar un objeto OneWire para comunicarse con el sensor
OneWire oneWire(pinDatos);

// Pasar la referencia del objeto OneWire a DallasTemperature 
DallasTemperature sensorDS18B20(&oneWire);

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);

  // Inicializar el sensor DS18B20
  sensorDS18B20.begin();
}

void loop() {
  // Realizar una lectura de la temperatura
  sensorDS18B20.requestTemperatures();

  // Leer la temperatura en grados Celsius
  float temperaturaCelsius = sensorDS18B20.getTempCByIndex(0);

  // Imprimir la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius);
  Serial.println(" °C");

  // Esperar 1 segundo antes de la próxima lectura
  delay(1000);
}