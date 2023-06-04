#include "Arduino.h"
#include "LightBox2_0.h"
#include <MCP23016.h>
#include <MCP23016Manager.h>
#include <ButtonControl.h>
#include <PotentiometerControl.h>
#include <LEDStrip.h>


// Define the I2C addresses of the MCP23016 chips
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x22
#define MCP23016_ADDRESS_4 0x23
#define MCP23016_ADDRESS_5 0x24
#define MCP23016_ADDRESS_6 0x25
#define MCP23016_ADDRESS_7 0x26

static const int LED_STRIP_PIN = 6;
static const int BUZZER_PIN = 3;
static const int BUTTON_PIN = 4;
static const int POT_PIN = A0;


// Create MCP23016Manager object
MCP23016Manager mcpManager;

// Create the LED strip object
LEDStrip strip(LED_STRIP_PIN, 100);

// Create button object
ButtonControl button(BUTTON_PIN);

// creates potentiometer object
PotentiometerControl potentiometer(POT_PIN);


LightBox2_0::LightBox2_0() {
  _startTime = 0;
}

void LightBox2_0::setup() {
  // Setup code here
  Serial.begin(9600);

  button.begin(); // button

  potentiometer.begin(); // Potentiometer
    

  // Check for connectivity
  if (Serial) {
    // If a serial connection is available, enter debug mode
    Serial.println("Entering debug mode...");
    // Add any additional debug setup code here
    DEBUG_mode();
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

void LightBox2_0::db_Potentiometer() {
  int rawValue = potentiometer.getValue();
    int mappedValue = potentiometer.getMappedValue();

    Serial.print("Raw Value: ");
    Serial.print(rawValue);
    Serial.print(" | Mapped Value: ");
    Serial.println(mappedValue);
}

void LightBox2_0::past() {
  // Code for past function
}

void LightBox2_0::DEBUG_mode() {
  // Setup the MCP23016 expanders
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_1)) {
        Serial.println("Failed to setup expander at address 0");
    }else
    {
      /* code */
      Serial.println("Expander at address 0 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_2)) {
        Serial.println("Failed to setup expander at address 1");
    }else
    {
      /* code */
      Serial.println("Expander at address 1 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_3)) {
        Serial.println("Failed to setup expander at address 2");
    }else
    {
      /* code */
      Serial.println("Expander at address 2 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_4)) {
        Serial.println("Failed to setup expander at address 3");
    }else
    {
      /* code */
      Serial.println("Expander at address 3 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_5)) {
        Serial.println("Failed to setup expander at address 4");
    }else
    {
      /* code */
      Serial.println("Expander at address 4 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_6)) {
        Serial.println("Failed to setup expander at address 5");
    }else
    {
      /* code */
      Serial.println("Expander at address 5 is connected");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_7)) {
        Serial.println("Failed to setup expander at address 6");
    }else
    {
      /* code */
      Serial.println("Expander at address 6 is connected");
    }
}
