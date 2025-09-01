#include <Servo.h>

const int servoPin = 7;   // Change to the actual pin you are using for the servo
const int switchPin = 9;  // Pin number for the digital input switch (proximity sensor)
const int redLedPin = 12; // red led pin
const int greenLedPin = 10; //green led pin

Servo myServo;

String lastSerialData;
int previousSwitchState = HIGH;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(switchPin, INPUT);
  // Read the initial state of the switch
  previousSwitchState = digitalRead(switchPin);
}

void loop() {
  // Read the most recent serial data
  String serialData = Serial.readStringUntil('\n');

  if (serialData == "cracked" || serialData == "normal") {
    // Store the most recent serial data
    lastSerialData = serialData;
  }

  // Read the current state of the switch
  int currentSwitchState = digitalRead(switchPin);

  // Perform the corresponding action based on the last received serial data
  if (lastSerialData == "cracked") {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    // Check if the switch state is low and was previously high
    if (currentSwitchState == LOW && previousSwitchState == HIGH) {
      // Turn the servo from 90 (we start at 90) to 0 degrees and back to 90
      myServo.write(60);
      delay(8000);        // Adjust the delay as needed
      myServo.write(90);  // Return to the center position
    } 
  }
  else if (lastSerialData == "normal") {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      if (currentSwitchState == LOW && previousSwitchState == HIGH) {
      // Turn the servo from 90 (we start at 90) to 180 degrees and back to 90
      myServo.write(120);
      delay(8000);        // Adjust the delay as needed
      myServo.write(90);  // Return to the center position
    } 
  }
  // Update the previous switch state for the next iteration
  previousSwitchState = currentSwitchState;
}

