#include "../include/Game.h"
#include <Arduino.h>




void::Game::setup() {
   this->time = millis();
    this->isGameOver = false;
    this->isGameWon = false;
    this->button.initialize();
    this->rgbLed.setSequence(0, 4);
    
}

void::Game::play() {
 this->gameMode.setGameMode();
 Serial.println(this->button.map());
    this->rgbLed.playSequence();
  
}





