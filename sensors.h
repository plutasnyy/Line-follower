#pragma once
#include "config.h"
#include "Manager.h"
#include <Arduino.h>

class Sensors
{
public:
	int input[6];
	Sensors();
	void read_data(Manager &manager);
	void print_data();
};