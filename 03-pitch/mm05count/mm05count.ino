

#include <Esplora.h>

//Global Variables
float tempo, averagePeriod;
int note_period = 375; //375 by default -- this should change when we run the tempo tapper

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

// PASTE SONG HERE
// Mary Had A Little Lamb
const int song[100] = {
  4, 2, 0, 2, 4, 4, 4, 2, 2, 2, 4, 7, 7, 4, 2, 0, 2, 4, 4, 4, 4, 2, 2, 4, 2, 0
};

const int song_time[100] = {
  4, 4, 4, 4, 4, 4, 8, 4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8
};

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Esplora.readButton(SWITCH_1) == LOW){
    float x = tapBeat();
    //averagePeriod = __________//Calculate the average period of one beat between the four beats (in milliseconds)
    //note_period = ____________ // Calculate the note_period which is one-quarter the length of one beat (in milliseconds)
    delay(4 * note_period); //wait a beat before synchronising with the song
    playSong();
  }
}

// Special function: Measured the time for 4 beats to pass.
float tapBeat() {
  int wait = 50; //wait this many milliseconds as a buffer
  int sensitivity;
  int count = 0;
  long elapsed, time1, time2;
  int debounce = 10; //another buffer
  int tempo = 0;
  float K1 = 0.9996;
  float K2 = -72;
  int period;
  if (Esplora.readButton(SWITCH_1) == LOW) { // starts by pressing bottom button
    Esplora.writeRed(255);
    delay(1500); //wait for a second and a half for the user to get ready
    Esplora.writeRed(0); //.. as indicated by the red light
    sensitivity = Esplora.readSlider();
    while (count < 4) {
      int loudness = Esplora.readMicrophone();
      if (loudness > sensitivity) {
        time1 = millis();
        Esplora.writeGreen(128);
        delay(debounce);
        Esplora.writeGreen(0);
        count++;
        delay(wait);//wait
        while (count < 4) {
          loudness = Esplora.readMicrophone();
          if (loudness > sensitivity) {
            Esplora.writeGreen(128);
            delay(debounce);
            Esplora.writeGreen(0);
            count++;
            delay(wait);//wait
          }
        }
      }
    }
    time2 = millis();
    elapsed = time2 - time1;
    elapsed = K1 * elapsed + K2; // correction factor based on the inaccuracy of the onboard timer
    return elapsed;
  }
  return 0;
}

void playSong() {
  for (int i = 0; i < 100; i ++) {
    if (song_time[i] != 0) {
      Esplora.tone(note[song[i]]);
      delay(song_time[i]*note_period);
      Esplora.noTone();
      delay(10);
    }
  }
}



