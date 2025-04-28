/*
  David Karacsonyi
  28.04.2025
  ADC exercise
*/

#include <Arduino.h>

#define ADC_CHANNEL 0;

ADMUX |= (1<<REFS0);
ADMUX &= ~(REFS1);

ADMUX |= 0b0000;




void setup() {
  Serial.begin(115200);

  ADCSRA |= _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
  
  ADMUX = (ADMUX & 0b11110000) | ADC_CHANNEL;

  ADMUX |= _BV(REFS0);
  }

void loop() {

  ADCSRA |= _BV(ADSC);
  if((ADCSRA & _BV(ADSC)) != 0);
  {
    int poti_value = ADC;
  }

  float voltage = (poti_value * 5.0) / 1023;

  Serial.print("Potentiometer analog value = ");
  Serial.print("voltage,2");
  Serial.println(" V");
}