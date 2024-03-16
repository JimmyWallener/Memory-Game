#pragma once

#include <Arduino.h>
#include "Player.h"
<<<<<<< Updated upstream
=======
#include "Button.h"
#include "GameMode.h"
#include "RGBLed.h"
>>>>>>> Stashed changes


class Game {
    private:
<<<<<<< Updated upstream
        byte _ledPins[4]{}; // 4 LED pins
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

        Game(byte (&ledPins)[4], byte (&buttonPins)[4], byte &piezoPin, byte (&rgbPins)[3], int &potentiometerPin){};
        void setSequenceLength(byte);
        void setSequence(size_t);
        void setUserSequenceLength(byte);
        void setUserSequence(byte[]);
        void setTime(unsigned long);
        void setIsGameOver(bool);
        void setIsGameWon(bool);
        byte getSequenceLength();
        byte* getSequence();
        byte getUserSequenceLength();
        byte* getUserSequence();
        unsigned long getTime();
        bool getIsGameOver();
        bool getIsGameWon();
        void setup();
        void play();
=======
        unsigned long time{}; // time for timing game
        bool isPlaying = true;

    public:
        void playEasy(RGBLed, Button);
        void playMedium(RGBLed, Button);
        void playHard(RGBLed, Button);
        bool checkAnwser(RGBLed, Button, int);
>>>>>>> Stashed changes
};

