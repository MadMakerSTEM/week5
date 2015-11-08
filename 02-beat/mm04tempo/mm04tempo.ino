#include<Esplora.h>

//Global Variables
float tempo, averagePeriod;

void setup() {
  Serial.begin(9600);

}

void loop() {
  float x = tapBeat();

  if (x>0){
    //averagePeriod = //Calculate the average period between the four beats 
    //tempo = //Calculate the average tempo in beats per minute
    Serial.print("duration (ms): ");Serial.println(x);
    Serial.print("calculated tempo: ");Serial.println(tempo);
  }

}

// Special function: Measured the time for 4 beats to pass.
float tapBeat() {
  int wait = 50; //wait this many milliseconds as a buffer 
  int sensitivity;
  int count=0;
  long elapsed, time1, time2;
  int debounce =10; //another buffer
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
    time2=millis();
    elapsed = time2 - time1;
    elapsed=K1*elapsed+K2; // correction factor based on the inaccuracy of the onboard timer 
    return elapsed;
  }
  return 0;
}
