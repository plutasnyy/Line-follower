#pragma once
#include <SimpleList.h>
#include "data.h"
class modul_bt
{
private:
	SimpleList<String> myList;
	String przechowaj_slowo = "";
	char odczyt = 0;

public:
	modul_bt();
	~modul_bt();
	void wczytaj();
	void wyswietl();
	void wyslij_dane(data);
};

