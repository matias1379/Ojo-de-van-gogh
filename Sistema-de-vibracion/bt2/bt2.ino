#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
#define   LED   13          //Pin para el LED
 
SoftwareSerial ModuloHC05 (10, 11);  //pin RX, pin TX
 
void setup() {
 
 Serial.begin(9600);        //Inicializa puerto serie 
 ModuloHC05.begin(9600);    //Inicializa puerto serie de BT
 
 pinMode (LED, OUTPUT);      //defino al led como Salida
 
 digitalWrite (LED, 0);      //el estado es 0
}
 
void loop() {
 char dato;
 if (ModuloHC05.available()) {              //SI Llega algo por bluetooth
  dato=ModuloHC05.read();                   //Leer lo que llegó
  Serial.write(dato);                       //Sacarlo al serial
  if (dato=='1') digitalWrite (LED, 1);     //Si es "1", prende el LED
  if (dato=='0') digitalWrite (LED, 0);     //Si es "0", apaga el LED
 
 }
           
 
}
