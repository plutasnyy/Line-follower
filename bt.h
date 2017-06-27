#pragma once
#include "SimpleList.h"

class bt
{
private:
	SimpleList<String> myList;

public:
	bt();
	~bt();
	void read();
	void print_input_list();
	void send_int(int value);
	void send_string(String value);
};

