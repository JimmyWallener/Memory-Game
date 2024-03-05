#include <Arduino.h>
#include "Game.cpp"


// Define the arrays and variables for the constructor
byte ledPins[4] = {12, 11, 10, 7};
byte buttonPins[4] = {8, 4, 3, 2};
byte piezoPin = 13;
byte rgbPins[3] = {5, 6, 9};
int potentiometerPin = A1;

// Initialize Game class with constructor arguments
Game game(ledPins, buttonPins, piezoPin, rgbPins, potentiometerPin);

void setup() {
  Serial.begin(9600);
  game.setup();
  
}

void loop() {
  
}

