#include <iostream>

using namespace std;

template <class T>
class Variety
{
private:
	int size;
	T* data;

public:

	Variety(T size)
	{
		this->size = size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 96;
		}
	}

	void ShowVariety()
	{
		cout << "Variety: ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << data[i] << " ";
		}
	}


	int& operator[](int num)
	{
		if (num < size && num >= 0)
		{
			return data[num];
		}

		else
		{
			cout << endl << "*******************" << endl << "Ошибка" << endl << "*******************" << endl;
		}
	}

	Variety operator-(const Variety& a) //-a
	{
		Variety<T> temp(size);

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i] - a.data[i];
		}
		delete[] data;
		return temp;
	}
	int& operator() ()
	{
		return size;
	}

	~Variety()
	{

	}
};

class Money
{
private:
	long rub;
	int cop;

public:
	Money();
	Money(long, int);
	~Money();
	Money operator-(const Money& a);
	Money& operator=(const Money& a);
	void ShowMoney()
	{
		cout << "Money: " << rub << ", " << cop << ";" << endl;
	}
};
Money::Money()
{
	rub = 0;
	cop = 0;
}

Money::Money(long rub, int cop)
{
	this->rub = rub;
	this->cop = cop;
}

Money Money::operator-(const Money& a)
{
	Money tmp(rub, cop);
	tmp.rub = this->rub - a.rub;
	tmp.cop = this->cop - a.cop;
	while (tmp.cop >= 100)
	{
		tmp.cop = tmp.cop - 100;
		++tmp.rub;
	}
	return tmp;
}

Money& Money :: operator=(const Money& a)
{
	this->rub = a.rub;
	this->cop = a.cop;
	return *this;
}

Money::~Money()
{

}



int main()
{
	setlocale(LC_ALL, "RUS");
	int size;
	int index;
	cout << "Задайте размер(size): ";
	cin >> size;

	Variety<int> a(size);
	cout << "class Variety a: ";

	a.ShowVariety();

	cout << endl << "Определение размера множества a: " << a() << endl;

	cout << endl << "Задайте индекс(index) для поиска: ";
	cin >> index;
	if (index >= 0 && index < size)
	{
		cout << "Доступ по заданному индексу: " << a[index] << endl;
	}
	else
	{
		cout << endl << "Доступ по заданному индексу невозможен!" << endl;
	}

	Variety<int> b(size);
	cout << "class Variety b: ";

	b.ShowVariety();

	Variety<int>c(size);
	cout << "class Variety c: ";
	c = a - b;
	c.ShowVariety();

	cout << "**********************************************************************" << endl << endl;

	Money A(543, 23);
	cout << "Первый 'Money': ";
	A.ShowMoney();

	Money B(542, 22);
	cout << "Второй 'Money': ";
	B.ShowMoney();

	Money С(52, 66);
	cout << "Третий 'Money': ";
	С.ShowMoney();

	cout << "Проведём операцию 'разность'" << endl;
	С = A - B;
	С.ShowMoney();
}