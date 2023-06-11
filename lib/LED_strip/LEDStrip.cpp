#include "LEDStrip.h"
#include "LEDController.h"
//#include <PotentiometerControl.h>



// creates potentiometer object

LEDStrip::LEDStrip(uint8_t pin, uint8_t num) {
  pixels = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
  numLEDs = num;
  pixels.begin();
  //potentiometer.begin();
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

void LEDStrip::setBrightness(uint8_t brightness) {
  for(uint8_t i = 0; i < numLEDs; i++) {
    uint32_t color = pixels.getPixelColor(i);
    uint8_t r = (uint8_t)(color >> 16),
            g = (uint8_t)(color >>  8),
            b = (uint8_t) color;
    r = (r * brightness) / 100; // scale the color components according to the brightness
    g = (g * brightness) / 100;
    b = (b * brightness) / 100;
    pixels.setPixelColor(i, pixels.Color(r, g, b)); // set the new color
  }
  pixels.show(); // update the LED strip
}

