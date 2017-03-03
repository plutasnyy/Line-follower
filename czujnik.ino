#include "config.h"
#include "modul_bt.h" // wymaga delay w petli minimum 1ms
#include "czujniki.h"
modul_bt BT;
czujniki czujniki;

int kd = 0, kp = 0, ki = 0;
double avg = 200.0, error = 0, last_error = 0;
void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT); 
	pinMode(6, OUTPUT); 
	pinMode(8, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
}
void uruchom_mostek()
{
	digitalWrite(12, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(8, LOW);
	digitalWrite(3, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(4, LOW);
	for (int i = 0; i <= 255; i+=10)
	{
		analogWrite(5, 255); //Maksymalna pr?dko?? obrot?w 
		analogWrite(6, 255); //Maksymalna pr?dko?? obrot?w 
	}
}
void loop()
{
	digitalWrite(13, HIGH);
	czujniki.ustaw_czujniki();
	czujniki.wyswietl();
	BT.wczytaj();
	BT.wyswietl();
	delay(1000);
}