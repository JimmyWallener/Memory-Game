#include "..\include\Player.h"
#include <HardwareSerial.h>

Player::Player(unsigned int score, unsigned int level, unsigned int mode) {
    this->score = score;
    this->level = level;
    this->mode = mode;
}

void Player::setScore(unsigned int score) {
    this->score = score;
}

void Player::setLevel(unsigned int level) {
    this->level = level;
}

void Player::setMode(unsigned int mode) {
    this->mode = mode;
}

unsigned int Player::getScore() {
    return this->score;
}

unsigned int Player::getLevel() {
    return this->level;
}

unsigned int Player::getMode() {
    return this->mode;
}

void Player::printPlayer() {
    Serial.print("Score: ");
    Serial.println(this->score);
    Serial.print("Level: ");
    Serial.println(this->level);
    Serial.print("Mode: ");
    Serial.println(this->mode);
}