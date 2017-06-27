#include "bt.h" // wymaga delay w petli minimum 1ms
#include "sensors.h"
#include "engines.h"
#include "Manager.h"

bt BT;
Engines engines;
Manager manager(engines,BT);
Sensors sensors;

void setup() 
{
}
void loop()
{
	sensors.read_data(manager);
	delay(12);
}
