#include "sensors.h"

Sensors::Sensors()	
{
	pinMode(sensor1, INPUT);
	pinMode(sensor2, INPUT);
	pinMode(sensor3, INPUT);
	pinMode(sensor4, INPUT);
	pinMode(sensor5, INPUT);
	pinMode(sensor6, INPUT);
}
void Sensors::read_data(Manager manager)
{
	input[0] = analogRead(sensor1);
	input[1] = analogRead(sensor2);
	input[2] = analogRead(sensor3);
	input[3] = analogRead(sensor4);
	input[4] = analogRead(sensor5);
	input[5] = analogRead(sensor6);
	print_data();
	manager.update(input);
}
void Sensors::print_data()
{
	for (int i = 0; i < 6; i++)
	{
		Serial.println(i+1);
		Serial.println(input[i]);
	}
	Serial.println(" ");
}