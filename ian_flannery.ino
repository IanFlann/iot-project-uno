/
PIR HCSR501
-modified on 5 Feb 2019
by Saeed Hosseini @ ElectroPeak
https://electropeak.com/learn/guides/
-modified 22 Feb 2020
by Ian Flannery /
int ledPin = 13; // LED pin
int pirPin = 2; // PIR Out pin
int pirStat = 0; // PIR status

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(pirPin, INPUT);
Serial.begin(9600);
}

void loop(){
pirStat = digitalRead(pirPin);
if (pirStat == LOW && ledPin == HIGH){ // if motion isn't detected and light is on
digitalWrite(ledPin, LOW); // turn LED off
}
else if (pirStat == HIGH && ledPin == LOW){ // if motion detected and light is off
digitalWrite(ledPin, HIGH); // turn LED on
}
}
