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
    pixels.show();
  }
}

void LEDStrip::run() {
  pixels.show();
}

void LEDStrip::turnOffAll() {
  for(uint8_t i = 0; i < numLEDs; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}

void LEDStrip::setBrightness(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness) {
  red = (red * brightness) / 100; // scale the color components according to the brightness
  green = (green * brightness) / 100;
  blue = (blue * brightness) / 100;
  for(uint8_t i = 0; i < numLEDs; i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // set the new color
  }
  pixels.show(); // update the LED strip
}


