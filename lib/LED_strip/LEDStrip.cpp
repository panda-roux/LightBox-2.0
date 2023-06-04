#include "LEDStrip.h"

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
void LEDStrip::colorCycleWithGap(uint8_t gap) {
  uint8_t red = 255, green = 0, blue = 0;
  uint8_t brightness = 100; // Start with full brightness
  for(uint8_t i = 0; i < numLEDs; i++) {
    if(i % (gap + 1) == 0) {
      // Cycle through colors
      if(red == 255 && green < 255 && blue == 0) {
        green += 5;
      } else if(red > 0 && green == 255 && blue == 0) {
        red -= 5;
      } else if(red == 0 && green == 255 && blue < 255) {
        blue += 5;
      } else if(red == 0 && green > 0 && blue == 255) {
        green -= 5;
      } else if(red < 255 && green == 0 && blue == 255) {
        red += 5;
      } else if(red == 255 && green == 0 && blue > 0) {
        blue -= 5;
      }
      // Apply brightness
      uint8_t r = (red * brightness) / 100;
      uint8_t g = (green * brightness) / 100;
      uint8_t b = (blue * brightness) / 100;
      pixels.setPixelColor(i, pixels.Color(r, g, b));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Turn off the LED
    }
  }
  pixels.show(); // Update the LED strip
  // Decrease brightness for next cycle
  brightness -= 5;
  if(brightness < 0) brightness = 0; // Don't go below 0
}
