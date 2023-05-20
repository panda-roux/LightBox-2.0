// MCP23016Manager.h
#ifndef MCP23016MANAGER_H
#define MCP23016MANAGER_H

#include <Arduino.h>
#include "MCP23016.h"

class MCP23016Manager {
public:
     MCP23016Manager(MCP23016* mcpArray[], uint8_t size);
    ~MCP23016Manager();
    void checkInputs();

private:
    MCP23016** _mcpArray;
    uint8_t _size;
    uint16_t* _previousStates;
};

#endif
