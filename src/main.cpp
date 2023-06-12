#include "Arduino.h"
#include <LightBox2_0.h>
#include <MCP23016.h>
#include <MCP23016Manager.h>
#include <ButtonControl.h>
#include <LEDStrip.h>
#include <BuzzerSounds.h>
#include <PotentiometerControl.h>
#include <LEDController.h>

// <== Pin Setup ==>
static const int LED_STRIP_PIN = 6; // LED pin DO to DI in led strip
static const int BUZZER_PIN = 3; // Buzzer button activation
static const int BUTTON_PIN = 4; // Button pin
static const int PON_PIN = A0;



// <== Objects ==>
#define ACTION_THRESHOLD 100
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x23
#define MCP23016_ADDRESS_4 0x24
#define MCP23016_ADDRESS_5 0x25
#define MCP23016_ADDRESS_6 0x26
#define MCP23016_ADDRESS_7 0x27

// Create MCP23016Manager object
uint8_t addressArray[] = {MCP23016_ADDRESS_1, MCP23016_ADDRESS_2, MCP23016_ADDRESS_3, MCP23016_ADDRESS_4, MCP23016_ADDRESS_5, MCP23016_ADDRESS_6, MCP23016_ADDRESS_7};
MCP23016Manager mcpManager(addressArray, sizeof(addressArray)/sizeof(addressArray[0]));

// Create the LED strip object
LEDStrip strip(LED_STRIP_PIN, ACTION_THRESHOLD);

// Controls: Create button object
ButtonControl button(BUTTON_PIN);

// Create Sound object
BuzzerSounds buzz(BUZZER_PIN);

// Create Potentiometer object
PotentiometerControl pont(PON_PIN);

// Create LEDController object
LEDController LEDC(strip,pont);



LightBox2_0 program;    

void setup() {
    // Tone
    buzz.playR2D2();
    program.setup();
    LEDC._potentiometer.begin();
    LEDC._strip.turnOffAll();
    
}

void loop() {
    // Read all inputs
    mcpManager.readAllInputs();
    

    // Check the first 100 inputs
    for (int i = 0; i < ACTION_THRESHOLD; i++) {
      if (mcpManager.getInputState(i) == HIGH) {
        // Do something
        Serial.print("1");
        
        //LEDC._strip.setBrightness(i,255,0,0,);
      }else if (mcpManager.getInputState(i) == LOW)
      {
        Serial.print("0");
        //LEDC._strip.setBrightness(i,0,255,0,);
  
      }
      
    }
    Serial.print(" ");
    Serial.print(LEDC._potentiometer.getMappedValue());
    Serial.print(" ");
    Serial.print(LEDC._potentiometer.getValue());
    Serial.print(" ");
    Serial.print("B ");
    if (button.isPressed())
    {
      Serial.print("1");
    }else
    {
      Serial.print("0");
    }
        
    Serial.print(" "); 



    Serial.println("");
    delay(100);
    
}