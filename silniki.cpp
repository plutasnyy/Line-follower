#include "silniki.h"
#include <Arduino.h>
#include "config.h"
silniki::silniki()
{
	pinMode(S1, OUTPUT);
	pinMode(S1_P, OUTPUT);
	pinMode(S1_T, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S2_P, OUTPUT);
	pinMode(S2_T, OUTPUT);
}

void silniki::uruchom(double kd, double error)
{
	digitalWrite(S1_P, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(S1_T, LOW);
	digitalWrite(S2_P, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(S2_T, LOW);
	
	zmiana = 0;
	zmiana = kd*error;
	Serial.println(zmiana);
		analogWrite(S1, 120+zmiana); //Maksymalna pr?dko?? obrot?w 
		analogWrite(S2, 120-zmiana); //Maksymalna pr?dko?? obrot?w 
	
}