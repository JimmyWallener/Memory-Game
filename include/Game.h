#pragma once

#include <Arduino.h>
#include "Player.h"
#include "Button.h"
#include "GameMode.h"
#include "RGBLed.h"


class Game {
    private:
        unsigned long time{}; // time for timing game
        bool isPlaying = true;

    public:
        void playEasy(RGBLed, Button);
        void playMedium(RGBLed, Button);
        void playHard(RGBLed, Button);
        bool checkAnwser(RGBLed, Button, size_t);
};

