#include "sensors.h"
#include "engines.h"
#include "Manager.h"
#include "HashTable.h"

Engines engines;
Manager manager(engines);
Sensors sensors;
Manager::bt X;
HashTable HASH;
void setup() 
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	Serial.println(" ");
	//Serial.println(5);
	sensors.read_data(manager);
	//Serial.println("w");
}
