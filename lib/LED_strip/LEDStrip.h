#ifndef LEDStrip_h
#define LEDStrip_h
#include <Adafruit_NeoPixel.h>

class LEDStrip {
 private:
  Adafruit_NeoPixel pixels;
  uint8_t numLEDs;

 public:
  LEDStrip(uint8_t pin, uint8_t num);
  void setLEDColor(uint8_t led, uint8_t red, uint8_t green, uint8_t blue);
  void run();
  void turnOffAll();
  void setBrightness(uint8_t brightness);
  void colorCycleWithGap(uint8_t gap);

  void setBrightnessPercentage(uint8_t percentage) {
    uint8_t brightness = map(percentage, 0, 100, 0, 255);
    setBrightness(brightness);
  }
};

#endif
