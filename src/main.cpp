#include <Arduino.h>
#include "Game.cpp"


// Define the arrays and variables for the constructor
<<<<<<< Updated upstream
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

=======
// inisiera pins i setu
// Game game ska vara global variabel
// constructor eller klasser som inte är i metoder/funktioner

const uint8_t piezoPin = 13;
Game game;
Button button;
RGBLed rgbled;
GameMode gamemode;

void setup() {
  Serial.begin(9600);
  button.initialize();
  button.getState();
  delay(600);
}

void loop() {

  int gameModeSelected;
  bool selectGameMode = true;
  
  while(selectGameMode){
    gameModeSelected = gamemode.setGameMode();

    if(button.map() == 1){
      selectGameMode = false; 
    }
  }
  
  switch (gameModeSelected)
  {
    case 1:
      game.playEasy(rgbled, button);
      break;

    case 2:
      game.playMedium(rgbled, button);
      break;

    case 3:
      game.playHard(rgbled, button);
      break;

    default:
        break;
  }
}
>>>>>>> Stashed changes
