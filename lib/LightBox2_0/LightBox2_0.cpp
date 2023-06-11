#include "Arduino.h"
#include "LightBox2_0.h"
#include <MCP23016.h>
#include <MCP23016Manager.h>

#include <LEDStrip.h>
#include <BuzzerSounds.h>

//#include <PotentiometerControl.h>

// <== Adresses ==>
// Define the I2C addresses of the MCP23016 chips
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x22
#define MCP23016_ADDRESS_4 0x23
#define MCP23016_ADDRESS_5 0x24
#define MCP23016_ADDRESS_6 0x25
#define MCP23016_ADDRESS_7 0x26

// Controls: Create Potentiometer object
//PotentiometerControl potentiometer(POT_PIN);

LightBox2_0::LightBox2_0() {
  _startTime = 0;
}

void LightBox2_0::setup() {
  // <== Setup code here ==>
  Serial.begin(9600); // Serial

  // Check for connectivity
  if (Serial) {
    

    // If a serial connection is available, enter debug mode

    Serial.println("Entering debug mode...");
    // Add any additional debug setup code here
    db_mode();

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
  //Serial.print("Time elapsed: ");
  //Serial.println(currentTime - _startTime);
  LigthBox_one();

  // 
}

void LightBox2_0::checkSerial() {
  if (Serial.available() > 0) {
    // Handle available serial data
    // Add error handling here
  }
}
void LightBox2_0::tick() {
  // Code for tick function
}
void LightBox2_0::tock() {
  // Code for tock function
}

void LightBox2_0::present() {
  // Code for present function
}

void LightBox2_0::past() {
  // Code for past function
}

void LightBox2_0::LigthBox_one() {
  // Code for LigthBox 1.0 program function
}

void LightBox2_0::db_mode() {
 // Debuging mode
}
