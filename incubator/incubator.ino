#include "DHT.h"

DHT dht;
#define SW 8

void setup()
{
  Serial.begin(9600);
  dht.setup(2); // data pin 2
    pinMode(SW, OUTPUT);
}

void loop()
{
  //delay(dht.getMinimumSamplingPeriod());
  float temperature = dht.getTemperature();
  Serial.println(temperature);
  if(temperature >= 37.7  )
  {
    digitalWrite(SW, HIGH);
    Serial.println("OFF");
    delay(10);
  }
  if(temperature <= 36)
  {
    digitalWrite(SW, LOW);
    Serial.println("ON");
    delay(10);
  }
  delay(250);

}
