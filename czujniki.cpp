#include "czujniki.h"
#include "config.h"
#include <Arduino.h>

czujniki::czujniki()	
{
	pinMode(czujnik1, INPUT);
	pinMode(czujnik2, INPUT);
	pinMode(czujnik3, INPUT);
	pinMode(czujnik4, INPUT);
	pinMode(czujnik5, INPUT);
	pinMode(czujnik6, INPUT);
}
void czujniki::ustaw_czujniki()
{
	wartosci_czujnikow[0] = analogRead(czujnik1);
	wartosci_czujnikow[1] = analogRead(czujnik2);
	wartosci_czujnikow[2] = analogRead(czujnik3);
	wartosci_czujnikow[3] = analogRead(czujnik4);
	wartosci_czujnikow[4] = analogRead(czujnik5);
	wartosci_czujnikow[5] = analogRead(czujnik6);
}
void czujniki::wyswietl()
{
	for (int i = 0; i < 6; i++)
	{
		Serial.println(i+1);
		Serial.println(wartosci_czujnikow[i]);
	}
	Serial.println(" ");
}
double czujniki::oblicz_blad()
{
	double avg = 300;
	flaga = 0;
	last_error = error;
	error = 0;

	ustaw_czujniki();
	wyswietl();
	for (int i = 0; i <= 5; i++)
	{
		if (wartosci_czujnikow[i] >= avg)
		{
			error += T_wsp[i];
			flaga++;
		}
	}

	if (flaga == 0) error = last_error;
	else error /= flaga;

	return error;
}
double czujniki::zwroc_last_error()
{
	return last_error;
}