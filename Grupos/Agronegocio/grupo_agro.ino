int sensorDeChuva = 2; //Pino ligado ao D0 do sensor
int SensorDeLuminosidade = A1; //Pino ligado ao A0 do sensor

int chuva = 0; //Armazena o valor lido do pino digital do sensor de chuva
int luminosidade = 0; //Armazena o valor lido do pino analogico do sensor de luminosidade
int intesidadeLux = 0;

void setup()
{
  // Define os pinos do sensores como entrada
  pinMode(sensorDeChuva, INPUT);
  pinMode(SensorDeLuminosidade, INPUT);

}

void loop()
{
  //Le e arnazena o valor do sensor de chuva
  chuva = digitalRead(sensorDeChuva);
  //Le e armazena o valor do sensor de luminosidade
  luminosidade = analogRead(luminosidade);
  //Envia as informacoes para o serial monitor
  Serial.print("Valor digital : ");
  Serial.print(chuva);
  Serial.print(" - Valor analogico : ");
  Serial.println(luminosidade);
 
    // Le o valor - analogico - do LDR  
  valorpot = analogRead(pinopot);  

  // Converte o valor lido do LDR
  intesidadeLux = map(valorpot, 0, 1023, 0, 255); 
  Serial.print("Valor lido do LDR : ");   

  // Mostra o valor lido do LDR no monitor serial  
  Serial.print(luminosidade);  
  Serial.print(" = Luminosidade : ");  

  // Mostra o valor da luminosidade no monitor serial  
  Serial.println(intesidadeLux); 


}
