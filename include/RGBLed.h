#pragma once

#include <Arduino.h>

enum RGBColor {
    RED = 5,
    GREEN = 6,
    BLUE = 9
};

class RGBLed {
    private:
        const uint8_t rgbPins[3] {RED, GREEN, BLUE};
        const size_t numLeds {3};
        uint8_t* sequence;
        void turnOn(size_t);
        void turnOff(size_t);
    public:
        RGBLed() {
            for (size_t i = 0; i < numLeds; i++) {
                pinMode(this->rgbPins[i], OUTPUT);
            }
        }
        void startSequence(size_t);
        void playSequence();
};