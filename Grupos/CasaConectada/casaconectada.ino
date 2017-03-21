
/*  Casa Conectada  by Ezequiel França   http://www.ezefranca.com

----------------------  Notes ----------------------  ----------------------

1) Sensor de presença: PIN 13 ou D7 no NodeMCU
2) Sensor de Ruido (Microfone): PIN A0

 ----------------------       ----------------------  ----------------------
*/


int sensorPresenca = 13;  //Pino ligado ao sensor de presença
int sensorRuido = A1;  //Pino ligado ao sensor de ruído
int statusSensorPresenca;
int statusSensorRuido;

void setup()
{
  pinMode(sensorPresenca, INPUT);   //Define pino como entrada
  pinMode(sensorRuido, INPUT);   //Define pino como entrada
}

void loop()
{
  
 statusSensorPresenca = digitalRead(sensorPresenca); //Le o valor do sensor PIR
 statusSensorRuido = analogRead(sensorRuido);

 Serial.print("Volume do som está: ");
 Serial.print(statusSensorRuido);
 
 if (statusSensorPresenca == LOW)  //Sem movimento, mantem led azul ligado
 {
    Serial.println("Sem movimento...");
 }
 else  //Caso seja detectado um movimento, aciona o led vermelho
 {
    Serial.println("Movimento Detectado...");
 }
}
