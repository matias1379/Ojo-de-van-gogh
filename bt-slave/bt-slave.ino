#include <SoftwareSerial.h>       //incluyo libreria para cambiar pines de serial
SoftwareSerial BTSlave (10, 11);  //pin RX=10, pin TX=11
int tono;
const int buzzer=9;               //pin del vibrador o buzzer

char c = 0;            // contador para que los colores vibren varias veces

void setup() {

 Serial.begin(9600);        //Inicializa puerto serie 
 BTSlave.begin(9600);    //Inicializa puerto serie de BT
 
}

void loop() {
  
  if(BTSlave.available()){ //si llega informacion por BT
   tono=BTSlave.read();    //leo y guardo en tono

   //Si es 1 hago tal ruido
     if(tono=='1'){
      //le agregue este for para que se repita 4 veces
      for(c = 0, c <= 4, c++) {
        tone(buzzer,440);
        delay(1000);
        noTone(buzzer);
        delay(100);
     
        Serial.println("Está sonando el color: verde");
      }
      c = 0;  
    }
    //Si es 2 hago tal ruido
    if(tono=='2'){
    
      for(c = 0, c <= 4, c++){
        tone(buzzer,880);
        delay(1000);
        noTone(buzzer);
        delay(1000);
        Serial.println("Está sonando el color: rojo");
      }
     c = 0;
     }
  //Si es 3 hago tal ruido
     if(tono=='3'){
      for(c = 0, c <= 4, c++){
        tone(buzzer,2000);
        delay(1000);
        noTone(buzzer);
        delay(2000);
        Serial.println("Está sonando el color: azul");
      }
      c = 0;
     }   
     
     Serial.println("Escribe el color: verde, rojo, azul");
  }

}
