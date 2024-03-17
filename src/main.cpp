#include <Arduino.h>
#include "../include/Game.h"
#include "../include/GameMode.h"
#include "../include/Button.h"
#include "../include/Player.h"


// Define the arrays and variables for the constructor
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