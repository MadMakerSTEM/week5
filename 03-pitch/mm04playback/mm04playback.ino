#include <Esplora.h>

int note_period=375  ;

const int note[] = {
  262, //0 C4
  277, //1 C#
  294, //2 D
  311, //3 D#
  330, //4 E
  349, //5 F
  370, //6 F#
  392, //7 G
  415, //8 G#
  440, //9 A
  466, //10 A#
  494, //11 B
  523 //12 C5 next octave
};


// Mary Had A Little lamb 
const int song[100] = {
  4,2,0,2,4,4,4,2,2,2,4,7,7,4,2,0,2,4,4,4,4,2,2,4,2,0
};

const int song_time[100] = {
  4,4,4,4,4,4,8,4,4,8,4,4,8,4,4,4,4,4,4,4,4,4,4,4,4,8
};

////A thousand Miles - Vanessa Carlton
//const int song[100] = {
//  11,23,11,23,22,11,22,18,15,13,11,23,11,23,22,11,22,18,11,18,11,18,11,15,16,15
//    ,11,23,11,23,22,11,22,18,15,13,11,15,13,11,15,13,11,18,13
//};
//
//const int song_time[100] = {
//  1,1,1,1,1,1,1,6,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,2,1,1,1,1,1,1,1,1,5,4
//};

////Mario Brothers
//const int song[100] = {
//  16,16,16,12,16,19,7,12,7,0,9,11,10,9
//};
//
//const int song_time[100] = {
//  1,2,2,1,2,4,4,3,2,2,2,2,2,1,1,1,1,1,5,4
//};


void setup() {
  

}

void loop() {
  if (Esplora.readButton(SWITCH_DOWN)==LOW){
    playSong();
  }
}

void playSong(){
    for (int i = 0; i < 100; i ++) {
      if (song_time[i]!=0){
        Esplora.tone(note[song[i]]);
        delay(song_time[i]*note_period);
        Esplora.noTone();
        delay(10);
      }
    }
}
