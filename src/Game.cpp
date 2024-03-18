#include "../include/Game.h"
#include <Arduino.h>

bool Game::checkAnwser(RGBLed rgbled, Button button, size_t counter) // for loop som kollar seqeunce[i] med buttonpress[i]                                                              
{                                                                 //om de e samma, är alla samma return true else false
    button.setButtonOrder(counter);
    uint8_t* buttonOrder = button.getButtonOrder(counter);
    uint8_t* rgbsequence = rgbled.getSequence();

    for(size_t i = 0; i < counter; i++){
        if(rgbsequence[i] != buttonOrder[i]){
            return false;
            break;
        }
    }
    return true;
}


void Game::playEasy(RGBLed rgbled, Button button) // just 1 more colour per iteration
{
    size_t counter = 4; // how many lamps you start out with
    rgbled.setSequence(0, counter);
    bool isPlaying = true;
 
    while(isPlaying){
        rgbled.playSequence(500);
        if(checkAnwser(rgbled, button, counter)){
            rgbled.addToSequence(counter); // adds to sequence using already existing sequence
            counter++;
            delay(2000);
        }else{
            isPlaying = false;
        }
    }
}

void Game::playMedium(RGBLed rgbled, Button button) // New colours and less time lit up
{
    size_t counter = 4;
    bool isPlaying = true;
    int delayTimer = 500;
 
    while(isPlaying){
        rgbled.setSequence(0, counter);
        rgbled.playSequence(delayTimer);
        if(checkAnwser(rgbled, button, counter)){
            if(delayTimer != 50){
                delayTimer -= 50;
            }
            delay(2000);
        }else{
            isPlaying = false;
        }
    }
}

void Game::playHard(RGBLed rgbled, Button button) // New coulors, less time and 1 more colour per iteration
{
    size_t counter = 4;
    bool isPlaying = true;
    int delayTimer = 500;
 
    while(isPlaying){
        rgbled.setSequence(0, counter);
        rgbled.playSequence(delayTimer);
        if(checkAnwser(rgbled, button, counter)){
            rgbled.addToSequence(counter);
            counter++;
            if(delayTimer != 50){
                delayTimer -= 50;
            }
            delay(2000);
        }else{
            isPlaying = false;
        }
    }
}