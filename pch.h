// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


#ifndef PCH_H
#define PCH_H
#include <fstream>
using namespace std;
class transport {
private:
	int spead;
	int distance;
public:
	static transport* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0; // вывод
	void OutCommon(ofstream &ofst);
	//мультиметоды
	virtual void MultiMethod(transport *other, ofstream &ofst) = 0;
	virtual void MMplane(ofstream &ofst) = 0;
	virtual void MMtraine(ofstream &ofst) = 0;
};
class container
{
private:
	class Node {		
	public:
		Node();
		Node* Next;
		Node* Prev;
		transport* data;
	};
	Node* Top;
	int count;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	void MultiMethod(ofstream &ofst);
	container(); // инициализация контейнера
	~container() { Clear(); }
};


class plane : public transport {
	int range;
	int c;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	plane() {} // создание без инициализации.
	//мультиметоды
	void MultiMethod(transport *other, ofstream &ofst);
	void MMplane(ofstream &ofst);
	void MMtraine(ofstream &ofst);
};
class traine : public transport {
	int count;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	traine() {} // создание без инициализации.
	//мультиметоды
	void MultiMethod(transport *other, ofstream &ofst);
	void MMplane(ofstream &ofst);
	void MMtraine(ofstream &ofst);
};

// TODO: add headers that you want to pre-compile here

#endif //PCH_H
