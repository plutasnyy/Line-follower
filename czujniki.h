#pragma once
#include "config.h"
class czujniki
{
private:
	double error, last_error;
	int wartosci_czujnikow[6];
	double T_wsp[6];
	int flaga;
public:
	czujniki();
	void ustaw_czujniki();
	double oblicz_blad();
	void wyswietl();
	double zwroc_last_error();
};