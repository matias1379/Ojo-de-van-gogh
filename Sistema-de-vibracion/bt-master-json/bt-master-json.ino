#include <ArduinoJson.hpp>        //incluyo librerias de Json
#include <ArduinoJson.h>
#include <SoftwareSerial.h>       //incluyo libreria para cambiar pines de serial
SoftwareSerial BTMaster (8, 9);  //pin RX=8, pin TX=9

// Funcion de serializar Json
String SerializarJson()
{
    String json;  
    StaticJsonDocument<300> doc;  // se crea un objeto llamado doc con 300 bytes de memoria
    doc["colour"] = "rojo";       //el documento colour tiende valor a rojo
     
    serializeJson(doc, json);     //se serializa el doc y guarda en json 
    return json;
}

int str_len =SerializarJson().length()+1;
char charArray[100];

void setup() {

 Serial.begin(9600);        //Inicializa puerto serie 
 BTMaster.begin(9600);    //Inicializa puerto serie de BT
 Serial.println("Escribe el color: rojo, verde, azul");
}

void loop() {
  
  if(Serial.available()>0){ //Si en el serial hay un dato
    if(Serial.read()== '1'){  //si es 1 lo que leo del serial
       SerializarJson().toCharArray(charArray, str_len);    //hago el string json en un char array
       Serial.println(SerializarJson());
       Serial.println(charArray);
       BTMaster.write(charArray); //escribo en el bt el char array
       
    }
    
  }
     
}
