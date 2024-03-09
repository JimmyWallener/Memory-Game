#pragma once

#include <Arduino.h>
#include "Player.h"


class Game {
    private:
        byte _ledPins[3]{}; // 3 LED pins
        byte _buttonPins[4]{}; // 4 button pins
        byte _piezoPin{}; // piezo pin
        byte _rgbPins[3]{}; // 3 RGB pins
        int _potentiometerPin{}; // potentiometer pin
        byte _sequence[100]{}; // sequence of LED flashes
        byte _userSequence[100]{}; // sequence of user button presses
        byte _sequenceLength{}; // length of sequence
        byte _userSequenceLength{}; // length of user sequence
        unsigned long _time{}; // time for timing game
        bool _isGameOver{}; // game over flag
        bool _isGameWon{}; // game won flag

    public:
        Player player{0, 0, 0}; // player object

        Game(const byte[], const byte[], const byte, const byte[], const int);
        void setSequenceLength(byte);
        void setSequence(size_t);
        void setUserSequenceLength(byte);
        void setUserSequence(byte[]);
        void setTime(unsigned long);
        void setIsGameOver(bool);
        void setIsGameWon(bool);
        void setPlayerScore(unsigned int);
        void setGameMode();
        byte getSequenceLength();
        byte* getSequence();
        byte getUserSequenceLength();
        byte* getUserSequence();
        void playSequence();
        unsigned long getTime();
        bool getIsGameOver();
        bool getIsGameWon();
        void setup();
        void play();
};

