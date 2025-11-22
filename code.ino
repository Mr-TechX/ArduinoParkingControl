// ++++++++++++++++++++++++++++++++++++++++++++++++
// Author: TecnoProjects Security                 +
// Project: Arduino Parking Control               +
// Version: v1.0.0                                +
// ++++++++++++++++++++++++++++++++++++++++++++++++
#include <Servo.h>

// definir pines
Servo servo;
int trigPin = 11;
int echoPin = 12;

// definir variables
long duration;
int distance;

void setup() {
  servo.attach(13);
  servo.write(180);
  delay(2000);
  
  // Setear el trigPin como Output
  pinMode(trigPin, OUTPUT);

  // Setear el echoPin como Input 
  pinMode(echoPin, INPUT);
}

void loop() {
  // limpiar trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Definir trigPin en estadi HIGH por 10ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer echoPin, devuelve el tiempo de viaje de la onda sonora en ms
  duration = pulseIn(echoPin, HIGH);

  // Calculando distancia
  distance= duration*0.034/2;

  // Imprimir la distancia en la pantalla (opcional, si no se usa la pantalla puede probar comentar las dos lineas siguientes "Los Serial prints")
  Serial.print("Distance: ");
  Serial.println(distance);

  // Austa la distancia del if "25" para que se acomode a tu acomodo del sensor
  if ( distance <= 25 ) {
    servo.write(180);
    delay(3000);
  } else {
    servo.write(90);
  }
}
