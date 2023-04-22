#include <Arduino.h>
#include "LEDsrtip_class.cpp"

#include <Wire.h>
#include "C:\Users\battl\Documents\PlatformIO\Projects\LightBox 2.0\lib\Sensor\MCP23016.h"

// instantiate a LEDStrip object connected to pin 6 with 100 LED
// instantiate 7 Controller objects 


#define MCP23016_ADDRESS 0x20

MCP23016 mcp(MCP23016_ADDRESS);

LEDStrip strip(6, 100); 

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
  mcp.begin();

  if (mcp.isConnected()) {
    Serial.println("MCP23016 connected!");
  } else {
    Serial.println("MCP23016 not found. Check connections.");
  }


  turn_LEDs_off();
   
  
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
  

  uint16_t inputValues = mcp.readInputs();
  Serial.print("Input values: ");
  Serial.println(inputValues, BIN);
  // do other stuff here


}

