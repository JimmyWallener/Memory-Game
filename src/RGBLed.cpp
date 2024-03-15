#include "../include/RGBLed.h"

void RGBLed::turnOn(size_t index) {
    digitalWrite(this->rgbPins[index], HIGH);
}

void RGBLed::turnOff(size_t index) {
    digitalWrite(this->rgbPins[index], LOW);
}

void RGBLed::setSequence(size_t index,size_t length) {
    randomSeed(analogRead(A0));
    this->sequenceLength = length;
    for (size_t i = index; i < length; i++) {
        this->sequence[i] = random(0, 4);
    }
}

void RGBLed::playSequence() {
  

    int lightDelay = 1000; // temporary variable for testing purpose only
    for (size_t i = 0; i < this->sequenceLength; i++) {

        analogWrite(GREEN, 0);
        analogWrite(RED, 0);
        analogWrite(BLUE, 0);
        delay(1000);

        switch (this->sequence[i]) {
            case 0: // Green Light
                analogWrite(GREEN, 255);
                delay(lightDelay);
                break;
            case 1: // Yellow Light
                analogWrite(RED, 255);
                analogWrite(GREEN, 226);
                analogWrite(BLUE, 0);
                delay(lightDelay);
                break;
            case 2: // Blue Light
                analogWrite(BLUE, 255);
                delay(lightDelay);
                break;
            case 3: // Red Light
                analogWrite(RED, 255);
                delay(lightDelay);
                break;
        }

    }
    analogWrite(GREEN, 0);
    analogWrite(RED, 0);
    analogWrite(BLUE, 0);
    delay(500);
    // for testing purpose only
}

