#ifndef MCP23016_h
#define MCP23016_h

#include <Arduino.h>
#include <Wire.h>

class MCP23016 {
  public:
    MCP23016(uint8_t address);
    void begin();
    uint16_t readInputs();
    bool isConnected();
  private:
    uint8_t _address;
};

#endif
