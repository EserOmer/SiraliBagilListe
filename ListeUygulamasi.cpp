#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node {
	string data;
	node* next;
	node* prev;
};
node* ilknode(node* r, string x) {
	//bos node olusturmak istediğimizde kullanılacak node.
	r = new node;
	r->data = x;
	r->next = r;
	r->prev = r;
	return r;
}
void dosyayaekle(string u) {
	//Dosyaya veri aktarımı icin kullandığım fonksiyon
	ofstream  writer("araclar.txt", ios::app);
	writer << u << endl;
	writer.close();

}
node* ekle(node* r, string x)
{
	//listeye veri eklemek icin kullandıgım fonksiyon
	if (r == NULL)
	{
		r = ilknode(r, x);
		return r;
	}
	else
	{
		r->prev->next = new node;
		r->prev->next->data = x;
		r->prev->next->next = r;
		r->prev->next->prev = r->prev;
		r->prev = r->prev->next;
	}
	return r;
}
void sil(string s)
{
	//Dosyadan Veri Silmek İcin kullandıgım fonskiyon
	//veri silmek istedigimde yeni bi dosya olusturup silinenden haric verileri
	//yeni dosyaya yazdıktan sonra isim degisikliği yapıp eski dosyayı sildim
	//swap islemi de diyebiriz.

	ifstream dosyaoku;
	ofstream DosyaYaz;
	string okudugun1;
	dosyaoku.open("araclar.txt", ios::in);
	DosyaYaz.open("bosdosya.txt", ios::app);
	int sayac = 0, sayac2 = 0;
	cout << endl;
	while (!dosyaoku.eof())
	{
		getline(dosyaoku, okudugun1);

		if (okudugun1.compare(s) == 0)
		{
			sayac2++;
		}
		else if (okudugun1 != "")
			DosyaYaz << okudugun1 << endl;

	}
	if (sayac2 == 0)
	{
		cout << "Silinecek Kayit yok" << endl;
	}
	else
		cout << "Kayit Silinmistir" << endl;

	dosyaoku.close();
	DosyaYaz.close();
	remove("araclar.txt");
	rename("bosdosya.txt", "araclar.txt");
}
void ara(string aranan) {
	string ad;
	ifstream dosya1("araclar.txt", ios::in);
	if (dosya1.is_open())
	{
		int x = 0;
		do
		{
			getline(dosya1, ad);
			if (ad == aranan) {
				cout << ad << " bulundu" << endl;
				x = 1;
			}
		} while (!dosya1.eof());

		if (x == 0)
			cout << aranan << " diye kayitli isim yok" << endl;
	}
	system("Pause");
}
node* dosyayioku(node* o) {
	ifstream dosyaoku;
	ofstream  writer("araclar.txt", ios::app);
	dosyaoku.open("araclar.txt", ios::in);
	string okunan;
	getline(dosyaoku, okunan);
	if (okunan == "")
	{
		return 0;
	}

	dosyaoku.close();
	dosyaoku.open("araclar.txt", ios::in);

	while (!dosyaoku.eof())
	{

		getline(dosyaoku, okunan);
		o = ekle(o, okunan);

	}

	dosyaoku.close();
	return o;
}
void gezin(node* r) {

	string h;

	if (r == NULL)
	{
		cout << "liste bos" << endl;
	}
	else
	{
		node* yrd;
		yrd = r;
		do
		{
			cout << "ileri - (i) geri - (g), cikis - (c) : ";
			cin >> h;
			if (h == "i")
			{
				cout << yrd->data << endl;
				yrd = yrd->next;
				if (yrd == r)
				{
					cout << "Liste Bitti" << endl;
				}
			}
			else if (h == "g")
			{
				r = r->prev;
				cout << r->data << endl;
			}
			else if (h != "c")
				cout << "yanlis tus" << endl;

		} while (h != "c");
	}
}
int main() {
	node* r = NULL;
	string b, c;


	cout << "1- Kayit ekleme:" << endl;
	cout << "2- Kayit silme:" << endl;
	cout << "3- Hafizaya aktarip gez:" << endl;
	cout << "4- Kayit arama:" << endl;

	int secim;
	cin >> secim;
	switch (secim)
	{
	case 1:
		cout << "Eklenecek deger: ";
		cin >> b;
		dosyayaekle(b);
		break;
	case 2:
		cout << "Silinecek deger: ";
		cin >> c;
		sil(c);
		break;

	case 3:
		r = dosyayioku(r);
		gezin(r);
		break;

	case 4:
		cout << "Aranacak deger: ";
		cin >> c;
		ara(c);
	default:
		break;
	}

	system("pause");

	return 0;

}