#ifndef MCP23016_H
#define MCP23016_H

#include <Wire.h>

#define MCP23016_ADDRESS 0x20 // Default I2C Address

class MCP23016 {
public:
    MCP23016(uint8_t address = MCP23016_ADDRESS);
    bool begin();
    uint16_t readGPIO();

private:
    uint8_t _address;
    void writeRegister(uint8_t reg, uint8_t value);
    uint8_t readRegister(uint8_t reg);
};

#endif
