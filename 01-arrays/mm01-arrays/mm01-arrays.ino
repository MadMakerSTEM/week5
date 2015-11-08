int num[] = {3, 14, 1, 5, 9};  // declare an array and it's elements
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.print(num[i]);      // print each element
    Serial.print(" ");
  }
  Serial.println();
  delay(5000);
}
