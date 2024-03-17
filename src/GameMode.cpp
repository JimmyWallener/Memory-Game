#include "../include/GameMode.h"

enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};


void GameMode::turnOn(size_t index) {
    digitalWrite(this->ledPins[index], HIGH);
}

void GameMode::turnOff(size_t index) {
    digitalWrite(this->ledPins[index], LOW);
}

unsigned int GameMode::getPotentiometerValue() {
    return analogRead(this->potentiometerPin);
    
}

uint8_t GameMode::setGameMode() {
    int potValue = getPotentiometerValue(); // read the value from potentiometer
    byte mappedValue = map(potValue,  0,  1023,  0,  3); // maps the potentiometer value to a 0-3 range

    switch (mappedValue) {
        case  0: // Easy Game Mode - no increase in speed but shows more LEDs
            turnOn(0);
            turnOff(1);
            turnOff(2);
            return EASY;
        case  1: // Medium Game Mode - less LEDs but faster
            turnOn(0);
            turnOn(1);
            turnOff(2);
            return MEDIUM;
        case  2: // Hard Game Mode - More leds and faster
            turnOn(0);
            turnOn(1);
            turnOn(2);
            return HARD;
        default:
            return 0;
    }
}

void GameMode::gameOver()
{
    for(int i = 0; i < 3; i++){
        turnOn(0);
        turnOn(1);
        turnOn(2);
        delay(200);
        turnOff(0);
        turnOff(1);
        turnOff(2);
        delay(200);
    }
}