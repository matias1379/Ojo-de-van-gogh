#include <SoftwareSerial.h>       //incluyo libreria para cambiar pines de serial
SoftwareSerial BTMaster (8, 9);  //pin RX=8, pin TX=9

void setup() {

 Serial.begin(9600);        //Inicializa puerto serie 
 BTMaster.begin(9600);    //Inicializa puerto serie de BT
 Serial.println("Escribe el color: verde, rojo, azul");
}

void loop() {
  
  if(Serial.available()>0){ //Si en el serial hay un dato
   BTMaster.write(Serial.read()); //escribo en el bt lo que se leyo 
    }
     
}
