#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include <Arduino.h>
#include <LEDStrip.h> // LED class
#include <PotentiometerControl.h>
#include <Timer.h>

#define MAX_CHANGES 16
#define DEFULT_DELAY_FOR_LIGTH 300


class LEDController {
public:
    LEDController(LEDStrip& ledStrip,PotentiometerControl& Pod);
    void red_high_reg(int i);
    void green_high_reg(int i);
    void blick(uint8_t led, uint8_t colour);
    void blue_high_reg(int i);
    void clockStart();
    void led_off (int i);

    Timer timerLOW;
    Timer timerHILH;
    LEDStrip& _strip;
    PotentiometerControl& _potentiometer;
    
private:
    
    
};
#endif
