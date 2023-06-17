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
static const int BUTTON_PIN = 2; // Button pin
static const int PON_PIN = A0;



// <== Objects ==>
#define ACTION_THRESHOLD 100

// Define the I2C addresses for your MCP23016 devices
uint8_t addresses[7] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26};



// Create MCP23016Manager object
MCP23016Manager mcpManager;

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
        Serial.print(mcpManager.getInputState(i));
        //Serial.print("1");
        
        //LEDC._strip.setBrightness(i,255,0,0,);
      }else if (mcpManager.getInputState(i) == LOW)
      {
        Serial.print(mcpManager.getInputState(i));
        //Serial.print("0");
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