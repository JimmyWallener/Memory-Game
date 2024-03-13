// Button class for managing multiple buttons with debouncing
// Button.h

#pragma once

#include <Arduino.h>

class Button {
 private:
    byte buttonPins[5]; // Assuming a maximum of 4 buttons for simplicity
    size_t numButtons; // Number of buttons being managed
    int lastButtonState[5]; // Last state of each button
    unsigned long lastDebounceTime[5]; // Last time the button state changed
    static const unsigned long debounceDelay = 5; // Debounce delay in milliseconds
    const int buttonOffset = 5; // Offset to indicate button release
    byte readButtons();
 public:
    // Constructor for multiple buttons
    Button(const byte buttonPins[], const size_t numButtons);
    byte mapButtons();
    void setup();
    
};
