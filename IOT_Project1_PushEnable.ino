
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
#include <Bridge.h>
#include <HttpClient.h>
 //PIR
int ledPin = A1;                 // discuss if needed with Team????
int pirPin = A2;                 // PIR Out pin 
int pirStat = LOW;              // PIR status
int val = 0;     

//Light sensor
int temt6000Pin = A0; //pin for reading sensor data
float light;
int light_value;

//Pushing box - Pushbullet
char devid[] = "vDC5AB035066E0F0";
char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
void setup() {    
  Serial.begin(9600);
  //Establishing connection
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  
  pinMode(pirPin, INPUT);     
  pinMode(temt6000Pin, INPUT); //data pin for ambientlight sensor
  //pinMode(TBC, OUTPUT);
}
 
void loop(){
  HttpClient client;
  
  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid);

  int light_value = analogRead(temt6000Pin);
  light = light_value * 0.0976;// percentage calculation  had to google cause sensor was giving me stupid readings. 
  Serial.println(light);
  Serial.println(pirStat);
  delay(100);
  
  pirStat = digitalRead(pirPin); 
  
  if (pirStat = HIGH && light > 80) {
    // if motion detected & light sends api call
  digitalWrite(ledPin, HIGH);
  client.get (APIRequest);
  
  } 
  else 
  {
  digitalWrite(ledPin, LOW);
  }
}
