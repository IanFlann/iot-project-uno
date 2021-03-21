
/*

PIR HCSR501 

modified on 18 March 2021
By Mark Lavin

Attributes
https://anasdalintakam.blogspot.in/
Saeed Hosseini @ ElectroPeak
https://electropeak.com/learn/guides/

*/
//Libraries
#include <ArduinoJson.h>

 //PIR
int ledPin = A1;                 // discuss if needed with Team????
int pirPin = A2;                 // PIR Out pin 
int pirStat = LOW;              // PIR status
int val = 0;     

//Light sensor
int temt6000Pin = A0; //pin for reading sensor data
float light;
int light_value;


void setup() {    
  
  pinMode(pirPin, INPUT);     
  Serial.begin(9600);
  
  pinMode(temt6000Pin, INPUT); //data pin for ambientlight sensor
  //pinMode(TBC, OUTPUT);
}
 
void loop(){
  
  int light_value = analogRead(temt6000Pin);
  light = light_value * 0.0976;// percentage calculation  had to google cause sensor was giving me stupid readings. 
  Serial.println(light);
  delay(100);
  
  pirStat = digitalRead(pirPin); 
  
  if (pirStat = HIGH && light_value > 400) {   // if motion detected & light
  digitalWrite(ledPin, HIGH);
  } 
  else 
  {
  digitalWrite(ledPin, LOW);
  }
}
