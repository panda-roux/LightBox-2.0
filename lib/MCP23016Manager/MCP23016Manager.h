#ifndef MCP23016MANAGER_H
#define MCP23016MANAGER_H

#include <Arduino.h>
#include <MCP23016.h>
#include <Wire.h>

#define MAX_EXPANDERS 7

class MCP23016Manager {
public:
  MCP23016Manager();
  ~MCP23016Manager();
  bool setupExpander(uint8_t address);
  void readAllInputs();
  uint16_t getInputState(uint8_t inputNumber);
  void checkConnectivity(); // Added this function

  MCP23016* expanders[MAX_EXPANDERS];
  uint8_t expanderCount;
  uint16_t inputStates[MAX_EXPANDERS * 16];
  uint16_t readExpander(int expanderIndex);

private:
  
};

#endif // MCP23016MANAGER_H
