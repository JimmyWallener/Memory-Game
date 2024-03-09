#include "../include/Game.h"
#include <Arduino.h>

// Constructor

Game::Game(const byte ledPins[], const byte buttonPins[], const byte piezoPin, const byte rgbPins[], const int potentiometerPin) {

    size_t ledPinsSize = (size_t) sizeof(this->_ledPins) / sizeof(this->_ledPins[0]);
    size_t buttonPinsSize = sizeof(this->_buttonPins) / sizeof(this->_buttonPins[0]);
    size_t rgbPinsSize = sizeof(this->_rgbPins) / sizeof(this->_rgbPins[0]);
    

    for (size_t i = 0; i < ledPinsSize; i++){
        this->_ledPins[i] = ledPins[i];
    }

    for (size_t i = 0; i < buttonPinsSize; i++) {
        this->_buttonPins[i] = buttonPins[i];
    }

    this->_piezoPin = piezoPin;

    for (size_t i = 0; i < rgbPinsSize; i++) {
        this->_rgbPins[i] = rgbPins[i];
    }

    this->_potentiometerPin = potentiometerPin;
}

    
  


// Setters and getters

void Game::setSequenceLength(byte sequenceLength) {
    this->_sequenceLength = sequenceLength;
}

void Game::setSequence(size_t startIndex) {
    for (size_t i = startIndex; i < this->_sequenceLength; i++) {
        this->_sequence[i] = random(0, 4);
    }
}

void Game::setUserSequenceLength(byte userSequenceLength) {
    this->_userSequenceLength = userSequenceLength;
}

void Game::setUserSequence(byte userSequence[]) {
    for (size_t i = 0; i < this->_userSequenceLength; i++) {
        this->_userSequence[i] = userSequence[i];
    }
}

void Game::setPlayerScore(unsigned int score) {
    this->player.setScore(score);
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
    for (size_t i = 0; i < sizeof(this->_ledPins); i++) {
        pinMode(this->_ledPins[i], OUTPUT);
    }

    // Set up button pins
    for (size_t i = 0; i < sizeof(this->_buttonPins); i++) {
        pinMode(this->_buttonPins[i], INPUT_PULLUP);
    }

    // Set up piezo pin
    pinMode(this->_piezoPin, OUTPUT);

    // Set up RGB pins
    for (size_t i = 0; i < sizeof(this->_rgbPins); i++) {
        pinMode(this->_rgbPins[i], OUTPUT);
    }

    // Set up potentiometer pin
    pinMode(this->_potentiometerPin, INPUT);

    // Set up random seed
    randomSeed(analogRead(A0));

    
}

// Set the game mode

  // Defines RGB LED Color and difficultlevel based on potentiometer value
  void Game::setGameMode() {
    int potValue = analogRead(this->_potentiometerPin); // read the value from potentiometer
    byte mappedValue = map(potValue,  0,  1023,  0,  2); // maps the potentiometer value to a 0-3 range
	
    Serial.println(mappedValue);

    switch (mappedValue) {
      case  0: // Default Game Mode
        digitalWrite(this->_ledPins[0], HIGH);
      	digitalWrite(this->_ledPins[1], LOW);
      	digitalWrite(this->_ledPins[2], LOW);

        player.setLevel(mappedValue); // Increase level based on mapped potentiometer input
        break;
      case  1: // Game Mode 1 - (different light pattern or/and speed, not set yet)
        digitalWrite(this->_ledPins[0], HIGH);
      	digitalWrite(this->_ledPins[1], HIGH);
      	digitalWrite(this->_ledPins[2], LOW);

        player.setLevel(mappedValue);
        break;
      case  2: // Game Mode 2 - (different light pattern or/and speed, not set yet)
        digitalWrite(this->_ledPins[0], HIGH);
      	digitalWrite(this->_ledPins[1], HIGH);
      	digitalWrite(this->_ledPins[2], HIGH);

        player.setLevel(mappedValue);
        break;
    }
  }

  // Plays the set sequence of LED
 void Game::playSequence() {

    int redPin = this->_rgbPins[0];
    int greenPin = this->_rgbPins[1];
    int bluePin = this->_rgbPins[2];

    int lightDelay = 1000; // temporary variable for testing purpose only

    for (size_t i =  0; i < this->_sequenceLength; i++) {
	
      analogWrite(greenPin, 0);
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      delay(1000);
      
    switch (this->getSequence()[i]) {
      case  0: // Green Light
        analogWrite(greenPin,  255);
        delay(lightDelay);
        break;
      case  1: // Yellow Light
        analogWrite(redPin,  255);
        analogWrite(greenPin,  255);
        delay(lightDelay);
        break;
      case  2: // Blue Light
        analogWrite(bluePin,  255);
        delay(lightDelay);
        break;
      case  3: // Red Light
        analogWrite(redPin,  255);
        delay(lightDelay);
        break;
    }
      
    }
     analogWrite(greenPin, 0);
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      delay(500);
      this->setIsGameOver(false); // for testing purpose only
  }


void Game::play() {
    setGameMode();
    setSequenceLength(4);
    setSequence(0);
    playSequence();   

}