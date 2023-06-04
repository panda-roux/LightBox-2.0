#include "Arduino.h"
#include "BuzzerSounds.h"

BuzzerSounds::BuzzerSounds(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void BuzzerSounds::lowFrequencyBeep()
{
  tone(_pin, 20, 100); // Send a 20 Hz sound signal to the buzzer for 100ms
  delay(1000); // Wait for 1000 millisecond(s) before the next beep
}

void BuzzerSounds::playMarioCoin()
{
  // Play the "Mario Coin" sound
  tone(_pin, 1318, 125); // Note E6
  delay(125);
  noTone(_pin);
  delay(125);
}

void BuzzerSounds::playR2D2()
{
  // Play a sound similar to R2D2's beep
  tone(_pin, 1397, 100); // Note F6
  delay(200);
  tone(_pin, 2093, 100); // Note C7
  delay(200);
  noTone(_pin);
}
