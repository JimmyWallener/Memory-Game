#include <Arduino.h>
#include "../include/Game.h"
#include "../include/ModeLight.h"
#include "../include/Button.h"


// Define the arrays and variables for the constructor
const byte ledPins[3] = {12, 11, 10};
const byte buttonPins[5] = {8, 4, 3, 2, 7};
const byte piezoPin = 13;

const byte rgbPins[3] = {5, 6, 9};
const int potentiometerPin = A1;

// Initialize ModeLight class with constructor arguments
ModeLight modeLight(ledPins, sizeof(ledPins) / sizeof(ledPins[0]));

// Initialize Button class with constructor arguments
Button button(buttonPins, sizeof(buttonPins) / sizeof(buttonPins[0]));


// Initialize Game class with constructor arguments
Game game(ledPins, buttonPins, piezoPin, rgbPins, potentiometerPin);

void setup() {
  Serial.begin(9600);
  button.setup();
  delay(500);
  

 // game.setup();
  
}

void loop() {

 byte buttonPressed = button.mapButtons();

 if (buttonPressed > 0) {

   Serial.println(buttonPressed);
   delay(200);
 }
  //game.playSequence(
  
  
 // game.play();
}
