int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int SensorDeToque = 2; 
int Signal;                          // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;                 // Determine which Signal to "count as a beat", and which to ingore. 


// The SetUp Function:
void setup() {       
   Serial.begin(9600);         // Set's up Serial Communication at certain speed. 
   pinMode(SensorDeToque, INPUT);
}

// The Main Loop Function

void loop() {

// Toque

int estado = digitalRead(sinal); 

 if(estado==1){  
  Serial.println("Tocou");  
  delay(10);      
 }  


// Batimentos
  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value. 
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.

   
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     Serial.println("Tem batimento");         
   } else {
     Serial.println("Nao tem batimento");    
   }
   
delay(10);  
}
