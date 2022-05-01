#include <iostream>

using namespace std;

const int max_size = 33;

class Variety
{
private:
	int size;
	int* data;
public:
	Variety();
	Variety(int size);
	//Variety(int s, int* mas);
	Variety(const Variety& v);
	const Variety& operator=(const Variety& v);//операция присваивания
	int& operator[](int i);
	int& operator()();
	Variety operator--();//удаление элемента
	Variety operator-(const Variety& a);
	//void ShowVariety();
	friend ostream& operator<<(ostream& out, const Variety& v);
	friend istream& operator>>(istream& in, Variety& v);
	~Variety();
};


Variety::Variety()
{
	size = 0;
	data = 0;
}

Variety::Variety(int size)
{
	if (size > max_size){throw 1;}
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 96;
	}
}

/*Variety::Variety(int s, int* mas)
{
	if (s > max_size) throw error("Длина множества заходит за границы значения Max_Size!");
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = mas[i];
	}
}*/

Variety :: Variety(const Variety& v) 
{
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
}

/*const Variety& Variety::operator=(const Variety& v)
{
	if (this == &v)
	{
		return *this;
	}
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
	return *this;
}

void Variety :: ShowVariety()
{
	cout << "Variety: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << data[i] << " ";
	}
	cout << endl;
}*/


int& Variety :: operator[](int num)
{
	if (num < size && num >= 0)
	{
		return data[num];
	}

	else
	{
		throw 2;
	}
}

Variety Variety :: operator-(const Variety& a) //-a
{
	if (size != a.size)
	{
		throw 3;
	}
	Variety tmp(size);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i] - a.data[i];
	}
	delete[] data;
	return tmp;
}
int& Variety :: operator()()
{
	return size;
}

Variety Variety::operator--()
{
	if (size == 0)//если элементов вообще нет 
	{
		throw 4;
	}
	if (size == 1)//если в вектор один элемент
	{
		size = 0;
		delete[] data;
		data = 0;
		return *this;
	};
	int tmp_size = size--;
	Variety tmp(tmp_size);
	for (int i = 0; i < tmp_size; i++)
	{
		tmp.data[i] = data[i];
	}
	delete [] data;
	return tmp;
}

Variety :: ~Variety()
{
	if (data != 0)
	{
		delete[] data;
	}
}

ostream& operator<<(ostream& out, const Variety& v)
{
	if (v.size == 0)
	{
		out << "Variety: NONE";
	}
	else
	{
		cout << "Variety: ";
		for (int i = 0; i < v.size; i++)
		{
			out << v.data[i] << " ";
		}
		return out;
	}
}


istream& operator>>(istream& in, Variety& v)
{
	for (int i = 0; i < v.size; i++)
	{
		in >> v.data[i];
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	/*
	const int max_size = 33;

	Действия: 
		[]-доступ по индексу
		()-определение размера множества
		- -разность множеств
		-- -удаление элемента
	*/

	try //контролирующий блок
	{
		Variety f(35);//Производит ошибку выхода size за Max_Size
		cout << f;

		Variety a(5);
		cout << a;
		a[3];//Производит ошибку выхода поиска поиндексу за максимально возможный 

		Variety c(4);
		cout << c;

		Variety d = a - c;
		cout << d;//Производит ошибку в разности множеств

		Variety b(3);//пустое множество
		cout << b;
		--b;
		--b;
		--b;//Производит ошибку удаления элемента 

	}
	catch (int n)
	{
		cout << "Номер ошибки: " << n << "....... " << endl << endl;
		switch (n)
		{
		case 1:
			cout << "Ошибка из-за выхода за границы MAX_SIZE" << endl;
			break;
		case 2:
			cout << "Ошибка действия доступа по индексу" << endl;
			break;
		case 3:
			cout << "Ошибка в разности двух множеств" << endl;
		case 4:
			cout << "Ошибка действия по удалению элемента" << endl;
			break;
		}
	}
	return 0;
}