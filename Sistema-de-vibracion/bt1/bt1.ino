#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial ModuloHC05 (10, 11);  //pin RX, pin TX
 
void setup() {
 
 Serial.begin(9600);        //Inicializa puerto serie 
 ModuloHC05.begin(9600);    //Inicializa puerto serie de BT
 
}
 
void loop() {
 
 if (ModuloHC05.available())                    //Si llega algo por bluetooth
            Serial.write(ModuloHC05.read());    //Sacarlo a la terminal
          
}
