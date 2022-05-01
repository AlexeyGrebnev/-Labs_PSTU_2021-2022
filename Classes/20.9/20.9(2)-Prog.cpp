#include <iostream>
#include <string>

using namespace std;

const int max_size = 33;

class error //класс ошибка
{
private:
	string sms;
public:
	//конструктор инициализирует атрибут str смс об ошибке
	error(string s)
	{
		sms = s;
	}
	
	void what()
	{
		cout << "Произошла ошибка: " << sms << endl; //выводит значение атрибута str
	}
};


class Variety
{
private: 
	int size;
	int* data;
public:
	Variety()
	{
		size = 0;
		data = 0;
	}
	Variety(int s);
	Variety(int s, int* mas);
	Variety(const Variety& v);
	~Variety();
	const Variety& operator=(const Variety& v);//операция присваивания
	int& operator[](int i);
	int& operator()();
	Variety operator--();//удаление элемента
	Variety operator-(const Variety& a);
	//void ShowVariety();
	Variety(int size, int* mas);
	friend ostream& operator<<(ostream& out, const Variety& v);
	friend istream& operator>>(istream& in, Variety& v);
};

Variety::Variety(int s)
{
	if (s > max_size) throw error("Длина множества заходит за границы значения Max_Size!");
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 96;
	}
}

Variety::Variety(const Variety& v)
{
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
}

Variety::~Variety()
{
	if (data != 0) delete[] data;
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


int& Variety::operator[](int i)
{
	if (i < 0) throw error("Заданный индекс меньше нуля! ");
	if (i >= size) throw error("Заданный индекс больше границы размера! ");
	return data[i];
}

Variety Variety :: operator-(const Variety& a) //-a
{
	if (size != a.size)
	{
		throw error("Ошибка в несоответствии кол-ва элементов для разности двух множеств!");
	}
	Variety tmp(size);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i] - a.data[i];
	}
	delete[] data;
	return tmp;
}

Variety Variety::operator--()
{
	if (size == 0)//если элементов вообще нет 
	{
		error("Нечего удалять, так как множество нулевое!");
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

istream& operator>>(istream& in, Variety&v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.data[i];
	}
	return in;
}

int main ()
{
	setlocale(LC_ALL,"RUS");
	/*
	const int max_size = 33;

	Действия: 
		[]-доступ по индексу
		()-определение размера множества
		- -разность множеств
		-- -удаление элемента
	*/
	try
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
	catch(error e)
	{
		e.what();
	}
}