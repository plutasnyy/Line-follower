#pragma once
#include "engines.h"
#include "bt.h"

class Manager
{
public:
	void update(int input[]);
	double border(double value);

private:
	int errors_scale[6] = { -3,-2,-1,1,2,3 };
	int average = 240;
	int kd = 10;
	int kp = 20;
	int speed = 125;
	double last_error = 0;
	double PID;

	double calculate_error(int input[]);
};

