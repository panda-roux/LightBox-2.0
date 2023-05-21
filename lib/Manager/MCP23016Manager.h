#ifndef MCP23016Manager_h
#define MCP23016Manager_h

#include "Arduino.h"
#include "MCP23016.h"

#define MAX_EXPANDERS 7

class MCP23016Manager {
public:
    MCP23016Manager();
    ~MCP23016Manager();
    bool setupExpander(uint8_t address);
    void readAllInputs();
    uint16_t getInputState(uint8_t inputNumber);

private:
    MCP23016* expanders[MAX_EXPANDERS];
    uint8_t expanderCount;
    uint16_t inputStates[MAX_EXPANDERS * 16];
};

#endif