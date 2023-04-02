#include <Arduino.h>
#include "LEDsrtip_class.cpp"

LEDStrip strip(6, 100); // instantiate a LEDStrip object connected to pin 6 with 100 LEDs

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // set LED colors debug
  strip.setLEDColor(0, 255, 0, 0); // set the first LED to red
  strip.setLEDColor(50, 0, 255, 0); // set the 50th LED to green
  strip.setLEDColor(99, 0, 0, 255); // set the last LED to blue

  // run the LED strip
  strip.run();

  // do other stuff here
}
