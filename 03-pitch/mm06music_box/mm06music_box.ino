/*
  Esplora Music Box
  
  Author: Duncan Moss, Calla Klafas
  Date: September 2014
  
  madmaker.com.au
*/

#include <Esplora.h>

// What State are we in
int state = 1;

boolean upSwitchWasPress = false;
boolean leftSwitchWasPress = false;
boolean rightSwitchWasPress = false;

// these are the frequencies for the notes from middle C
// to one octave above middle C:
const int note[] = {
262, // C
277, // C#
294, // D
311, // D#
330, // E
349, // F
370, // F#
392, // G
415, // G#
440, // A
466, // A#
494, // B
523  // C next octave
};

//int count = 2;
//int song_note[100] = {4, 2};
//int song_time[100] = {500, 500};


void setup() {
  Serial.begin(9600);
}

void loop() {
  int currNote = playNote();
  playSong();
  detectState();
  changeSong(currNote);
}


/*
 * PLAY CURRENT NOTE
 */
int playNote() {
  // Value of the Slider
  // Expect Range 1023 - 0 (Left - Right)
  int sVal = Esplora.readSlider();
  
  // map sVal into note range
  byte currNote = map(sVal, 0, 1024, 0, 13);
  if (Esplora.readButton(SWITCH_DOWN) == LOW) {
    Esplora.tone(note[currNote]);
  } else {
    Esplora.noTone();
  }
  return currNote;
}
 
/*
 * PLAY CURRENT SONG
 */
void playSong() {
  boolean leftSwitch;
  int leftSwitchPress = Esplora.readButton(SWITCH_LEFT) == LOW;
  leftSwitch = leftSwitchWasPress && !leftSwitchPress;
  leftSwitchWasPress = leftSwitchPress;
  if (leftSwitch) {
    Esplora.writeRGB(0, 255, 0);
    for (int i = 0; i < 100; i ++) {
      if (song_time[i]!=0){
        Esplora.tone(note[song_note[i]], song_time[i]);
        delay(song_time[i]);
        Esplora.noTone();
        delay(10);
      }
    }
  }
}


/*
 * Detect State
 */
void detectState() {
  // Change State
  // Edge Detection Switch Up
  boolean upSwitch;
  int upSwitchPress = Esplora.readButton(SWITCH_UP) == LOW;
  upSwitch = upSwitchWasPress && !upSwitchPress;
  upSwitchWasPress = upSwitchPress;
  
  if (upSwitch) {
    state = state == 1 ? 0 : state + 1;
  }
    
  if (state == 0) {
    // Remove Mode
    Esplora.writeRGB(255, 0, 0);
  } else  {
    // Add Mode
    Esplora.writeRGB(0, 0, 255);
  }    
}

void changeSong(int currNote) {
  boolean rightSwitch;
  int rightSwitchPress = Esplora.readButton(SWITCH_RIGHT) == LOW;
  rightSwitch = rightSwitchWasPress && !rightSwitchPress;
  rightSwitchWasPress = rightSwitchPress;
  
  if (rightSwitch) {
    if (state == 0) {
      // Attempt Remove
      if (count == 0) {
        Esplora.writeRGB(0, 255, 255);
        delay(500);
      } else {
        count -= 1;
        song_time[count] = 0;
      }
    } else {
      if (count == 100) {
        Esplora.writeRGB(0, 255, 255);
        delay(500); 
      } else {
        song_note[count] = currNote;
        song_time[count] = 500;
        count += 1;
      }
    }
  }
}
