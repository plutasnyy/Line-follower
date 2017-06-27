#pragma once
#include <Arduino.h>
#include "config.h"

class Engines
{
public:
	Engines();
	void drive(int left, int right);
};

