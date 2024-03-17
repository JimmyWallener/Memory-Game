// Button class for managing multiple buttons with debouncing
// Button.h
#include "RGBLed.h"

#pragma once

#include <Arduino.h>

class Button {
    const uint8_t buttonPins[5] {8, 4, 3, 2, 7};; // Pins for buttons
    const size_t numButtons {5}; // Number of buttons being managed
    uint8_t lastButtonState[5]; // Last state of each button
    unsigned long lastDebounceTime[5]; // Last time the button state changed
    const unsigned long debounceDelay {5}; // Debounce delay in milliseconds
    const uint8_t buttonOffset {5}; // Offset to indicate button release
   
    uint8_t buttonOrder[100]; 
    
 public:
    // Constructor for multiple buttons
      Button() {
         for (size_t i = 0; i < this->numButtons; i++) {
               this->lastButtonState[i] = HIGH;
               this->lastDebounceTime[i] = 0;
         }
      }
    uint8_t getState(); // Read the state of the buttons
    void initialize() const; // Initialize the button pins
    uint8_t map(); // Map the button state to a number
    void setButtonOrder(RGBLed rgbled); // add buttonpresses to array which will be compared to sequence array.
    uint8_t* getButtonOrder(); 
};
