//En funktion för att spela upp ljud för lamporna. 
//funktionen tar lamp-nummer samt tid som ljudet ska låta. 
//Lamporna är numrerade i samma ordning som i ButtonIndex i button.cpp. 


#ifndef LED_SOUND
#define LED_SOUND

#ifdef __AVR__
#include <avr/power.h>
#endif
#include <Arduino.h>
#define R_LED 262 //(C)
#define Y_LED 294 //(D)
#define B_LED 330 //(E)
#define G_LED 349 //(F)

void playLED(int LED, int time) //index för lampa, tid för lampa att lysa (kanske delaytime?)
{

//Pin för summer
int buzzer = 11;

int LEDSound[] = {
R_LED, Y_LED, B_LED,  G_LED, 
};

 tone(buzzer, LEDSound[LED-1], time);

// Behöver vi delay här?
delay(time);

}


#endif