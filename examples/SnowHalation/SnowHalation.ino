/*************************************************
 * Public Constants
 *************************************************/
#include "pitches.h"
#define melodyPin 6

unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
long currentMelody = 0;

//Mario main theme melody
int melodySize = 750;
unsigned long melody[] = {
  NOTE_A4, NOTE_E5, NOTE_E6, NOTE_CS6, NOTE_B6, NOTE_GS6, NOTE_A6, NOTE_A6,
  0, 0, 0, 0, 0, NOTE_A6, NOTE_GS6, NOTE_A6,
  NOTE_GS6, NOTE_FS6, NOTE_E6, NOTE_E6,
  NOTE_GS6, NOTE_B6,
  NOTE_A6, 0, NOTE_A6, NOTE_GS6, NOTE_A6,
  NOTE_CS7, NOTE_A6, NOTE_GS6,NOTE_GS6, NOTE_E6,
  NOTE_FS6, NOTE_CS7, NOTE_CS7, NOTE_A6, NOTE_FS6, NOTE_CS6,
  NOTE_A5, NOTE_E7,
  //END 전주
  NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6,
  NOTE_B5, NOTE_CS6, NOTE_B5, NOTE_A5,
  NOTE_B5, NOTE_CS6, NOTE_CS6, NOTE_CS6,
  0, NOTE_A6,NOTE_GS6, NOTE_E6,NOTE_E6,NOTE_D6, NOTE_CS6, NOTE_CS6,
  NOTE_CS6, NOTE_D6, NOTE_A5, NOTE_A5, NOTE_D6, NOTE_CS6,
  NOTE_CS6, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_E5, NOTE_GS5, NOTE_B5,
  NOTE_D6, NOTE_D6, 0 , NOTE_E6,NOTE_E6,0,
  //2장 도돌이표
  NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6,
  NOTE_E6, NOTE_CS6, NOTE_E6, NOTE_B5, NOTE_B5, NOTE_A5,
  NOTE_B5, NOTE_E6, NOTE_FS6, NOTE_A5,
  0, NOTE_A6, NOTE_GS6, NOTE_GS6, NOTE_E6,//1줄
  NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_D6,NOTE_D6,
  NOTE_E6,NOTE_A5,NOTE_B5,NOTE_B5,NOTE_FS5,NOTE_A5,NOTE_D5,NOTE_A5,
  NOTE_A5,NOTE_CS5,//2

  NOTE_FS5,NOTE_D6,NOTE_FS6,NOTE_D6,NOTE_GS6,
  //NOTE_GS5,NOTE_E5,NOTE_E5,NOTE_GS5,
  NOTE_GS5,NOTE_E6,NOTE_GS6,NOTE_E6,NOTE_B6,
  NOTE_B6,NOTE_A6,NOTE_GS6,NOTE_A6,NOTE_GS6,NOTE_E6,NOTE_B5,NOTE_GS5,//3

  NOTE_FS6,NOTE_D6,NOTE_FS6,NOTE_A6,
  NOTE_GS6,NOTE_A6,NOTE_GS6,NOTE_GS6,
  NOTE_FS6,NOTE_D6,NOTE_FS6,NOTE_A6,
  NOTE_B6,NOTE_E6,NOTE_E6,//4

  NOTE_FS6,NOTE_D6,NOTE_FS6,NOTE_A6,NOTE_A6,
  0,NOTE_FS6,NOTE_GS6,NOTE_GS6,NOTE_A6,NOTE_B6,
  NOTE_E7,0,NOTE_E7,0,NOTE_E7,NOTE_CS7,NOTE_D7,NOTE_DS7,
  NOTE_CS7,0,NOTE_A6,
  NOTE_C8,NOTE_B7,NOTE_A7,NOTE_G7,NOTE_F7,NOTE_E7,NOTE_D7,
  NOTE_C7,NOTE_B6,NOTE_A6,NOTE_G6,NOTE_F6,NOTE_E6
  };
//Snow halation main them tempo
unsigned int tempo[] = { //TODO : unsigned long -> unsigned int
   8, 8, 8 ,8, 4, 8 ,8, 2,
   8 ,8 ,8 ,8 ,8 ,8, 8, 8,
   4, 8, 8 ,2,
   2, 2,
   2, 8 ,8 ,8 ,8,
   4, 8 , 8, 8 ,3,
   3, 8 ,8 ,8 ,8 ,8,
   1,
   1,
   //전주
   4,8,8,4,8,4,
   4,4,4,4,
   4,8,8,2,
   8,8,8,8, 8,8,8,8,
   4,8,8,8,4,8,
   4,8,8,8,4,8,
   2,8,8,8,8,8,
   8,8,4,8,8,4,
   //2장 도돌이표
   4,8,8,4,8,8,
   4,4,8,4,3,4,
   4,4,4,4,
   8,4,8,8,3, //1줄

   4,8,8,8,4,8,
   4,8,8,8,4,8,
   1,1,//2

   4,4,4,8,8,
  // 3,8,8,3,
   4,4,4,8,8,
   8,8,8,8,8,8,8,8,//3

   4,4,4,4,
   4,8,8,2,
   4,4,4,4,
   4,8,1.5,//4

   4,4,4,8,8,
   8,4,8,8,4,8,
   8,8,8,8,8,8,8,8,
   4,4,8,
   28,28,28,28,28,28,28,
   28,28,28,28,28,28//휘익
};


void sing() {
    if(millis() < prevPlayTime + playDuration) {
        // music is playing. do nothing
        return;
    }
    // stop the tone playing:
    noTone(8);

    if(currentMelody >= melodySize)
        currentMelody = 0;
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/tempo[currentMelody];

    tone(melodyPin, melody[currentMelody], noteDuration);
    prevPlayTime = millis();
    playDuration = noteDuration * 1.30;

    currentMelody++;
}



void setup() {
  pinMode(melodyPin, OUTPUT);
}

void loop() {
  // Do what you want

  // play music
  sing();
}
