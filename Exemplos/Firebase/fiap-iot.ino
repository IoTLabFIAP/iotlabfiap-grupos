#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "Sua URL do FIrebase"
#define FIREBASE_AUTH "Chave Sereta do Banco"
#define WIFI_SSID "NOME DO WIFI"
#define WIFI_PASSWORD "SENHA"

void setup() {

  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando...");
   
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado a rede: ");
  Serial.println(WiFi.localIP());
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(1000);
  Firebase.set("LEDFIAP", 0);
  if (Firebase.failed()) {
    Serial.print(">>> ERROR AO CRIAR LEDFIAP >>> ");
    Serial.println(Firebase.error());
  }
   
  pinMode(13, OUTPUT); 
  digitalWrite(13, HIGH); 
  delay(1000);
  digitalWrite(13, LOW); 
  delay(1000);
  digitalWrite(13, HIGH);
  
}

void loop() {
  int r = Firebase.getInt("LEDFIAP");
  if (Firebase.failed()) {
    Serial.print(">>> ERRO AO OBTER LED FIAP >>> ");
    Serial.println(Firebase.error());
  } else {
    digitalWrite(13, r);
    Serial.println(r);
  }
  delay(50);
}
