#include <Esplora.h>

#define SIZE 20

int randArray[SIZE];

void setup() {
  randomSeed(analogRead(A9));
}

void loop() {
  randomArray();
  float avg = getAverage();
  int maximum = getMax();
  int minimum = getMin();
  printResults(avg, maximum, minimum);
  delay(5000);
}

void randomArray() {
  int r = 0;
  for (int i = 0; i < SIZE; i++) {
    r = random(100);
    randArray[i] = r;
  }
}

float getAverage() {
  float sum = 0.0;
  for (int i = 0; i < SIZE; i++) {
    sum += randArray[i];
  }
  return sum / SIZE;
}

int getMax() {
  int maximum = randArray[0];         // first one max
  for (int i = 1; i < SIZE; i++) {    // go through the rest
    // add code to find the maximum here
  }
  return maximum;
}

int getMin() {
  int minimum = randArray[0];         // first one min
  for (int i = 1; i < SIZE; i++) {    // go through the rest
    // add code to find the minimum here
  }
  return minimum;
}


void printResults(float avg, int maximum, int minimum) {
  for (int i = 0; i < SIZE; i++) {
    Serial.print(randArray[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Average: ");
  Serial.print(avg);
  Serial.print(" Max: ");
  Serial.print(maximum);
  Serial.print(" Min: ");
  Serial.print(minimum);
  Serial.print(" Range: ");
  Serial.print(0);            // print the range here
  Serial.println();
}