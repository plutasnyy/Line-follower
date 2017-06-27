#include "Manager.h"


void Manager::update(int input[])
{
	//BT.send_string("Czujniki:");
	//for (int i = 0; i < 6; i++) { BT.send_int(input[i]); }
	//BT.send_string("error: ");

	double error = calculate_error(input);
	PID = error*kp + last_error*kd;
	//BT.send_int((int)error);
	//BT.send_string("PID:");
	//BT.send_int(int(PID));
	double left = border(speed - PID);
	double right = border(speed + PID);
	Serial.println("Error i PID: ");
	Serial.print(error);
	Serial.print(PID);

//	engines.drive(speed,speed);

	last_error = error;
}

double Manager::calculate_error(int input[])
{
	int counter = 0;
	double error = 0;
	for (int i = 0; i < 6; i++)
	{
		if (input[i] > average)
		{
			error += errors_scale[i];
			counter++;
		}
	}
	return counter == 0 ? last_error : (double)error / counter;
}

double Manager::border(double value)
{
	if (value < 0)value = 0;
	if (value > 255)value = 255;
	return (int)value;
}