#include <Arduino.h>
#include "../include/Game.h"
#include "../include/GameMode.h"
#include "../include/Button.h"
#include "../include/Player.h"


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

    if(button.map() == 5){
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
  gamemode.gameOver(); // uses
  rgbled.reset();
  button.resetSelectButton(); // resets button so that you can play again
}