#include "../include/ModeLight.h"

// Constructor
ModeLight::ModeLight() {
    this->_pin = -1;
}

ModeLight::ModeLight(byte pin){
    this->_pin = pin;
    pinMode(this->_pin, OUTPUT);
}
ModeLight::ModeLight(const byte pins[], const int numPins){
    this->_pins = new byte[numPins];
    this->_numPins = numPins;
    for (size_t i = 0; i < this->_numPins; i++) {
        pinMode(this->_pins[i], OUTPUT);
    }
}

// Turn on LED

void ModeLight::turnOn(size_t index) {
    if (index != -1) {
        digitalWrite(this->_pin, HIGH);
    } else {
        digitalWrite(this->_pins[index], HIGH);
    }
}

// Turn off LED

void ModeLight::turnOff(size_t index) {
    if (index != -1) {
        digitalWrite(this->_pin, LOW);
    } else {
        digitalWrite(this->_pins[index], LOW);
    }
}

