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
    void clockTick();
    void clockTock();
    void led_off (int i);
    void blinkUninterruptibleR(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow);
    void blinkUninterruptibleG(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow);
    void blinkUninterruptibleB(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow);

    
    
    LEDStrip& _strip;
    PotentiometerControl& _potentiometer;
    
private:
    Timer _timerHigh;
    Timer _timerLow;
    bool _isHigh;
};
#endif
