#include "bt.h" // wymaga delay w petli minimum 1ms
#include "sensors.h"
#include "engines.h"
#include "Manager.h"
#include "HashTable.h"

bt BT;
Engines engines;
Manager manager(engines,BT);
Sensors sensors;

void setup() 
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	//sensors.read_data(manager);
	//BT.read(manager);
	delay(10);
}
