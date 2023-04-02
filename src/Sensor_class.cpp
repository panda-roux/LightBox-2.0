#include <Arduino.h> // Include the Arduino.h header file
#include <Wire.h>

class MCP23016Controller {
  private:
    const int numICs;
    int numInputs;
    uint16_t* inputValues;
  
  public:
    MCP23016Controller(int numICs) : numICs(numICs) {
      numInputs = numICs * 16;
      inputValues = new uint16_t[numICs];
    }
    
    ~MCP23016Controller() {
      delete[] inputValues;
    }
    
    void begin() {
      Wire.begin();
      
      for (int i = 0; i < numICs; i++) {
        // Set all pins as inputs
        writeRegister(i, 0x00, 0xFF);
        
        // Enable pull-up resistors on all pins
        writeRegister(i, 0x0C, 0xFF);
        
        // Configure IOCON register for serial mode
        writeRegister(i, 0x05, 0x80);
      }
    }
    
    uint32_t readInputs() {
      for (int i = 0; i < numICs; i++) {
        // Read all input values from the IC
        inputValues[i] = readRegister(i, 0x12);
      }
      
      // Combine all input values into a single binary value
      uint32_t result = 0;
      for (int i = 0; i < numInputs; i++) {
        if (getBit(inputValues[i / 16], i % 16) == 0) {
          result |= (1 << i);
        }
      }
      
      return result;
    }
    
  private:
    void writeRegister(int ic, byte reg, byte value) {
      Wire.beginTransmission(0x20 + ic);
      Wire.write(reg);
      Wire.write(value);
      Wire.endTransmission();
    }
    
    uint16_t readRegister(int ic, byte reg) {
      Wire.beginTransmission(0x20 + ic);
      Wire.write(reg);
      Wire.endTransmission();
      
      Wire.requestFrom(0x20 + ic, 2);
      uint16_t result = Wire.read();
      result |= (Wire.read() << 8);
      
      return result;
    }
    
    int getBit(uint16_t value, int bit) {
      return (value >> bit) & 0x01;
    }
};
