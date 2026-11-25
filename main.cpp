// Mohawk College - COMP-10184
//
// Basic GPIO Pin Configuration
//
#include <Arduino.h>
// these are numerical contants #define them this way instead
// of hard-coding these values into your program
#define PIN_LED 2
#define PIN_BUTTON 14
int count = 0;
bool lowToHigh;
void setup() {
// put your setup code here, to run once:
// intialize serial USB monitor
  Serial.begin(115200);
// configure GPIO pins
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLDOWN);
}
void loop() {
// put your main code here, to run repeatedly:
// acquire button input (up: btn=0, down: btn=1)
int btn = digitalRead(PIN_BUTTON);

  if (btn == 1 && lowToHigh == true)
  {
    if (count == 3){
      count = 0;
    } else {
      count ++;
    }
  
}

  if (count == 0)
  {
    analogWrite(PIN_LED, 5);
  }
  else if (count == 1)
  {
    analogWrite(PIN_LED, 50);
  }
  else if (count == 2)
  {
    analogWrite(PIN_LED, 150);
  }
  else if (count == 3)
  {
    analogWrite(PIN_LED, 255);
  }
  if (btn == 1)
    lowToHigh = false;
  else
    lowToHigh = true;
    
  delay(1);
}