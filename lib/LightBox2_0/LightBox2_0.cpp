#include "Arduino.h"
#include "LightBox2_0.h"

LightBox2_0::LightBox2_0() {
  _startTime = 0;
}

void LightBox2_0::setup() {
  // Setup code here

  // Check for connectivity
  if (Serial) {
    // If a serial connection is available, enter debug mode
    Serial.println("Entering debug mode...");
    // Add any additional debug setup code here
  } else {
    // If no serial connection is available, continue as normal
    // Add any additional normal setup code here
  }
}

void LightBox2_0::loop() {
  // Code to run on every cycle

  // Time counter
  unsigned long currentTime = millis();
  if (_startTime == 0) {
    _startTime = currentTime;
  }
  Serial.print("Time elapsed: ");
  Serial.println(currentTime - _startTime);
}

void LightBox2_0::checkSerial() {
  if (Serial.available() > 0) {
    // Handle available serial data
    // Add error handling here
  }
}

void LightBox2_0::present() {
  // Code for present function
}

void LightBox2_0::past() {
  // Code for past function
}
