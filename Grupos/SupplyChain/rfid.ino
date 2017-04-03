//Biblioteca wifi do nodeMCUESP8266
#include <ESP8266WiFi.h>

//https://www.arduino.cc/en/Reference/SPI
#include <SPI.h>

//Biblioteca do RFID 
//https://github.com/miguelbalboa/rfid
#include <MFRC522.h>

//https://www.arduino.cc/en/Reference/Wire
#include <Wire.h> 

//Pinos do RFID
#define RST_PIN  15 // RST-PIN für RC522 - RFID - SPI - Modul GPIO15 
#define SS_PIN  2  // SDA-PIN für RC522 - RFID - SPI - Modul GPIO2 


//Criando RFID nas posições dos pinos.
MFRC522 mfrc522(SS_PIN, RST_PIN);

//WIFI parametros.
const char* ssid = "NOME_DA_REDE_WIFI";
const char* password = "SENHA";

//MQTT parametros.
const char* mqtt_server = "m12.cloudmqtt.com";
const int mqtt_port = PORTA_MQTT;

void setup() {
  Serial.begin(9600);
  
  // Init SPI bus
  SPI.begin();           
  
  //Iniciando PCD do RFID
  mfrc522.PCD_Init();
  Serial.print("Passe o Cartao!");  
}


//Método que foi definido para receber os retornos dos tópicos que demos subscribe,
// neste caso apenas o tópico 'retorno'
//Parametros: NomedoTópico, mensagem , tamanho da mensagem
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println();
  Serial.print("Messagembida [");
  Serial.print(topic);
  Serial.print("]: ");
  String mensagem = "";
  //Conversão da mensagem recebidade de byte pra String
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }
  Serial.println(mensagem);
  Serial.println();
  
  //Chamada ao método que controla o acesso
  verificaAcesso(mensagem);
}

//Método de controle de acesso.
void verificaAcesso(String mensagem){

  if ( mensagem.substring(0,8) == "ENTRANDO" ){
    Serial.println("BEM VINDO");
    delay(1000);
    Serial.println(mensagem.substring(9));
    delay(1000);
  }else if (mensagem.substring(0,6) == "SAINDO" ){
    Serial.println("ATE MAIS");
    delay(1000);
    Serial.println(mensagem.substring(7));
    delay(1000);
  }else{
    Serial.println("Acesso negado!");
    delay(1000);
  }  
  delay(1000);
  Serial.println("Passe o Cartao!");
  return;
}


//Método de envio do id do cartão lido pra fila acesso
void sendMessage(MFRC522 mfrc522){
  Serial.print("Lendo Cartao");
  char rfidstr[15];
  char s[100];
  for (int i = 0; i < mfrc522.uid.size; i++){
    
    //Conversão de byte pra Hexadecimal
    sprintf(s,"%x",mfrc522.uid.uidByte[i]);    
    
    //Concatenando para o array de char que será enviado
    strcat( &rfidstr[i] , s);
  }
  Serial.print("Card ");
  Serial.print(rfidstr);
  
  Serial.println();
  Serial.print("Verificando...");

  return;
}

void loop() {  

  //Verificando existencia do card no leitor
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(1000);
    return;
  }

  //Verificando Leitura do card
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(1000);
    return;
  }

  //Enviando mensagem
  sendMessage(mfrc522);
    
}
