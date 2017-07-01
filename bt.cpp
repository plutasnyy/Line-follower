#include "bt.h"

SoftwareSerial Bluetooth(8,5);  //create Bluetooth 10-RX 11-TX .available() .read()

bt::bt()
{
	Bluetooth.begin(9600);                      //uruchom SerialSoftware z pr?dko?ci? 9600 baud
	Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
}
bt::~bt()
{
	myList.clear();
}
void bt::send_int(int value)
{
	Bluetooth.println(value);
}
void bt::send_string(String value)
{
	Bluetooth.println(value);
}
void bt::print_input_list()
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
void bt::read(Manager manager)
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
		if (word.length() > 0 )
			myList.push_back(word);
	}
	if (myList.size() == 2)
	{
		String key,temp;
		int value;
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
		{
			value = atoi(temp.c_str());
			manager.set_hash(key, value);
		}
	}
}

bool bt::is_digit(String word)
{
	for (int i = 0; i < word.length(); i++)
		if (!isdigit(word[i]))
			return false;
	return true;
}