#include "../include/Game.h"
#include <Arduino.h>

/*
1. Fixa objekt game & metoder + members
2. switch statement som kör de olika metoderna beroende på vilken mode som funktion 'setGameMode' returnar
3. Fixa så att när man trycker på knappen med rätt game mode körs det igång (spela en ljus sekvens?)
4. implmentera olika logiker för de tre olika game modes
5. Fixa en loop som låter en spela igen

Sammanfattning: rgbsequence som finns i checkAnswer fungerar och returnerar korrekt en array med de lampor som lyst
                addToSequnece fungerar också. Problemet är button klassen och det finns två huvudsakliga problem.

                    1. button.map() returner 1,2,3,4,5 varje gång den kallas vilket gör det svårt för SELECT_BUTTON att fungera.

                    2. återigen button.map() som ska returnera 0 ifall ingen knapp är nedtryckt, men den returnerar ibland 1 
                       ibland 0? vilket gör att det blir väldigt svårt att loopa oändligt till man får en array med de 
                       knapptryck som player har tryckt in. Jag har testat mycket för att få det att funka men det går inte, 
                       förmpdligen behöver button klassen göras om eller ändras.

                Det som kvarstår efter det är endast att jämföra de två olika arraysen för att se ifall de är lika, vilket
                jag har skrivit ut en del för men inte kunnat testa pga problem 2. 
*/

bool Game::checkAnwser(RGBLed rgbled, Button button, int counter) // for loop som kollar seqeunce[i] med buttonpress[i]                                                              
{                                                                 //om de e samma, är alla samma return true else false

    // uint8_t* rgbsequence = rgbled.getSequence();

    button.setButtonOrder(rgbled);
    uint8_t* buttonOrder = button.getButtonOrder();

    for(size_t i = 0; i < counter; i++){
        // Serial.println(rgbsequence[i]);
        Serial.println(buttonOrder[i]);
        //Serial.println(buttonOrder[i]);
        //delay(1000);
        /*
        if(rgbsequence[i] != buttonOrder[i]){
            return false;
            break;
        }*/
    }
    return false;
}

void Game::playEasy(RGBLed rgbled, Button button) // bara fler färger
{
    int counter = 8;
    rgbled.setSequence(0, counter);
 
    while(isPlaying == true){
        rgbled.playSequence();
        if(checkAnwser(rgbled, button, counter) == true){
            rgbled.addToSequence(counter);
            counter++;
        }else{
            isPlaying = false;
        }
    }
}

void Game::playMedium(RGBLed rgbled, Button button) // mindre delay
{
    int counter = 2; 
    // lägga in en decreaseDelay funktion i RGBLed, sen köra chechAnswer och en liknande struktur som i playEasy
    rgbled.setSequence(0, counter);
    rgbled.playSequence();
    delay(500);
}

void Game::playHard(RGBLed rgbled, Button button) // bägge två
{
    
}