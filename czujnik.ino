#include "modul_bt.h"
#include "config.h"

modul_bt BT;

void setup() {
	pinMode(czujnik1, INPUT);
	pinMode(czujnik2, INPUT);
	pinMode(czujnik3, INPUT);
	Serial.begin(9600);

	pinMode(6, OUTPUT); //Sygna³ PWM silnika nr 1
	pinMode(7, OUTPUT); //Sygna³y steruj¹ce kierunkiem obrotów silnika nr 1
	pinMode(8, OUTPUT);
}
void wyswietl_cny()
{
	Serial.print("Czujnik A0: ");
	Serial.println(analogRead(czujnik1));

	Serial.print("Czujnik A1: ");
	Serial.println(analogRead(czujnik2));

	Serial.print("Czujnik A2: ");
	Serial.println(analogRead(czujnik3));
	Serial.print("\n################\n\n");
}
void uruchom_mostek()
{
	analogWrite(6, 255); //Niska prêdkoœæ obrotów  
	digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
	digitalWrite(8, HIGH);
	delay(300); //Odczekaj 3 sekundy

	analogWrite(6, 255); //Maksymalna prêdkoœæ obrotów 
	digitalWrite(7, HIGH); //Silnik nr 1 - obroty w lewo
	digitalWrite(8, LOW);
	delay(300); //Odczekaj 3 sekundy
}
void loop()
{
	//BT.wczytaj();
	//BT.wyswietl();
	//BT.wyslij_dane(dane);
	//wyswietl_cny();
	//wyswietl_bt();
	//uruchom_mostek();
	delay(1500);

}
