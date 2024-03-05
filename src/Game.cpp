#include "../include/Game.h"
#include <Arduino.h>

Game::Game(byte (&ledPins)[4], byte (&buttonPins)[4], byte &piezoPin, byte (&rgbPins)[3], int &potentiometerPin) {
    for (int i = 0; i < 4; i++) {
        this->_ledPins[i] = ledPins[i];
        this->_buttonPins[i] = buttonPins[i];
    }
    this->_piezoPin = piezoPin;
    for (int i = 0; i < 3; i++) {
        this->_rgbPins[i] = rgbPins[i];
    }
    this->_potentiometerPin = potentiometerPin;
    this->_sequenceLength = 4;
}

// Setters and getters

void Game::setSequenceLength(byte sequenceLength) {
    this->_sequenceLength = sequenceLength;
}

void Game::setSequence(size_t startIndex) {
    for (int i = startIndex; i < this->_sequenceLength; i++) {
        this->_sequence[i] = random(0, 4);
    }
}

void Game::setUserSequenceLength(byte userSequenceLength) {
    this->_userSequenceLength = userSequenceLength;
}

void Game::setUserSequence(byte userSequence[]) {
    for (int i = 0; i < this->_userSequenceLength; i++) {
        this->_userSequence[i] = userSequence[i];
    }
}


void Game::setTime(unsigned long time) {
    this->_time = time;
}

void Game::setIsGameOver(bool isGameOver) {
    this->_isGameOver = isGameOver;
}

void Game::setIsGameWon(bool isGameWon) {
    this->_isGameWon = isGameWon;
}

byte Game::getSequenceLength() {
    return this->_sequenceLength;
}

byte* Game::getSequence() {
    return this->_sequence;
}

byte Game::getUserSequenceLength() {
    return this->_userSequenceLength;
}

byte* Game::getUserSequence() {
    return this->_userSequence;
}

unsigned long Game::getTime() {
    return this->_time;
}

bool Game::getIsGameOver() {
    return this->_isGameOver;
}

bool Game::getIsGameWon() {
    return this->_isGameWon;
}


// Game Methods

void Game::setup() {
    // Set up LED pins
    for (int i = 0; i < 4; i++) {
        pinMode(this->_ledPins[i], OUTPUT);
    }

    // Set up button pins
    for (int i = 0; i < 4; i++) {
        pinMode(this->_buttonPins[i], INPUT_PULLUP);
    }

    // Set up piezo pin
    pinMode(this->_piezoPin, OUTPUT);

    // Set up RGB pins
    for (int i = 0; i < 3; i++) {
        pinMode(this->_rgbPins[i], OUTPUT);
    }

    // Set up potentiometer pin
    pinMode(this->_potentiometerPin, INPUT);

    // Set up random seed
    randomSeed(analogRead(A0));

    
}

void Game::play() {
    setSequenceLength(0);   

}