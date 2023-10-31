#include <Arduino.h>

const int sensor = 17;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(sensor));
  delay(50);
}
