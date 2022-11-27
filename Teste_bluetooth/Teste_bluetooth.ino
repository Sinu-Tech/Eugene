#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char valorRecebido;
int LED_BUILTIN = LOW;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("Esp32"); 
  Serial.println("O dispositivo já pode ser pareado!");
  int LED_BUILTIN = LOW;
  pinMode(LED_BUILTIN, OUTPUT); //make BUILTIN_LED pin as output
}

void loop() {
    valorRecebido =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) { //NO APLICATIVO "SERIAL BLUETOOTH TERMINAL, ENVIA UM COMANDO 1, 2 ,3 OU 4"
    
    if(valorRecebido == '1')
    {
     SerialBT.println("LED 1 ligado:");
     digitalWrite(LED_BUILTIN, HIGH);
    }
    if(valorRecebido == '2')
    {
     SerialBT.println("LED 1 desligado:");
      digitalWrite(LED_BUILTIN, HIGH);
    }    
    if(valorRecebido == '3')
    {
     SerialBT.println("LED 2 ligado:");
     digitalWrite(LED_BUILTIN, HIGH);
       
    }
    if(valorRecebido == '4')
    {
     SerialBT.println("LED 2 desligado");
      digitalWrite(LED_BUILTIN, HIGH); 
    }
     
  
  }
  delay(30);
}
