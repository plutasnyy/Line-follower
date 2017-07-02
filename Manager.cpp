#include "Manager.h"

SoftwareSerial Bluetooth(8, 5);  //create Bluetooth 10-RX 11-TX .available() .read()

Manager::Manager(Engines engines)
{
	this->engines = engines;
	hash.add("ki", 0);
	hash.add("kd", 30);
	hash.add("kp", 20);
	hash.add("average", 250);
	hash.add("speed", 0);
}

void Manager::update(int input[])
{
	String key;
	int value;
	BT.read(key,value);
	BT.send_int(value);
	BT.send_string(key);
	if (!value == -1)
		hash.set(key, value);

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

Manager::bt::bt()
{
	Bluetooth.begin(9600);                      //uruchom SerialSoftware z pr?dko?ci? 9600 baud
	Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
}
Manager::bt::~bt()
{
	myList.clear();
}
void Manager::bt::send_int(int value)
{
	Bluetooth.println(value);
}
void Manager::bt::send_string(String value)
{
	Bluetooth.println(value);
}
void Manager::bt::print_input_list()
{
	if (!myList.empty())
	{
		Serial.println("ODCZYTALEM: ");
		for (SimpleList<String>::iterator i = myList.begin(); i != myList.end(); ++i)
		{
			Serial.println(*i);
		}
	}
}

void Manager::bt::read(String &key, int &value)
{
	myList.clear();
	String word = "";
	char input;
	if (Bluetooth.available())
	{
		while (Bluetooth.available())
		{
			input = Bluetooth.read();
			if (input == '.' || input == ' ')
			{
				myList.push_back(word);
				word = "";
			}
			else
			{
				word += input;
			}
		}
		if (word.length() > 0)
			myList.push_back(word);
	}

	if (myList.size() == 2)
	{
		value = -1;
		String temp;
		int flaga = 0;
		for (SimpleList<String>::iterator i = myList.begin(); i != myList.end(); ++i)
		{
			if (flaga == 0)
			{
				key = *i;
				flaga++;
			}
			else
				temp = *i;
		}
		if (is_digit(temp))
			value = atoi(temp.c_str());
	}

}

bool Manager::bt::is_digit(String word)
{
	for (int i = 0; i < word.length(); i++)
		if (!isdigit(word[i]))
			return false;
	return true;
}