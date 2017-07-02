#include "sensors.h"
#include "engines.h"
#include "Manager.h"
#include "HashTable.h"
HashTable hashh;
Engines engines;
Manager manager(engines);
Sensors sensors;

void setup() 
{
	hashh.add("lol", 1);
	hashh.get("lol");
	hashh.set("lo", 2);
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	sensors.read_data(manager);
	delay(10);
}
