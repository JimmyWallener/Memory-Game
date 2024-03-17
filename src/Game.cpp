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


void Game::playEasy(RGBLed rgbled, Button button) // bara fler färger
{
    size_t counter = 4;
    rgbled.setSequence(0, counter);
 
    while(isPlaying){
        rgbled.playSequence();
        if(checkAnwser(rgbled, button, counter)){
            rgbled.addToSequence(counter);
            button.clearButtonOrder(counter);
            counter++;
            delay(2000);
        }else{
            isPlaying = false;
        }
    }
}

void Game::playMedium(RGBLed rgbled, Button button) // mindre delay
{
    //int counter = 2; 
    // lägga in en decreaseDelay funktion i RGBLed, sen köra chechAnswer och en liknande struktur som i playEasy
    //rgbled.setSequence(0, counter);
    //rgbled.playSequence();
    //delay(500);
}

void Game::playHard(RGBLed rgbled, Button button) // bägge två
{
    
}