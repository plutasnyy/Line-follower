#pragma once
#include "engines.h"
#include "HashTable.h"
#include "SimpleList.h"
#include <SoftwareSerial.h>    
#include "Arduino.h"
#include <ctype.h>
#include <stdlib.h>

class Manager
{
public:

	class bt
	{
	private:
		SimpleList<String> myList;
		bool is_digit(String word);

	public:
		bt();
		~bt();

		void read(String &key, int &value);
		void print_input_list();
		void send_int(int value);
		void send_string(String value);
		int str_to_int(String temp);
	};

	Engines engines;
	Manager(Engines engines);
	void update(int input[]);
	double border(double value);

	int counter = 0;
	double error = 0;
	int average = 250;
	HashTable hash;
	int errors_scale[6] = { -3,-2,-1,1,2,3 };
	int kd = 50;
	int kp = 40;
	int speed = 100;
	double last_error = 0;
	double PID;
	double calculate_error(int input[]);
	bt BT;

};

