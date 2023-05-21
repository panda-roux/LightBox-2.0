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
};

#endif
