#include <iostream>
#include <ctime>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
};
node* ilknode(node* r, int x) {
	//bos node olusturmak istediðimizde kullanýlacak node.
	r = new node;
	r->data = x;
	r->next = r;
	r->prev = r;
	return r;
}
node* basaekle(node* r, int x) {
	//basa eklemek istedigimizde calisacak fonksiyon
	if (r == NULL)
	{
		r = ilknode(r, x);
		return r;
	}
	else
	{
		node* tmp = NULL;
		tmp = ilknode(tmp, x);
		tmp->next = r;
		tmp->prev = r->prev;
		r->prev = tmp;
		tmp->prev->next = tmp;
		r = tmp;
		return r;
	}
}
node* ekle(node* r, int x) {
	if (r == NULL)//liste bos ise yeni node olusturup liste baslatir
	{
		r = ilknode(r, x);
		return r;
	}

	else
	{
		if (x < r->data)//gelen deger root'dan kucukse basa eklemek
		{
			r = basaekle(r, x);
			return r;
		}
		else
		{
			node* yrd;
			yrd = r;
			while (yrd->next->data < x && yrd->next != r)  //gelen deger, yardimcinin gosterdigi 
				yrd = yrd->next;						   //yerden kucuk olana kadar veya sona gelene kadar yardimciyi tasi
			node* tmp;
			tmp = new node;
			tmp->data = x;
			tmp->next = yrd->next;
			yrd->next->prev = tmp;
			tmp->prev = yrd;
			//node ekleme islemleri..
			yrd->next = tmp;
			yrd = NULL;
			tmp = NULL;
			delete yrd, tmp;



		}
		return r;
	}


}
void yazdir(node* r) {
	node* yrd;
	yrd = r;
	if (r == NULL)
		cout << "liste bos";
	else
	{

		do {
			cout << yrd->data << " ";
			yrd = yrd->next;
		} while (yrd->next != r);//sona gelene kadar her degeri yaz

		cout << yrd->data << " ";
	}
}
int main()
{
	srand(time(NULL));
	node* root;
	root = NULL;
	for (int i = 0; i < 6; i++)//rastgele sayi uretip listeye ekliyor
	{
		int r = rand() % 100 + 1;
		root = ekle(root, r);

	}
	yazdir(root);
	system("pause");
}