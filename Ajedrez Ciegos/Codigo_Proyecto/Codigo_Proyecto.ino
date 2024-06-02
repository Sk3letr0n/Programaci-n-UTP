#include <BluetoothSerial.h>

#define Pin1 5    // A1
#define Pin2 18   // B1
#define Pin3 19   // C1
#define Pin4 21   // D1
#define Pin5 22   // A2
#define Pin6 23   // B2
#define Pin7 13   // C2
#define Pin8 15   // D2
#define Pin9 14   // A3
#define Pin10 27  // B3
#define Pin11 26  // C3
#define Pin12 25  // D3
#define Pin13 33  // A4
#define Pin14 32  // B4
#define Pin15 35  // C4
#define Pin16 34  // D4


int Boton1_A1, Boton2_B1, Boton3_C1, Boton4_D1; //Fila 1
int Boton5_A2, Boton6_B2, Boton7_C2, Boton8_D2; //Fila 2
int Boton9_A3, Boton10_B3, Boton11_C3, Boton12_D3; //Fila 3
int Boton13_A4, Boton14_B4, Boton15_C4, Boton16_D4; //Fila 4


BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");
  Serial.println("Bluetooth iniciado");

  pinMode(Pin1, INPUT_PULLUP);
  pinMode(Pin2, INPUT_PULLUP);
  pinMode(Pin3, INPUT_PULLUP);
  pinMode(Pin4, INPUT_PULLUP);
  pinMode(Pin5, INPUT_PULLUP);
  pinMode(Pin6, INPUT_PULLUP);
  pinMode(Pin7, INPUT_PULLUP);
  pinMode(Pin8, INPUT_PULLUP);
  pinMode(Pin9, INPUT_PULLUP);
  pinMode(Pin10, INPUT_PULLUP);
  pinMode(Pin11, INPUT_PULLUP);
  pinMode(Pin12, INPUT_PULLUP);
  pinMode(Pin13, INPUT_PULLUP);
  pinMode(Pin14, INPUT_PULLUP);
  pinMode(Pin15, INPUT_PULLUP);
  pinMode(Pin16, INPUT_PULLUP);
}

void loop() {

  Boton1_A1 = digitalRead(Pin1);
  if (Boton1_A1 == LOW) {
    SerialBT.print("Casilla A1");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton2_B1 = digitalRead(Pin2);
  if (Boton2_B1 == LOW) {
    SerialBT.print("Casilla B1");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton3_C1 = digitalRead(Pin3);
  if (Boton3_C1 == LOW) {
    SerialBT.print("Casilla C1");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton4_D1 = digitalRead(Pin4);
  if (Boton4_D1 == LOW) {
    SerialBT.print("Casilla D1");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton5_A2 = digitalRead(Pin5);
  if (Boton5_A2 == LOW) {
    SerialBT.print("Casilla A2");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }

  
  Boton6_B2 = digitalRead(Pin6);
  if (Boton6_B2 == LOW) {
    SerialBT.print("Casilla B2");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton7_C2 = digitalRead(Pin7);
  if (Boton7_C2 == LOW) {
    SerialBT.print("Casilla C2");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton8_D2 = digitalRead(Pin8);
  if (Boton8_D2 == LOW) {
    SerialBT.print("Casilla D2");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton9_A3 = digitalRead(Pin9);
  if (Boton9_A3 == LOW) {
    SerialBT.print("Casilla A3");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton10_B3 = digitalRead(Pin10);
  if (Boton10_B3 == LOW) {
    SerialBT.print("Casilla B3");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton11_C3 = digitalRead(Pin11);
  if (Boton11_C3 == LOW) {
    SerialBT.print("Casilla C3");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton12_D3 = digitalRead(Pin12);
  if (Boton12_D3 == LOW) {
    SerialBT.print("Casilla D3");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }
  

  Boton13_A4 = digitalRead(Pin13);
  if (Boton13_A4 == LOW) {
    SerialBT.print("Casilla A4");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton14_B4 = digitalRead(Pin14);
  if (Boton14_B4 == LOW) {
    SerialBT.print("Casilla B4");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton15_C4 = digitalRead(Pin15);
  if (Boton15_C4 == LOW) {
    SerialBT.print("Casilla C4");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  Boton16_D4 = digitalRead(Pin16);
  if (Boton16_D4 == LOW) {
    SerialBT.print("Casilla D4");
    delay(1000); // Esperar 1000 milisegundos para evitar rebotes
  }


  // Verificar los caracteres que se imprimen desde el front.
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.print(receivedChar);
  }
}
