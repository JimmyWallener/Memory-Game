#include "../include/Game.h"
#include <Arduino.h>

<<<<<<< Updated upstream
Game::Game(byte (&ledPins)[4], byte (&buttonPins)[4], byte &piezoPin, byte (&rgbPins)[3], int &potentiometerPin) {
    for (int i = 0; i < 4; i++) {
        this->_ledPins[i] = ledPins[i];
        this->_buttonPins[i] = buttonPins[i];
    }
    this->_piezoPin = piezoPin;
    for (int i = 0; i < 3; i++) {
        this->_rgbPins[i] = rgbPins[i];
    }
    this->_potentiometerPin = potentiometerPin;
    this->_sequenceLength = 4;
}

// Setters and getters

void Game::setSequenceLength(byte sequenceLength) {
    this->_sequenceLength = sequenceLength;
}

void Game::setSequence(size_t startIndex) {
    for (int i = startIndex; i < this->_sequenceLength; i++) {
        this->_sequence[i] = random(0, 4);
    }
}

void Game::setUserSequenceLength(byte userSequenceLength) {
    this->_userSequenceLength = userSequenceLength;
}

void Game::setUserSequence(byte userSequence[]) {
    for (int i = 0; i < this->_userSequenceLength; i++) {
        this->_userSequence[i] = userSequence[i];
    }
}
=======
/*
1. Fixa objekt game & metoder + members
2. switch statement som kör de olika metoderna beroende på vilken mode som funktion 'setGameMode' returnar
3. Fixa så att när man trycker på knappen med rätt game mode körs det igång (spela en ljus sekvens?)
4. implmentera olika logiker för de tre olika game modes
5. Fixa en loop som låter en spela igen
>>>>>>> Stashed changes

Sammanfattning: rgbsequence som finns i checkAnswer fungerar och returnerar korrekt en array med de lampor som lyst
                addToSequnece fungerar också. Problemet är button klassen och det finns två huvudsakliga problem.

<<<<<<< Updated upstream
void Game::setTime(unsigned long time) {
    this->_time = time;
}

void Game::setIsGameOver(bool isGameOver) {
    this->_isGameOver = isGameOver;
}

void Game::setIsGameWon(bool isGameWon) {
    this->_isGameWon = isGameWon;
}

byte Game::getSequenceLength() {
    return this->_sequenceLength;
}

byte* Game::getSequence() {
    return this->_sequence;
}

byte Game::getUserSequenceLength() {
    return this->_userSequenceLength;
}

byte* Game::getUserSequence() {
    return this->_userSequence;
}

unsigned long Game::getTime() {
    return this->_time;
}

bool Game::getIsGameOver() {
    return this->_isGameOver;
}

bool Game::getIsGameWon() {
    return this->_isGameWon;
}
=======
                    1. button.map() returner 1,2,3,4,5 varje gång den kallas vilket gör det svårt för SELECT_BUTTON att fungera.
>>>>>>> Stashed changes

                    2. återigen button.map() som ska returnera 0 ifall ingen knapp är nedtryckt, men den returnerar ibland 1 
                       ibland 0? vilket gör att det blir väldigt svårt att loopa oändligt till man får en array med de 
                       knapptryck som player har tryckt in. Jag har testat mycket för att få det att funka men det går inte, 
                       förmpdligen behöver button klassen göras om eller ändras.

<<<<<<< Updated upstream
// Game Methods

void Game::setup() {
    // Set up LED pins
    for (int i = 0; i < 4; i++) {
        pinMode(this->_ledPins[i], OUTPUT);
    }

    // Set up button pins
    for (int i = 0; i < 4; i++) {
        pinMode(this->_buttonPins[i], INPUT_PULLUP);
    }

    // Set up piezo pin
    pinMode(this->_piezoPin, OUTPUT);

    // Set up RGB pins
    for (int i = 0; i < 3; i++) {
        pinMode(this->_rgbPins[i], OUTPUT);
    }

    // Set up potentiometer pin
    pinMode(this->_potentiometerPin, INPUT);

    // Set up random seed
    randomSeed(analogRead(A0));

    
}

void Game::play() {
    setSequenceLength(0);   

=======
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
    
>>>>>>> Stashed changes
}