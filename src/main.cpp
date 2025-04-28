/*
  David Karacsonyi
  28.04.2025
  ADC exercise
*/

#include <Arduino.h>


void setup() {
  Serial.begin(115200);
}

void loop() {
  int poti_value = analogRead (A0);

  float voltage = (poti_value * 5) / 1023;

  Serial.print("Potentiometer analog value = ");
  Serial.print("voltage,2");
  Serial.println(" V");
}