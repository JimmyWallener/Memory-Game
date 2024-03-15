#pragma once

#include <Arduino.h>
#include "Player.h"
#include "Button.h"
#include "GameMode.h"


class Game {
    private:
        unsigned long time{}; // time for timing game
        bool isGameOver{}; // game over flag
        bool isGameWon{}; // game won flag


    public:
        Game(){};
        void play();
};

