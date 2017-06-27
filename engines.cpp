#include "engines.h"

Engines::Engines()
{
	pinMode(S1, OUTPUT);
	pinMode(S1_P, OUTPUT);
	pinMode(S1_T, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S2_P, OUTPUT);
	pinMode(S2_T, OUTPUT);
}

void Engines::drive(int left, int right)
{
	digitalWrite(S1_T, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(S1_P, LOW);
	digitalWrite(S2_P, HIGH); //Silnik nr 2 - obroty w lewo
	digitalWrite(S2_T, LOW);

	analogWrite(S1, left); 
	analogWrite(S2, right); 	
}