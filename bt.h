#pragma once
#include "SimpleList.h"
#include <SoftwareSerial.h>    
#include "Arduino.h"
#include "Manager.h"

class bt
{
private:
	SimpleList<String> myList;
	bool is_digit(String word);

public:
	bt();
	~bt();
	Manager manager;
	void read();
	void print_input_list();
	void send_int(int value);
	void send_string(String value);
};

