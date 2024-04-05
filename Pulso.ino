//Pulso

// Definir el pin al que está conectado el sensor de pulso
const int sensorPin = 2;
// Variable para almacenar el número de pulsos
int pulsos = 0;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);
  // Configurar el pin del sensor como entrada
  pinMode(sensorPin, INPUT);
  // Adjuntar la interrupción para detectar los pulsos
  attachInterrupt(digitalPinToInterrupt(sensorPin), contarPulsos, RISING);
}

void loop() {
  // Mostrar el número de pulsos en el monitor serial
  Serial.println(pulsos);
  // Esperar 1 segundo
  delay(1000);
}

// Función para contar los pulsos
void contarPulsos() {
  pulsos++;
}
