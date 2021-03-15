/*
 SMS sender
 created 25 Feb 2012
 by Tom Igoe
 
 -modified 22 Feb 2020
by Ian Flannery

 modified 26 Feb 2021
 by Mark Lavin
 
 */
int ledPin = 13;                // LED pin
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                // PIR status

#include <GSM.h>
#define PINNUMBER ""

// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;

void setup() {
  
   pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  while (notConnected) {
    if (gsmAccess.begin(0000) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(10000);
    }
  }
  Serial.println("GSM ready");
}

void loop() {
  pirStat = digitalRead(pirPin); 
 if (pirStat == LOW && ledPin == HIGH){      // if motion isn't detected and light is on
   digitalWrite(ledPin, LOW);               // turn LED off 
   
     //example predetermined number - This can be alter to take serial input
  char externalNum[16] = {"0876666666"};  // telephone number to send sms 
  Serial.println(externalNum);

  // sms text
  char txtMsg[] = {"You have missed all group meetings thus far."};
                                                 
  Serial.println("SENDING");
  Serial.println();
  Serial.println("Message:");
  Serial.println(txtMsg);

  // send the message
  sms.beginSMS(externalNum);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nSent\n");
  
 } 
 else if (pirStat == HIGH && ledPin == LOW){   // if motion detected and light is off
   digitalWrite(ledPin, HIGH);              // turn LED on

}
  }
