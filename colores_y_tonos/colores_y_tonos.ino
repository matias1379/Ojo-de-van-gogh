const int buzzer=9;
int tono;
void setup() {
  Serial.begin(9600);
  Serial.println("Escribe el color: verde, rojo, azul");
}

void loop() {
 if(Serial.available()>0){
    tono=Serial.read();
    if(tono=='1'){
      tone(buzzer,440);
      delay(1000);
      noTone(buzzer);
      delay(100);
     
      Serial.println("Está sonando el color: verde");
    }
    if(tono=='2'){
      tone(buzzer,880);
      delay(1000);
      noTone(buzzer);
      delay(1000);
      
     }
  
     if(tono=='3'){
      tone(buzzer,2000);
      delay(1000);
      noTone(buzzer);
      delay(2000);
      
     }   
     Serial.println("Escribe el color: verde, rojo, azul");
  
  }
}
