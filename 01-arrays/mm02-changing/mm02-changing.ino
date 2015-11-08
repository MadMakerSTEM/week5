#include <Esplora.h>

int buttons[4];

void setup() {
  Serial.begin(9600);
}

void loop() {
  readButtons();
  printButtons();
  delay(200);
}

void readButtons() {
  for(int i = 0; i < 4; i++) {
    buttons[i] = Esplora.readButton(i+1);
  }  
}

void printButtons() {
  for(int i = 0; i < 4; i++) {
    Serial.print(buttons[i]);
    Serial.print(" ");
  }  
  Serial.println();
}
