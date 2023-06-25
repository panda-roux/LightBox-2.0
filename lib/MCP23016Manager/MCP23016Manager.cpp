#include "MCP23016Manager.h"

MCP23016Manager::MCP23016Manager() : expanderCount(0) {
  for (int i = 0; i < MAX_EXPANDERS * 16; i++) {
    inputStates[i] = 0;
  }
}

MCP23016Manager::~MCP23016Manager() {
  for (int i = 0; i < expanderCount; i++) {
    delete expanders[i];
  }
}

bool MCP23016Manager::setupExpander(uint8_t address) {
  if (expanderCount >= MAX_EXPANDERS) {
    return false;
  }
  MCP23016* expander = new MCP23016(address);
  if (!expander->begin()) {
    delete expander;
    return false;
  }
  expanders[expanderCount] = expander;
  expanderCount++;
  return true;
}


void MCP23016Manager::readAllInputs() {
  for (int i = 0; i < expanderCount; i++) {
    uint16_t gpio = expanders[i]->readGPIO();
    for (int j = 0; j < 16; j++) {
      inputStates[i * 16 + j] = (gpio >> j) & 1;
    }
  }
}

uint16_t MCP23016Manager::getInputState(uint8_t inputNumber) {
  if (inputNumber < MAX_EXPANDERS * 16) {
    return inputStates[inputNumber];
  }
  return 0;
}

void MCP23016Manager::checkConnectivity() {
  for (int i = 0; i < expanderCount; i++) {
    if (expanders[i]->isConnected()) {
      Serial.print("Expander at address ");
      Serial.print(expanders[i]->getAddress(), HEX);
      Serial.println(" is connected.");
    } else {
      Serial.print("Expander at address ");
      Serial.print(expanders[i]->getAddress(), HEX);
      Serial.println(" is not connected.");
    }
  }

}

uint16_t MCP23016Manager::readExpander(int expanderIndex) {
  if (expanders[expanderIndex]->isConnected()) {
    return expanders[expanderIndex]->readGPIO();
  }
  return 0; // Return 0 if the expander is not connected
}
