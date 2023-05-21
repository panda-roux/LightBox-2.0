#include "MCP23016.h"
#include "MCP23016Manager.h" 
#include "LEDController.h"

// Define the I2C addresses of the MCP23016 chips
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x22
#define MCP23016_ADDRESS_4 0x23

// Create MCP23016Manager object
MCP23016Manager mcpManager;

void setup() {
    Serial.begin(9600);
    
    // Setup the MCP23016 expanders
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_1)) {
        Serial.println("Failed to setup expander at address 1");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_2)) {
        Serial.println("Failed to setup expander at address 2");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_3)) {
        Serial.println("Failed to setup expander at address 3");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_4)) {
        Serial.println("Failed to setup expander at address 4");
    }
}

void loop() {
    // Read all inputs
    mcpManager.readAllInputs();

    // Print the state of all inputs as a single string of ones and zeros
    String inputStates = "";
    for (int i = 0; i < 4 * 16; i++) {
        inputStates += mcpManager.getInputState(i) ? "1" : "0";
    }
    Serial.println("Input: " + inputStates);

    delay(1000);
}