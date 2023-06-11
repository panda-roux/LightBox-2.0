#include <Adafruit_NeoPixel.h>

class LEDStrip {
  private:
    Adafruit_NeoPixel pixels;
    uint8_t numLEDs;

  public:
    LEDStrip(uint8_t pin, uint8_t num) {
      pixels = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
      numLEDs = num;
      pixels.begin();
    }

    void setLEDColor(uint8_t led, uint8_t red, uint8_t green, uint8_t blue) {
      if (led < numLEDs) {
        pixels.setPixelColor(led, pixels.Color(red, green, blue));
        pixels.show();
      }
    }

    void run() {
      pixels.show();
    }
};
