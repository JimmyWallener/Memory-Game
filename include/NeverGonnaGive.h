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
#define REST      0

void playNever()
{
// Tempo
int tempo = 114;

// Vilken pin
int buzzer = 11;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

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

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(int); //arrayens längd

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

   for (int i=0; i<notes;i+=2) //Ittererar genom arrayen, varannan för att sära på ton och längd på ton
   {
    divider = melody[i + 1]; // längd på ton

    if (divider > 0) {//räknar på längden på tonen.
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

// we only play the note for 95% of the duration, leaving 5% as a pause
    tone(buzzer, melody[i], noteDuration*0.95); //spelar tonen

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
              
  
}

#endif