#ifndef LED_SOUND
#define LED_SOUND
#ifdef __AVR__


#include <avr/power.h>
#endif
#include <Arduino.h>
#define R_LED 262
#define Y_LED 294
#define B_LED 330
#define G_LED 349

void playLED(int LED, int time) //index för lampa, tid för lampa att lysa (kanske delaytime?)
{

// change this to whichever pin you want to use
int buzzerN = 11;

int melodyN[] = {
R_LED, Y_LED, B_LED,  G_LED, 
};

 tone(buzzerN, melodyN[LED-1], time);

// Behöver vi delay här?
delay(time);




}


#endif