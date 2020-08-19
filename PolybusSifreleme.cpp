#include <cmath> 
#include <iostream> 
using namespace std;
void polybiusSifreleme(string sifre, int key) {
	/*------Alfabeyi Olusturdum(z-a,9-0)-------*/
	char alfabe[6][6];
	int sayac = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (122 - sayac == 96)
			{
				sayac = 65;
			}
			alfabe[i][j] = 122 - sayac;
			sayac++;
		}
	}
	/*-----Sıfreleme Islemi Burada Gerceklesiyor-----*/
	int count = 0;//girilen kelimenin hangi harfinin sifrelenecegini bulmak icin tuttuğum sayac
	for (int k = 0; k < sifre.length(); k++)
	{

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{

				if (sifre[count] == alfabe[i][j])//olusturdugumuz alfabe icerisinden bulunan karakter 
				{
					i = i + key;				//girilen key kadar kayarak sifreleniyor
					j = j + key;
					cout << i << j;				//sifreli hali ekrana yaziliyor
				}
			}
		}
		count++;
	}


}
void polybiusCozme(string x, int key) {
	/*------Alfabeyi Olusturdum(z-a,9-0)-------*/
	char alfabe[6][6];
	int sayac = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (122 - sayac == 96)
			{
				sayac = 65;
			}
			alfabe[i][j] = 122 - sayac;
			sayac++;
		}
	}
	/*----------Sifre Cozme Islemi Burada Yapilacak----------*/
	int satir, sutun;
	for (int i = 1; i <= x.length(); i += 2)
	{
		satir = 0, sutun = 0;
		satir = x[i - 1] - 48;//satir ve sutun numaralarını ASCII kodlarında aldığı icin...
		sutun = x[i] - 48;//...indisleme yapmak icin rakamlara cevirdim
		cout << alfabe[satir - key][sutun - key];//cozulmus metni yazdırdım
	}

}
int main() {
	string a, b;//gerekli olan string ifadeler
	int key;//sifrelenme icin girilecek anahtar
	int secim;
	cout << "Sifreleme 1\nSifre Cozme 2" << endl;
	cin >> secim;
	switch (secim)
	{
	case 1:
		cout << "Sifrelemek istediginiz kelimeyi giriniz" << endl;
		cin >> a;
		cout << "sifrelemede kullanilacak keyi giriniz(0-4 arasi)" << endl;
		cin >> key;
		if (key > 4)
		{
			cout << "Hatali key girisi" << endl;
			break;
		}
		polybiusSifreleme(a, key);
		break;
	case 2:
		cout << "Sifreli metni giriniz" << endl;
		cin >> b;
		cout << "sifrelemede kullanilmis keyi giriniz(0-4 arasi)" << endl;
		cin >> key;
		if (key > 4)
		{
			cout << "Hatali key girisi" << endl;
			break;
		}
		polybiusCozme(b, key);
		break;
	default:
		cout << "YANLIS SECIM";
		break;
	}
	/*key = 5;
	a = "omer";

	b = "59657756";*/

	system("pause");
}