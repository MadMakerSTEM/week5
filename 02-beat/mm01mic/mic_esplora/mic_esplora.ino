#include<Esplora.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int mic = Esplora.readMicrophone();
  int slider =Esplora.readSlider();
  Serial.print(mic);
  Serial.print(",");
  Serial.println(slider); //print values of slider and microphone
  //if(){ ///if microphone is greater than the slider
  //  //make light red
  //}
  //else{
  //  //make light off
  //}
  delay(5);
}
