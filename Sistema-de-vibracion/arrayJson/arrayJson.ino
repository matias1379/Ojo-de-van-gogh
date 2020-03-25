#include <ArduinoJson.hpp>
#include <ArduinoJson.h>
 
void SerializeArray()
{
    String json;
    StaticJsonDocument<300> doc;
    doc.add("B");
    doc.add(45);
    doc.add(2.1728);
    doc.add(true);
 
    serializeJson(doc, json);
    Serial.println(json);
}
 
void DeserializeArray()
{
    String json = "[\"B\",45,2.1728,true]";
 
    StaticJsonDocument<300> doc;
    DeserializationError error = deserializeJson(doc, json);
    if (error) { return; }
 
    String item0 = doc[0];
    int item1 = doc[1];
    float item2 = doc[2];
    bool item3 = doc[3];
 
    Serial.println(item0);
    Serial.println(item1);
    Serial.println(item2);
    Serial.println(item3);
}
 
void setup()
{
    Serial.begin(115200);
 
    Serial.println("===== Array Example =====");
    Serial.println("-- Serialize --");
    SerializeArray();
    Serial.println();
    Serial.println("-- Deserialize --");
    DeserializeArray();
    Serial.println();
}
 
void loop()
{
}
