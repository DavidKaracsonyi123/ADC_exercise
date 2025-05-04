/*
  David Karacsonyi
  28.04.2025 - 03.05.2025
  ADC exercise
*/

#include <Arduino.h>

#define ADC_CHANNEL 0

volatile int poti_value = 0;

void setup() {
  Serial.begin(115200);

  ADMUX = (1 << REFS0) | (ADC_CHANNEL & 0b00001111);

  // enable ADC and set prescaler to 128 -> 125kHz @ 16MHz (best conversion rast is between 50 - 200kHz)
  ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  sei(); //activate global Interrupts

  ADCSRA |= (1 << ADSC); //start first Conversion
}

void loop() {
  float voltage = (poti_value * 5.0) / 1023;

  Serial.print("Potentiometer analog value = ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  delay(500); // show only 500ms new value
}

ISR(ADC_vect) {
  poti_value = ADC; //read value
  ADCSRA |= (1 << ADSC); //start next Conversion
}




