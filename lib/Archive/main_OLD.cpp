#include <Arduino.h>
#include "LEDsrtip_class.cpp"

#include <Wire.h>
#include "C:\Users\battl\Documents\PlatformIO\Projects\LightBox 2.0\lib\Manager\MCP23016Manager.h"

// instantiate a LEDStrip object connected to pin 6 with 100 LED
// instantiate 7 Controller objects 
LEDStrip strip(6, 100); 

// Define an array to hold MCP23016 addresses
byte mcpAddresses[] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26};

MCP23016  mcpArray[7] = {
  MCP23016(mcpAddresses[0]),
  MCP23016(mcpAddresses[1]),
  MCP23016(mcpAddresses[2]),
  MCP23016(mcpAddresses[3]),
  MCP23016(mcpAddresses[4]),
  MCP23016(mcpAddresses[5]),
  MCP23016(mcpAddresses[6])
};

void turn_LEDs_off(){
  for (size_t i = 0; i < 100; i++)
  {
    /* Resset */
    strip.setLEDColor(i,0,0,0); // set all leds off

  }
  strip.run(); // update leds
};

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  
  
  Serial.println("");
  Serial.println("=> Start <=");
  Serial.println("");
  Serial.begin(9600);
 


}

//Variables
float dimerVavue = 0.7;

void loop() {
  // set LED colors debug
  strip.setLEDColor(0, 255, 0, 0); // set the first LED to red
  strip.setLEDColor(9, 255, 0, 0); // set the 10th LED to red
  strip.setLEDColor(49, 0, 255, 0); // set the 50th LED to green
  strip.setLEDColor(99, 0, 0, 255); // set the last LED to blue

  // run the LED strip
  strip.run();
  

  //}Serial.println();
  delay(1000);

  for (int i = 0; i < 4; i++) {
    
    
    
    if(mcpArray[i].begin()){
      Serial.print(" ~*~ MCP23016 at address ");
      Serial.print(mcpAddresses[i], HEX);
      Serial.print(" And read's: ");
      Serial.println(mcpArray[i].readGPIO(), BIN);
    }
    else{
      Serial.print(" ~*~ MCP23016 at address ");
      Serial.print(mcpAddresses[i],  HEX);
      Serial.println(" is NOT connected.");
    }

  }
  

  
  // do other stuff here


}

