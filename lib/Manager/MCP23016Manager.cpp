// MCP23016Manager.cpp
#include "MCP23016Manager.h"

MCP23016Manager::MCP23016Manager(MCP23016* mcpArray[], uint8_t size)
    : _mcpArray(mcpArray), _size(size)
{
    _previousStates = new uint16_t[size];
    for (uint8_t i = 0; i < size; i++) {
        _previousStates[i] = _mcpArray[i]->readGPIO();
    }
}

MCP23016Manager::~MCP23016Manager() {
    delete[] _previousStates;
}


uint8_t MCP23016Manager::getChangedPins(int changedPins[MAX_CHANGES]) {
    uint8_t numChanges = 0;
    for (uint8_t i = 0; i < _size; i++) {
        uint16_t currentState = _mcpArray[i]->readGPIO();
        uint16_t changes = currentState ^ _previousStates[i];
        for (uint8_t j = 0; j < 16; j++) {
            if (changes & (1 << j)) {
                int pinNumber = i * 16 + j;
                if (numChanges < MAX_CHANGES) {
                    changedPins[numChanges] = pinNumber;
                    numChanges++;
                }
            }
        }
        _previousStates[i] = currentState;
    }
    return numChanges;
}
