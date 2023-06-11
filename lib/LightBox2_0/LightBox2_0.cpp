#include "Arduino.h"
#include "LightBox2_0.h"
#include <MCP23016.h>
#include <MCP23016Manager.h>
#include <ButtonControl.h>
#include <LEDStrip.h>
#include <BuzzerSounds.h>
//#include <PotentiometerControl.h>


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
const int POT_PIN = A0;
#define ACTION_THRESHOLD 100


// Create MCP23016Manager object
MCP23016Manager mcpManager;

// Create the LED strip object
LEDStrip strip(LED_STRIP_PIN, 100);

// Controls: Create button object
ButtonControl button(BUTTON_PIN);

// Create Sound object
BuzzerSounds buzz(BUZZER_PIN);

// Controls: Create Potentiometer object
//PotentiometerControl potentiometer(POT_PIN);

LightBox2_0::LightBox2_0() {
  _startTime = 0;
}

void LightBox2_0::setup() {
  // <== Setup code here ==>
  
  Serial.begin(9600); // Serial

  

  button.begin(); // button

  // Check for connectivity
  if (Serial) {
    // Tone
    buzz.playR2D2();

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
  // Read all inputs
  mcpManager.readAllInputs();

  // Check the first 100 inputs
    for (int i = 0; i < ACTION_THRESHOLD; i++) {
      if (mcpManager.getInputState(i) == HIGH) {
        // Do something
        Serial.print("1");
      }else if (mcpManager.getInputState(i) == LOW)
      {
        Serial.print("0");
      }
      
    }
  
  Serial.println("");
  delay(100);

}

void LightBox2_0::db_mode() {
  // Turn all LEDs off
  strip.turnOffAll();
 // Setup the MCP23016 expanders
 uint8_t addresses[] = {MCP23016_ADDRESS_1, MCP23016_ADDRESS_2, MCP23016_ADDRESS_3, MCP23016_ADDRESS_4, MCP23016_ADDRESS_5, MCP23016_ADDRESS_6, MCP23016_ADDRESS_7};
 for (uint8_t i = 0; i < sizeof(addresses); i++) {
   if (!mcpManager.setupExpander(addresses[i])) {
     Serial.print("Failed to setup expander at address ");
     Serial.println(i);
   } else {
     Serial.print("Expander at address ");
     Serial.print(i);
     Serial.println(" is connected");
     buzz.lowFrequencyBeep();
   }
 }
 buzz.playMarioCoin();
 strip.colorCycleWithGap(2);

 Serial.println("<= END =>");
 if (button.isPressed())
 {
  /* code */
  Serial.println("Button pressed!");
 }
 
 delay(2000);
 if (button.isPressed())
 {
  /* code */
  Serial.println("Button pressed!");
 }
 strip.turnOffAll();
}

