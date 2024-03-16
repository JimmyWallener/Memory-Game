#ifndef NEVER_H
#define NEVER_H
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <Arduino.h>

#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_FS5 740
#define NOTE_A5  880


void playNever()
{
// Tempo
int tempo = 114;

// Vilken pin
int buzzer = 11;

// Not följd av dess värde(längd) varvas i arrayen. 

// Notvärden och punkterade noter:
// 4 är kvarts noter, 8, är åttonndel, 16 är sextondel osv, 
// negativa tal är punkterade noter, -4 är därmed en kvarts + en åttondel
// Negativa tal har ingen annan funktion än att skilja punkerade noter från de som inte är punkterade. 

int melody[] = {


  NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5, -4,

  NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, 
  
  NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  
  NOTE_D5,4, NOTE_E5,8, 

  NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2,

};


int notes = sizeof(melody) / sizeof(int); //arrayens längd

// Räknar ut längden på en hel not i ms

int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

   for (int i=0; i<notes;i+=2) // Ittererar genom arrayen, varannan för att sära på ton och längd på ton
   {
    divider = melody[i + 1]; // längd på noten

    if (divider > 0) {// om notvärdet inte är punkterat 
      
      noteDuration = (wholenote) / divider;  

    } else if (divider < 0) { // om notvärdet är punkterat
    
      noteDuration = (wholenote) / abs(divider); 
      noteDuration *= 1.5; // ökar notvärdet med 50%
    }

    // För att skapa luft eller mellanrum mellan tonerna spelas varje not 95% av längden med en pus på 5%.
    tone(buzzer, melody[i], noteDuration*0.95); //spelar tonen

    // 
    // Väntar på att ta nästa ton
    delay(noteDuration);

    // stop the waveform generation before the next note.
    //Märkte ingen skillnad när jag tog bort denna.
    noTone(buzzer);
  }
              
  
}

#endif