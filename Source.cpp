#include <iostream>
using namespace std;

struct Elem
{
	int data;
	Elem* next;
	Elem* prev;
};
template <class T>
class Kucha
{
	Elem* Head;
	Elem* Tail;
	int Count;
public:
	Kucha <T>();
	Kucha <T>(T amount);
	~Kucha <T>();
	void DelAll();
	void Del(int adress);
	void Add(T n);
	void Show();
	void Extract();
	int GetCount();

};
template<class T>
Kucha<T>::Kucha()
{
	Head = Tail = NULL;
	Count = 0;
}
template<class T>
Kucha<T>::Kucha(T amount)
{
	Head = Tail = NULL;
	Count = amount;
}
template<class T>
Kucha<T>::~Kucha()
{
	DelAll();
}
template<class T>
int Kucha<T>::GetCount()
{
	return Count;
}
template<class T>
void Kucha<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}
template<class T>
void Kucha<T>::Del(int adress)
{
	if (adress == 0)
	{
		cout << "Input Adress: ";
		cin >> adress;
	}
	if (adress < 1 || adress > Count)
	{
		cout << "Error Adress" << endl;
		return;
	}
	int i = 1;

	Elem* Del = Head;

	while (i < adress)
	{
		Del = Del->next;
		i++;
	}
	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;
	delete Del;

	Count--;
}
template<class T>
void Kucha<T>::Add(T n)
{
	Elem* temp = new Elem;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;

	if (Head != 0) {
		Head->prev = temp;
	}
	if (Count == 0) {
		Head = Tail = temp;
	}
	else {
		Head = temp;
	}
}
template<class T>
void Kucha<T>::Show()
{
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "first element->( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}
template<class T>
void Kucha<T>::Extract()
{
	Del(1);
}
int main() {
	srand(time(0));
	int size = 7;
	Kucha<int> QU(size);
	for (int i = 0; i < size; i++) {
		QU.Add(rand() % 100);
	}
	do {
		QU.Show();
		QU.Extract();
		if (QU.GetCount() == 0) {
			cout << "there is no kucha!" << endl;
		}
	} while (QU.GetCount() > 0);


}