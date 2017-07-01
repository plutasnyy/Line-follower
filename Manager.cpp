#include "Manager.h"

Manager::Manager(Engines engines,bt BT)
{
	this->engines = engines;
	this->BT = BT;
	hash.add("ki", 0);
	hash.add("kd", 30);
	hash.add("kp", 20);
	hash.add("average", 250);
	hash.add("speed", 100);
}

void Manager::update(int input[])
{
	double error = calculate_error(input);

	PID = error*hash.get("kp") + last_error*hash.get("kd");

	double left = border(hash.get("speed") + PID);
	double right = border(hash.get("speed") - PID);

	engines.drive(left,right);

	last_error = error;
}

double Manager::calculate_error(int input[])
{
	int counter = 0;
	double error = 0;
	for (int i = 0; i < 6; i++)
	{
		if (input[i] > hash.get("average"))
		{
			error += errors_scale[i];
			counter++;
		}
	}
	return counter == 0 ? 0 : (double)error / counter;
}

double Manager::border(double value)
{
	if (value < 0)value = 0;
	if (value > 255)value = 255;
	return (int)value;
}

void Manager::set_hash(String key, int value)
{
	hash.set(key, value);
}