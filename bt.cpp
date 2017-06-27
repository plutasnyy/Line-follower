#include "bt.h"
#include <SoftwareSerial.h>    
#include "Arduino.h"

SoftwareSerial Bluetooth(10, 11);  //create Bluetooth 10-RX 11-TX .available() .read()
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
void bt::read()
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
}