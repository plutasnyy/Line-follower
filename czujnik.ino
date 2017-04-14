#include "modul_bt.h" // wymaga delay w petli minimum 1ms
#include "czujniki.h"
#include "silniki.h"
#include "wsp.h"

modul_bt BT;
czujniki czujniki;
silniki silniki;

int kd = 40, kp = 0, ki = 0;
double avg = 200.0, error = 0, last_error = 0;

void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}
void loop()
{
	error = czujniki.oblicz_blad();
	silniki.uruchom(kd,error);
	delay(10);
}
