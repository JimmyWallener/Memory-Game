// Button class for managing multiple buttons with debouncing
// Button.h

#pragma once

#include <Arduino.h>

class Button {
    const uint8_t buttonPins[5] {8, 4, 3, 2, 7};; // Pins for buttons
    const size_t numButtons {5}; // Number of buttons being managed
    uint8_t lastButtonState[5] = {HIGH, HIGH, HIGH, HIGH, LOW}; // Last state of each button
    unsigned long lastDebounceTime[5] = {0, 0, 0, 0, 0}; // Last time the button state changed
    const unsigned long debounceDelay {50}; // Debounce delay in milliseconds
    const uint8_t buttonOffset {5}; // Offset to indicate button release
   
    uint8_t buttonOrder[100]; 
    
 public:
    uint8_t getState(); // Read the state of the buttons
    void initialize() const; // Initialize the button pins
    uint8_t map(); // Map the button state to a number
    void setButtonOrder(size_t); // add buttonpresses to array which will be compared to sequence array.
    uint8_t* getButtonOrder(size_t);
    void resetSelectButton(); 
};