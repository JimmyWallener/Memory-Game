// Button.cpp

#include "../include/Button.h"
#include <Arduino.h>

enum ButtonState {
  RELEASED = 0,
  PRESSED = 1
};

enum ButtonIndex {
  RED_BUTTON = 1,
  YELLOW_BUTTON = 2,
  BLUE_BUTTON = 3,
  GREEN_BUTTON = 4,
  SELECT_BUTTON = 5
};

void Button::initialize() const {
    for (size_t i = 0; i < this->numButtons; i++) {
        pinMode(this->buttonPins[i], INPUT_PULLUP);
    }
}

uint8_t Button::getState() {
  for (size_t i = 0; i < this->numButtons; i++) {
    int reading = digitalRead(this->buttonPins[i]);

    // Update state and debounce time on state change (press or release)
    if (reading != this->lastButtonState[i]) {
      this->lastButtonState[i] = reading;
      this->lastDebounceTime[i] = millis();
    }

    if ((millis() - this->lastDebounceTime[i]) < debounceDelay) {
      // Update state only if debounce time has passed
      return PRESSED + i; // Return index for button press
    }
  }
  return RELEASED; // No button press or release detected
}

uint8_t Button::map() {
  uint8_t button = this->getState();
  switch(button) {
    case 1:
      return RED_BUTTON;
    case 2:
      return YELLOW_BUTTON;
    case 3:
      return BLUE_BUTTON;
    case 4:
      return GREEN_BUTTON;
    case 5:
      return SELECT_BUTTON;
    default:
        return 0;
  }
    
}

void Button::setButtonOrder(RGBLed rgbled)
{  
    bool loopIt = true;
    for (size_t i = 0; i < rgbled.getSequenceLength(); i++){
      while(loopIt){
        uint8_t res = map();
        if(res != 0){
          this->buttonOrder[i] = res - 1;
        }else{
          i--;
        }
      }
    }

}

uint8_t* Button::getButtonOrder(){return this->buttonOrder;}