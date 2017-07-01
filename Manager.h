#pragma once
#include "engines.h"
#include "bt.h"
#include "HashTable.h"

class Manager
{
public:
	Engines engines;
	bt BT;
	Manager(Engines engines,bt BT );
	void update(int input[]);
	double border(double value);
	void set_hash(String key, int value);

private:
	HashTable hash;
	int errors_scale[6] = { -3,-2,-1,1,2,3 };
	int average = 240;
	int kd = 50;
	int kp = 40;
	int speed = 100;
	double last_error = 0;
	double PID;

	double calculate_error(int input[]);
};

