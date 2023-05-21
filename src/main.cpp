#include "MCP23016.h"
#include "MCP23016Manager.h" 
#include "LEDController.h"

// Define the I2C addresses of the MCP23016 chips
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x22
#define MCP23016_ADDRESS_4 0x23

// Create MCP23016 objects
MCP23016 mcp1(MCP23016_ADDRESS_1);
MCP23016 mcp2(MCP23016_ADDRESS_2);
MCP23016 mcp3(MCP23016_ADDRESS_3);
MCP23016 mcp4(MCP23016_ADDRESS_4);

// Create an array of MCP23016 objects
MCP23016* mcpArray[] = {&mcp1, &mcp2, &mcp3, &mcp4};

// Create MCP23016Manager object
MCP23016Manager mcpManager(mcpArray, sizeof(mcpArray) / sizeof(mcpArray[0]));

// Create your LED strip object here
LEDStrip ledStrip(6, 100);

// Create LEDController object
LEDController ledController(ledStrip);

void setup() {
  Serial.begin(9600);
  // Setup your LED strip here
}

void loop() {
  int changedPins[MAX_CHANGES];
  uint8_t numChanges = mcpManager.getChangedPins(changedPins);
  ledController.updateLEDs(changedPins, numChanges);
  ledController.printActivations(changedPins, numChanges);
  delay(100);

  Serial.println(numChanges);
  delay(1000);
}
