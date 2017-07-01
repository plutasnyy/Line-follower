#include "sensors.h"
#include "engines.h"
#include "Manager.h"

Engines engines;
Manager manager(engines);
Sensors sensors;

void setup() 
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	sensors.read_data(manager);
	delay(10);
}
