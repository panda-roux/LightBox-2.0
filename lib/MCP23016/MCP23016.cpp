// MCP23016.h
#include "MCP23016.h"

MCP23016::MCP23016(uint8_t address)
 : _address(address)
{
}

bool MCP23016::begin() {
 Wire.begin();
 Wire.beginTransmission(_address);
 if (Wire.endTransmission() == 0) {
   // Set all pins to input
   writeRegister(0x06, 0xFF); // GP0
   writeRegister(0x07, 0xFF); // GP1
   return true;
 }
 return false;
}

bool MCP23016::isConnected() {
 Wire.beginTransmission(_address);
 return Wire.endTransmission() == 0;
}

uint16_t MCP23016::readGPIO() {
 uint16_t gpio;
 gpio = readRegister(0x00); // Read GP0
 gpio |= readRegister(0x01) << 8; // Read GP1
 return gpio;
}

uint8_t MCP23016::getAddress() {
 return _address;
}

void MCP23016::writeRegister(uint8_t reg, uint8_t value) {
 Wire.beginTransmission(_address);
 Wire.write(reg);
 Wire.write(value);
 Wire.endTransmission();
}

uint8_t MCP23016::readRegister(uint8_t reg) {
 Wire.beginTransmission(_address);
 Wire.write(reg);
 Wire.endTransmission();
 Wire.requestFrom(_address, (uint8_t)1);
 return Wire.read();
}
