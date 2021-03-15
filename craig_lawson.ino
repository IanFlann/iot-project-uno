// constants won't change. They're used here to set pin numbers:
const int irPin = 2; // the number of the pushbutton pin
const int buzzerPin = 3;
const int vibrationPin =4;

// variables will change:
int irState = 0; // variable for reading the pushbutton status
int vibrationState = 0; // variable for reading the vibration status

void setup() {
pinMode(buzzerPin, OUTPUT); // initialize the buzzer as an output:
pinMode(irPin, INPUT); // using the button as a replacement for the IR sensor:
pinMode(vibrationPin, INPUT); // initialize the buzzer as an input:
}

void loop() {
irState = digitalRead(irPin); // read the state of the pushbutton value:
vibrationState = digitalRead(vibrationPin);

// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
if (irState == HIGH && vibrationState == HIGH) //this could be one or the other either{
// turn LED on:
digitalWrite(ledPin, HIGH); //this turns on the buzzer and led as these parameters are met either from someone entering the room or leaving alerting them about the light
digitalWrite(buzzerPin, HIGH);

}
else {
// turn LED off:
digitalWrite(ledPin, LOW);
digitalWrite(buzzerPin, LOW);
}
}
