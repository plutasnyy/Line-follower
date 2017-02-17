#include "czujniki.h"
#include "config.h"
#include <Arduino.h>

czujniki::czujniki()	
{
	T_wsp[0] = 1;
	T_wsp[1] = 1;
	T_wsp[2] = 2;
	pinMode(czujnik1, INPUT);
	pinMode(czujnik2, INPUT);
	pinMode(czujnik3, INPUT);
}
void czujniki::ustaw_czujniki()
{
	wartosci_czujnikow[0] = analogRead(czujnik1);
	wartosci_czujnikow[1] = analogRead(czujnik2);
	wartosci_czujnikow[2] = analogRead(czujnik3);
}
double czujniki::oblicz_blad(double avg)
{
	flaga = 0;
	last_error = error;
	error = 0;
	ustaw_czujniki();
	for (int i = 0; i <= 2; i++)
	{
		//if (wartosci_czujnikow[i] >= avg)
			//error += T_wsp[i];
		flaga++;
	}
	if (flaga == 0) error = last_error;
	else error /= flaga;

	return error;
}
double czujniki::zwroc_last_error()
{
	return last_error;
}