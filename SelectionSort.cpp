#include <iostream>
#include <ctime>
using namespace std;
void diziolustur(int dizi[], int boyut) {
	srand(time(NULL));
	int random;
	for (int i = 0; i < boyut; i++)
	{
		random = rand() % boyut;
		dizi[i] = random;
	}
	return;
}
int selection(int dizi[], int eleman) {

	for (int i = 0; i < eleman; i++)
	{
		int sira_no = i;
		for (int j = i + 1; j < eleman; j++)
		{
			if (dizi[j] < dizi[sira_no])
			{
				sira_no = j;
			}
		}
		int gecici = dizi[i];
		dizi[i] = dizi[sira_no];
		dizi[sira_no] = gecici;
		//cout << dizi[i] << endl;
	}
	return 0;
}

int main()
{
	clock_t t;

	int dizi1[5000], dizi2[10000], dizi3[15000];
	diziolustur(dizi1, 5000);
	diziolustur(dizi2, 10000);
	diziolustur(dizi3, 15000);
	t = clock();
	selection(dizi1, 5000);
	t = clock() - t;
	cout << "5K lik Dizinin siralanma zamanlamasi :";
	cout << (float)t / CLOCKS_PER_SEC << endl;
	t = clock();
	selection(dizi2, 10000);
	t = clock() - t;
	cout << "10K lik Dizinin siralanma zamanlamasi :";
	cout << (float)t / CLOCKS_PER_SEC << endl;
	t = clock();
	selection(dizi3, 15000);
	t = clock() - t;
	cout << "15K lik Dizinin siralanma zamanlamasi :";
	cout << (float)t / CLOCKS_PER_SEC << endl;
	system("pause");
}