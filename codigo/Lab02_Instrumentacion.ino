const int pwmPin = 2; // Pin de salida del simulador de bioseñal
const float frecuencia = 2.0; // 2 Hz
const int pinADC = A0; // Pin de lectura del nodo sumador

unsigned long tiempoAnteriorPWM = 0;
unsigned long tiempoAnteriorADC = 0;

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600); // Configurado a 9600 baudios según la guía
}

void loop() {
  unsigned long tiempoActual = millis();
  
  // TAREA 1: Generar la señal PWM (se actualiza constantemente)
  if (tiempoActual - tiempoAnteriorPWM >= 2) { 
    tiempoAnteriorPWM = tiempoActual;
    float tiempoSegundos = tiempoActual / 1000.0;
    float seno = sin(2 * PI * frecuencia * tiempoSegundos);
    int valorPWM = (int)((seno + 1.0) * 127.5);
    analogWrite(pwmPin, valorPWM);
  }

  // TAREA 2: Leer el nodo sumador e imprimir (Etapa D) - cada 10 ms según guía
  if (tiempoActual - tiempoAnteriorADC >= 10) {
    tiempoAnteriorADC = tiempoActual;
    int lecturaRaw = analogRead(pinADC);
    // Conversión a voltios (Mega: 5V / 1023.0)
    float voltaje = lecturaRaw * (5.0 / 1023.0); 
    Serial.println(voltaje); // Envio al Serial Plotter virtual
  }
}