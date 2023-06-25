#include "Arduino.h"
#include <LightBox2_0.h>
#include <MCP23016.h>
#include <MCP23016Manager.h>
#include <ButtonControl.h>
#include <LEDStrip.h>
#include <BuzzerSounds.h>
#include <PotentiometerControl.h>
#include <LEDController.h>
#include <Timer.h>

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
MCP23016Manager manager;

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

// Set timers
Timer timer_down_blink(100);
Timer timer_up_blink(300);
//Timer timer_gap_blink(1000);

   
void blink(){
  if (timer_down_blink.check())
  {
    if (timer_up_blink.check())
    {
      LEDC.led_off(1);
      LEDC.led_off(100);
      timer_down_blink.reset();
    }else
    {
      LEDC.green_high_reg(1);
      LEDC.blue_high_reg(100);
    }
  }
  
}


void setup() {
    // Tone
    buzz.playR2D2();
    
    LEDC._potentiometer.begin();
    LEDC._strip.turnOffAll();

    // Setup the MCP23016 devices
  for (int i = 0; i < 7; i++) {
    if (!manager.setupExpander(addresses[i])) {
      Serial.print("Failed to setup expander at address ");
      Serial.println(addresses[i], HEX);
    }
  }

  // Check connectivity
  manager.checkConnectivity();

}

void loop() {
    // Read all inputs
    manager.readAllInputs();

    // Check the first 100 inputs
    int index = 0;
    for (int i = 0; i < 7; i++) {
      uint16_t gpio = manager.readExpander(i);
      for (int pin = 0; pin < 16; pin++) {
        bool isHigh = (gpio >> pin) & 1;
        index ++;
        if (isHigh) {
          // Do something if the pin is HIGH
          Serial.print("1");
        } else {
          // Do something else if the pin is LOW
          Serial.print("0");
        }
      }
    }
    index = 0;
    manager.readAllInputs();    
    Serial.println(" ");
    
}