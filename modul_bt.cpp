#include "modul_bt.h"
#include <SoftwareSerial.h>    
#include "Arduino.h"

SoftwareSerial Bluetooth(10, 11);  //Utworz instancje Bluetooth 10-RX 11-TX
								   // .available() .read()
modul_bt::modul_bt()
{
	Bluetooth.begin(9600);                      //uruchom SerialSoftware z pr?dko?ci? 9600 baud
	Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
}
modul_bt::~modul_bt()
{
	myList.clear();
}
void modul_bt::wyswietl()
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
void modul_bt::wczytaj()
{
	myList.clear();
	if (Bluetooth.available())
	{
		while (Bluetooth.available())
		{
			odczyt = Bluetooth.read();
			if (odczyt == '.' or odczyt == ' ')
			{
				myList.push_back(przechowaj_slowo);
				przechowaj_slowo = "";
			}
			else
			{
				przechowaj_slowo += odczyt;
			}
		}
		//Serial.println(przechowaj_slowo);
		myList.push_back(przechowaj_slowo);
		przechowaj_slowo = "";
	}
}