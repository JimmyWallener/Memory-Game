#pragma once

#include <Arduino.h>


class GameMode {
    private:
        const uint8_t ledPins[3]{12, 11, 10};
        const size_t numLeds {3};
        const unsigned int potentiometerPin{A1};
        void turnOn(size_t);
        void turnOff(size_t);
        unsigned int getPotentiometerValue();
    public:
        GameMode() {
            for (size_t i = 0; i < numLeds; i++) {
                pinMode(this->ledPins[i], OUTPUT);
            }
            pinMode(this->potentiometerPin, INPUT);
        }
        uint8_t setGameMode();
};