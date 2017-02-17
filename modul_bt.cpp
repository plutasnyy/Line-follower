#include "modul_bt.h"
#include <SoftwareSerial.h>    
#include "Arduino.h"
#include <SimpleList.h>
SimpleList<int> myList;
SoftwareSerial Bluetooth(10, 11);  //Utworz instancje Bluetooth 10-RX 11-TX
								   // .available() .read()
modul_bt::modul_bt()
{
	Bluetooth.begin(9600);                      //uruchom SerialSoftware z prêdkoœci¹ 9600 baud
	Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
}

modul_bt::~modul_bt()
{
}

void modul_bt::wyswietl()
{
	if (Bluetooth.available())
		{
			int odczyt = 0;
			Serial.println("WCZYTUJE DANE BLUETOOTH:");
			while (Bluetooth.available())
			{
				odczyt = Bluetooth.read();
				Serial.println(odczyt);
			}
		}
}
