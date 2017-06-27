#include "bt.h" // wymaga delay w petli minimum 1ms
#include "sensors.h"
#include "engines.h"
#include "Manager.h"



bt BT;
Engines engines;
Manager manager;
Sensors sensors;

void setup() 
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	engines.drive(200, 200);
	delay(10);
}
