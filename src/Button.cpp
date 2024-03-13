// Button.cpp

#include "../include/Button.h"
#include <Arduino.h>

Button::Button(const byte buttonPins[], const size_t numButtons) {
    this->numButtons = numButtons;
    for (size_t i = 0; i < numButtons; i++) {
        this->buttonPins[i] = buttonPins[i];
        this->lastButtonState[i] = LOW;
        this->lastDebounceTime[i] = 0;
    }
}

void Button::setup() {
    for (size_t i = 0; i < this->numButtons; i++) {
        pinMode(this->buttonPins[i], INPUT_PULLUP);
    }
}

byte Button::readButtons() {
  for (size_t i = 0; i < this->numButtons; i++) {
    int reading = digitalRead(this->buttonPins[i]);

    // Update state and debounce time on state change (press or release)
    if (reading != this->lastButtonState[i]) {
      this->lastButtonState[i] = reading;
      this->lastDebounceTime[i] = millis();
    }

    if ((millis() - this->lastDebounceTime[i]) < debounceDelay) {
      // Update state only if debounce time has passed
      return i + 1; // Return index for button press
    }
  }
  return 0; // No button press or release detected
}

byte Button::mapButtons() {
  byte button = this->readButtons();
  switch(button) {
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
        break;
    case 4:
      return 4;
      break;
    case 5:
      return 5;
      break;
    default:
        return 0;
        break;
  }
    
}
