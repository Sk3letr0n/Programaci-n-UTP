#include <BluetoothSerial.h>

// set pin numbers
const int touchPin4 = 4; // C
const int touchPin15 = 15; // D
const int touchPin13 = 13; // B
const int touchPin14 = 14; // A
const int touchPin27 = 27; // 1
const int touchPin33 = 33; // 3
const int touchPin32 = 32; // 2

// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int touchValue4;
int touchValue15;
int touchValue13;
int touchValue14;
int touchValue27;
int touchValue33;
int touchValue32;

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");
  Serial.println("Bluetooth iniciado");
  delay(1000); // give me time to bring up serial monitor
 
}

void loop(){

  // read the state of the pushbutton value:
  touchValue4 = touchRead(touchPin4);
  touchValue15 = touchRead(touchPin15);
  touchValue13 = touchRead(touchPin13);
  touchValue14 = touchRead(touchPin14);
  touchValue27 = touchRead(touchPin27);
  touchValue33 = touchRead(touchPin33);
  touchValue32 = touchRead(touchPin32);

  // Serial.println(touchValue33);
  delay(1000);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH


  // Casillas A
  if((touchValue14 < threshold) && (touchValue27 < threshold)){
    SerialBT.print("Casilla A1");
    delay(1000);
  } else if ((touchValue14 < threshold) && (touchValue32 < threshold)){
    SerialBT.print("Casilla A2");
    delay(1000);
  } else if ((touchValue14 < threshold) && (touchValue33 < threshold)){
    SerialBT.print("Casilla A3");
    delay(1000);
  } else if (touchValue14 < threshold){
    SerialBT.print("Casilla A4");
    delay(1000);
  }


  // Casillas B
  if((touchValue13 < threshold) && (touchValue27 < threshold)){
    SerialBT.print("Casilla B1");
    delay(1000);
  } else if ((touchValue13 < threshold) && (touchValue32 < threshold)){
    SerialBT.print("Casilla B2");
    delay(1000);
  } else if ((touchValue13 < threshold) && (touchValue33 < threshold)){
    SerialBT.print("Casilla B3");
    delay(1000);
  } else if (touchValue13 < threshold){
    SerialBT.print("Casilla B4");
    delay(1000);
  }


  // Casillas C
  if((touchValue4 < threshold) && (touchValue27 < threshold)){
    SerialBT.print("Casilla C1");
    delay(1000);
  } else if ((touchValue4 < threshold) && (touchValue32 < threshold)){
    SerialBT.print("Casilla C2");
    delay(1000);
  } else if ((touchValue4 < threshold) && (touchValue33 < threshold)){
    SerialBT.print("Casilla C3");
    delay(1000);
  } else if (touchValue4 < threshold){
    SerialBT.print("Casilla C4");
    delay(1000);
  }  


  // Casillas D
  if((touchValue15 < threshold) && (touchValue27 < threshold)){
    SerialBT.print("Casilla D1");
    delay(1000);
  } else if ((touchValue15 < threshold) && (touchValue32 < threshold)){
    SerialBT.print("Casilla D2");
    delay(1000);
  } else if ((touchValue15 < threshold) && (touchValue33 < threshold)){
    SerialBT.print("Casilla D3");
    delay(1000);
  } else if (touchValue15 < threshold){
    SerialBT.print("Casilla D4");
    delay(1000);
  }

}