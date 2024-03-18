// Liv Danielsdottir

#ifndef THE_LICK
#define THE_LICK
#ifdef __AVR__


#include <avr/power.h>
#endif
#include <Arduino.h>

#define NOTE_C1  33
#define NOTE_D1  37 
#define NOTE_E1  41 
#define NOTE_F1  44
#define NOTE_G1  49


void playTheLick(int l) //level för att höja pitchen, kanske kan lägga in tempo här som ökar för levels? pitchen kan endast höjas sex ggr
{
// Tempo
int tempo = 180;

// Vilken pin
int buzzer = 11;

// Not följd av dess värde(längd) varvas i arrayen. 
// 4 är kvarts notlängd, 8, är åttonndel, 16 är sextondel osv, 

int melody[] = {

    NOTE_D1,8, NOTE_E1,8, NOTE_F1,8, NOTE_G1,8, NOTE_E1,4, NOTE_C1,8, NOTE_D1,2,
};

int wholenote = (60000 * 4) / tempo; //längden på tonen
int notes = sizeof(melody) / sizeof(int); //arrayens längd

   for (int j = 0; j < l; j++) //dubblar inten (tonen) för varje level. 
   {
       for (int i = 0; i <notes; i+=2)//eftersom att vartannat värde är längd på tonen
       {
               melody[i] = (melody[i] * 2);    
       }
   }
   for (int i=0; i<notes;i+=2) //spelar upp 
   {
                 //spelar tonen
                tone(buzzer, melody[i], (wholenote)/melody[i+1] );

                 // Väntar på att ta nästa ton
                delay((wholenote)/melody[i+1]);

                 // stop the waveform generation before the next note.
                  //Märkte ingen skillnad när jag tog bort denna.   
                noTone(buzzer);
   }


}

#endif