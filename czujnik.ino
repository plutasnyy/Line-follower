#include "config.h"
#include "modul_bt.h"
#include "czujniki.h"
modul_bt BT;
czujniki czujniki;

int kd = 0, kp = 0, ki = 0;
double avg = 0, error = 0, last_error = 0;
void setup() {
	Serial.begin(9600);
	pinMode(6, OUTPUT); //Sygna? PWM silnika nr 1
	pinMode(7, OUTPUT); //Sygna?y steruj?ce kierunkiem obrot?w silnika nr 1
	pinMode(8, OUTPUT);
}
void uruchom_mostek()
{
	analogWrite(6, 255); //Niska pr?dko?? obrot?w  
	digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
	digitalWrite(8, HIGH);
	delay(300); //Odczekaj 3 sekundy

	analogWrite(6, 255); //Maksymalna pr?dko?? obrot?w 
	digitalWrite(7, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(8, LOW);
	delay(300); //Odczekaj 3 sekundy
}
void loop()
{
	delay(1500);
}