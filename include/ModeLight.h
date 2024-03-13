#pragma once

#include <Arduino.h>

class ModeLight {
    private:
        byte *_pins;
        int _numPins;
        byte _pin;

    public:
        ModeLight();
        ModeLight(byte);
        ModeLight(const byte[],const int);
        void turnOn(size_t index = -1);
        void turnOff(size_t index = -1);
};