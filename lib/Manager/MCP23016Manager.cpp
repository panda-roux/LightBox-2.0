// MCP23016Manager.cpp
#include "MCP23016Manager.h"
#include "LEDsrtip_class.cpp" // Replace with the actual name of your LED class
LEDStrip strip(6, 100); 

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

void MCP23016Manager::checkInputs() {
    for (uint8_t i = 0; i < _size; i++) {
        uint16_t currentState = _mcpArray[i]->readGPIO();
        uint16_t changedPins = currentState ^ _previousStates[i];
        for (uint8_t j = 0; j < 16; j++) {
            if (changedPins & (1 << j)) {
                int ledNumber = i * 16 + j;
                if (currentState & (1 << j)) {
                    // Pin activated, turn the LED red
                    strip.setLEDColor(ledNumber, 255, 0, 0);
                } else {
                    // Pin deactivated, turn the LED green
                    strip.setLEDColor(ledNumber, 0, 255, 0);
                }
            }
        }
        _previousStates[i] = currentState;
    }
}
