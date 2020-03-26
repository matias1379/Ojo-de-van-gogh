#include <ArduinoJson.hpp>    //incluyo librerias de Json
#include <ArduinoJson.h>

// Funcion de crear un Json
String SerializarJson()
{
    String json; // variable Json
    StaticJsonDocument<300> doc;  // se crea un objeto llamado doc con 300 bytes de memoria
    doc["colour"] = "rojo";     // el documento color tiene de valor: rojo
     
    serializeJson(doc, json); // se crea el Json de color y se guarda en la variable json
    return json;  // el programa devuelve el string json
}

// Funcion de deserializar Json 
String DeserializarJson(String json)                          //Devuelve un string y pide el string json
{
    StaticJsonDocument<300> doc;                              // se crea un objeto llamado doc con 300 bytes de memoria
    DeserializationError error = deserializeJson(doc, json);  //se deserializa el documento y la variable json
    if (error) { return; }                                    // si hay error devolver nada
 
    String color = doc["colour"]; //busco el documento "colour" y guardo lo que contiene 
    Serial.println(color);        //se imprime el contenido de colour, osea rojo
    return color;
}
 
void setup()
{
    Serial.begin(115200); //Inicializa puerto serie 
    Serial.println("===== Object Example =====");
    Serial.println("-- Serialize --");
    Serial.println(SerializarJson()); //imprimo el archivo Json creado  
 
}
 
void loop()
{
  if(Serial.available()>0){    //Si en el serial hay un dato
    int a= Serial.read();      // leo el Serial y guardo en la variable a

    // si a es 1 deserializo el archivo que serialice.
    if (a=='1'){
      DeserializarJson(SerializarJson()); // devuelve "rojo"
    }
    
  }
}
