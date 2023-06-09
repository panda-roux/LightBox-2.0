#include "Arduino.h"
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
bool db_mode_flag = false;




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
Timer timeMain;

void data_header(){
  Serial.print("!=============================================== Readings =====================================================! B Pm Ct");
  Serial.println(" ");
  delay(1000);
}

void db_mode_head(){
  //<== START ==>
  Serial.flush();
  Serial.println("");
  
  // Change debug flag
  db_mode_flag = true;
  Serial.print("Entering debug mode.");
  for (size_t i = 0; i < 5; i++)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" ");

  // Tone
  if (db_mode_flag)
  {
    buzz.playR2D2();
  }
   
  // Extenders first check
  for (int i = 0; i < 7; i++) {
    if (!manager.setupExpander(addresses[i])) {
      Serial.print("Failed to setup expander at address ");
      Serial.println(addresses[i], HEX);
    }
  }

  // Extenders Second ckeck
  manager.checkConnectivity();

  // Data Legend
  Serial.println("B = button: 1 is pressed, 0 is not pressed");
  Serial.println("Pm = Potentiometer mapped value from 0 to 100");
  Serial.println("Ct = Cycle time in milliseconds");
  delay(500);
  Serial.print("Starting.");
  for (size_t i = 0; i < 2; i++)
  {
    if (db_mode_flag)
    {
      buzz.playMarioCoin();
    }
    
    Serial.print(".");
    delay(500);
  }
  Serial.println("");

  // Data Hedder
  data_header();  
  
  //<= Exit HEAD =>
}

void setup() {
    // Pre-run steps
    LEDC._potentiometer.begin();
    // Serial connection
    Serial.flush();
    Serial.begin(9800);
    if (!Serial)
    {
      buzz.lowFrequencySiren();
    }else
    {
      /* Debug mode */
      db_mode_head();
    }
    LEDC._strip.turnOffAll();

}

void loop() {
    // entry cloock
  timeMain.tick();
    
  // Check the first 100 inputs
  int index = 0;

    /* Action with a ctivation. TBC */
  for (int i = 0; i < 7; i++) {
    uint16_t gpio = manager.readExpander(i);
    for (int pin = 0; pin < 16; pin++) {
      bool isHigh = (gpio >> pin);
      index ++;
      if (isHigh) {
        // Do something if the pin is HIGH
        Serial.print("1");
        if (index<=100)
        {
          LEDC.blinkUninterruptibleR(index, 0, 3000);
          Serial.print(" ");
          Serial.print(index);
          Serial.print(" ");
        }

      } else {
      // Do something else if the pin is LOW
      //LEDC.led_off(index);
      Serial.print("0");
      }
      index ++;
      
    }
  } 

  // Button check
  if (button.isPressed())
  {
    Serial.print(" 1 ");
  }else
  {
    Serial.print(" 0 ");
  }
  
  // Potentiometer mapped reading
  Serial.print(pont.getMappedValue());
  Serial.print(" ");

  // Cycle time
  Serial.print(timeMain.tock());
  //Serial.print(" ");

  // New line
  Serial.println(" ");

  LEDC.blinkUninterruptibleG(0, 2000, 500);
  LEDC._strip.run();
  
}



