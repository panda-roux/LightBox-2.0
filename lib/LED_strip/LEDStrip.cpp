#include <Arduino.h>
#include "LEDStrip.h"
#include "LEDController.h"



LEDStrip::LEDStrip(uint8_t pin, uint8_t num) {
  pixels = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
  numLEDs = num;
  pixels.begin();
}

void LEDStrip::setLEDColor(uint8_t led, uint8_t red, uint8_t green, uint8_t blue) {
  if (led < numLEDs) {
    pixels.setPixelColor(led, pixels.Color(red, green, blue));
    run();
  }
}

void LEDStrip::run() {
  pixels.show();
}

void LEDStrip::turnOffAll() {
  for(uint8_t i = 0; i < numLEDs; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  run();
}

void LEDStrip::setBrightness(uint8_t i, uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness) {
  red = (red * brightness) / 100; // scale the color components according to the brightness
  green = (green * brightness) / 100;
  blue = (blue * brightness) / 100;
  pixels.setPixelColor(i, pixels.Color(red, green, blue)); // set the new color
  Serial.print(red);// Debug line
  Serial.print(" ");// Debug line 
  Serial.print(green);// Debug line
  Serial.print(" ");// Debug line
  Serial.print(blue);// Debug line
  Serial.print(" ");// Debug line 

  run(); // update the LED strip
}


