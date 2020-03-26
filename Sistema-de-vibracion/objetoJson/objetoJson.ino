#include <ArduinoJson.hpp>    //incluyo librerias de Json
#include <ArduinoJson.h>
 
 // Funcion de crear un Json
String SerializeObject()
{
    String json;                  // variable Json
    StaticJsonDocument<300> doc;  // se crea un objeto llamado doc con 300 bytes de memoria
    doc["text"] = "myText";       // el doc text tiene valor myText
    doc["id"] = 10;               // el doc id tiene valor 10
    doc["status"] = true;         // el doc status tiene valor true
    doc["value"] = 3.14;          // el doc value tiene valor 3.14
 
    serializeJson(doc, json);
    Serial.println(json); //se imprime json creado
  
}
 
void DeserializeObject()
{
     String json = "{\"text\":\"myText\",\"id\":10,\"status\":true,\"value\":3.14}"; //creo el json a deserializar
 
    StaticJsonDocument<300> doc;                              // se crea un objeto llamado doc con 300 bytes de memoria
    DeserializationError error = deserializeJson(doc, json);  //se deserializa el documento y la variable json
    if (error) { return; }                                    // si hay error devolver nada
 
 //busco los diferentes documentos y guardo sus contenidos en una variable
    String text = doc["text"];        
    int id = doc["id"];
    bool stat = doc["status"];
    float value = doc["value"];

 // se imprimen los documentos deserializados
    Serial.println(text);   
    Serial.println(id);
    Serial.println(stat);
    Serial.println(value);
}
 
void setup()
{
    Serial.begin(115200);//Inicializa puerto serie 
    Serial.println("===== Object Example =====");
    Serial.println("-- Serialize --");
    SerializeObject();//se serializa
    Serial.println("-- Deserialize --");
    DeserializeObject();//se deserializa
 
}
 
void loop()
{
}
