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
    mcpManager.setupExpander(MCP23016_ADDRESS_1);
    mcpManager.setupExpander(MCP23016_ADDRESS_2);
    mcpManager.setupExpander(MCP23016_ADDRESS_3);
    mcpManager.setupExpander(MCP23016_ADDRESS_4);
}

void loop() {
    // Read all inputs
    mcpManager.readAllInputs();

    // Print the state of all inputs
    for (int i = 0; i < MAX_EXPANDERS * 16; i++) {
        Serial.print(i);
        Serial.print(": ");
        Serial.print(mcpManager.getInputState(i));
        Serial.print("   ");
    }
    Serial.println(" ");

    delay(1000);
}