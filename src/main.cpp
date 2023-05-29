#include "MCP23016.h"
#include "MCP23016Manager.h" 
#include "LEDController.h"
#include <ButtonControl.h>
#include <PotentiometerControl.h>

// Define the I2C addresses of the MCP23016 chips
#define MCP23016_ADDRESS_1 0x20
#define MCP23016_ADDRESS_2 0x21
#define MCP23016_ADDRESS_3 0x22
#define MCP23016_ADDRESS_4 0x23
#define MCP23016_ADDRESS_5 0x24
#define MCP23016_ADDRESS_6 0x25
#define MCP23016_ADDRESS_7 0x26


// Create MCP23016Manager object
MCP23016Manager mcpManager;

LEDStrip strip(6, 100);

const int BUTTON_PIN = 4;
ButtonControl button(BUTTON_PIN);

const int POT_PIN = A0;
PotentiometerControl potentiometer(POT_PIN);

void db_Potentiometer() {
    int rawValue = potentiometer.getValue();
    int mappedValue = potentiometer.getMappedValue();

    Serial.print("Raw Value: ");
    Serial.print(rawValue);
    Serial.print(" | Mapped Value: ");
    Serial.println(mappedValue);

}


void setup() {
    Serial.begin(9600);

    button.begin(); // button

    potentiometer.begin(); // Potentiometer
    
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
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_5)) {
        Serial.println("Failed to setup expander at address 5");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_6)) {
        Serial.println("Failed to setup expander at address 6");
    }
    if (!mcpManager.setupExpander(MCP23016_ADDRESS_7)) {
        Serial.println("Failed to setup expander at address 7");
    }
}




void loop() {
    if (button.isPressed()) {
        Serial.println("Button pressed!");
        // Perform desired actions when the button is pressed
    }

    // Read all inputs
    mcpManager.readAllInputs();

    mcpManager.checkConnectivity();

    // Print the state of all inputs as a single string of ones and zeros
    String inputStates = "";
    for (int i = 0; i < 4 * 16; i++) {

        inputStates += mcpManager.getInputState(i) ? "1" : "0";
    }
    Serial.println("Input: " + inputStates);
    db_Potentiometer();

    delay(1000);
}