#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;
int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup(void) {
  Serial.begin(9600);
  Serial.println("Bas on tech - 1-wire temperatuur sensor");
  sensors.begin();
}

void loop(void) {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  Serial.print("Temp is:");
  Serial.println(temp);
  delay(1000);
}
