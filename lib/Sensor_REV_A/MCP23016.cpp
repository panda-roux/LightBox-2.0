#include "MCP23016.h"

#define MCP23016_GP0 0x00
#define MCP23016_GP1 0x01

MCP23016::MCP23016(uint8_t address) {
  _address = address;
}

void MCP23016::begin() {
  Wire.begin();
}

uint16_t MCP23016::readInputs() {
  Wire.beginTransmission(_address);
  Wire.write(MCP23016_GP0);
  Wire.endTransmission();
  Wire.requestFrom(_address, (uint8_t)2);

  uint8_t lowByte = Wire.read();
  uint8_t highByte = Wire.read();

  return (highByte << 8) | lowByte;
}

bool MCP23016::isConnected() {
  Wire.beginTransmission(_address);
  byte status = Wire.endTransmission();

  return status == 0;
}
