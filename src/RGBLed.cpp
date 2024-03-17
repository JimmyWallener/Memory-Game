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
        uint8_t tempSequence = random(0, 4);
        if(tempSequence == this->sequence[i - 1]){
            i--;
        }else{
            this->sequence[i] = tempSequence;
        }
    }
}

void RGBLed::addToSequence(size_t counter)
{
    randomSeed(analogRead(A0));
    this->sequence[counter] = random(0,4);
    this->sequenceLength++;

    for (size_t i = counter; i < counter + 1; i++) {
        uint8_t tempSequence = random(0, 4);
        if(tempSequence == this->sequence[i - 1]){
            i--;
        }else{
            this->sequence[i] = tempSequence;
        }
    }
}

void RGBLed::playSequence() {
  

    int lightDelay = 400; // temporary variable for testing purpose only

    for (size_t i = 0; i < this->sequenceLength; i++) {

        analogWrite(GREEN, 0);
        analogWrite(RED, 0);
        analogWrite(BLUE, 0);
        delay(1000);

        switch (this->sequence[i]) {
            case 0: // Red Light
                analogWrite(RED, 255);
                delay(lightDelay);
                break;
            case 1: // Yellow Light
                analogWrite(RED, 255);
                analogWrite(GREEN, 255);
                delay(lightDelay);
                break;
            case 2: // Blue Light
                analogWrite(BLUE, 255);
                delay(lightDelay);
                break;
            case 3: // Green
                analogWrite(GREEN, 255);
                delay(lightDelay);
                break;
        }

    }
    // for testing purpose only
    analogWrite(GREEN, 0);
    analogWrite(RED, 0);
    analogWrite(BLUE, 0);
}

uint8_t* RGBLed::getSequence()
{
    return sequence;
}