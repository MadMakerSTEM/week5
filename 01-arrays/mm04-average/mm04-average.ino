#include <Esplora.h>

#define SIZE 20

int randArray[SIZE];

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A9));
}

void loop() {
  randomArray();
  int avg = getAverage();
  printArray(avg);
  delay(5000);
}

void randomArray() {
  int r = 0;
  for(int i = 0; i < SIZE; i++) {
    r = random(100);
    randArray[i] = r;
  }
}

float getAverage() {
  float sum = 0.0;
  for(int i = 0; i < SIZE; i++) {
    // add code here, you will need to
    // access each element in the array
    // and add it to sum
  }
  // change this based on the formula
  return 0.0; 
}

void printArray(float avg) {
  for(int i = 0; i < SIZE; i++) {
    Serial.print(randArray[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("The average is: ");
  Serial.println(avg);
}
