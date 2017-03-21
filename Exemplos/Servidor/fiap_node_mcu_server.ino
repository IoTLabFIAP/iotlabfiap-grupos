#include <ESP8266WiFi.h>
 
const char* ssid = "NOME DA REDE";
const char* password = "SENHA DA REDE";
 
int ledPin = 13; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Conectando em: ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Verifica se o client está conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  //Espera um client enviar novos dados
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Le a primeira linha da requisição
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Faz a requisição
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 
// Modifica o estado do led, com o valor obtido na requisicao
  digitalWrite(ledPin, value);
 
  // Retorna uma reposta
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("O Led está : ");
 
  if(value == HIGH) {
    client.print("Ligado");
  } else {
    client.print("Desligado");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Ligar </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Desligar </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Cliente desconectado");
  Serial.println("");
 
}
 
