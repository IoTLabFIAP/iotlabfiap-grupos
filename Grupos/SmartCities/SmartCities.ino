#include "DHT.h"         //include DHT library
#define DHTPIN 3         //define as DHTPIN the Pin 3 used to connect the Sensor
#define DHTTYPE DHT11    //define the sensor used(DHT11)

DHT dht(DHTPIN, DHTTYPE);//create an instance of DHT
int sensorRuido = A1;  //Pino ligado ao sensor de ruído

/*setup*/
void setup() {
  Serial.begin(9600);    //initialize the Serial communication
  delay(6000);           //wait 6 seconds
  pinMode(sensorRuido, INPUT);   //Define pino como entrada
  Serial.println("Temperature and Humidity test!");//print on Serial monitor
  Serial.println("T(C) \tH(%)");                   //print on Serial monitor
  dht.begin();           //initialize the Serial communication
}
/*loop*/
void loop() {
 
 statusSensorRuido = analogRead(sensorRuido);
 Serial.print("Volume do som está: ");
 Serial.print(statusSensorRuido);
 
  float h = dht.readHumidity();    // reading Humidity 
  float t = dht.readTemperature(); // read Temperature as Celsius (the default)
  // check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(t, 2);    //print the temperature
  Serial.print("\t");
  Serial.println(h, 2);  //print the humidity
  delay(2000);           //wait 2 seconds
}
