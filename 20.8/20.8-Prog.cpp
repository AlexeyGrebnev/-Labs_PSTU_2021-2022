#include <iostream>

using namespace std;

const int evNothing = 0;//пустое событие
const int evMessage = 100;//непустое событие
const int cmAdd = 1;//добавить объект в группу
const int cmDel = 2;//удалить объект из группы
const int cmGet = 3;//вывести атрибут всех объектов
const int cmShow = 4;//вывести всю группу
const int cmMake = 6;//создать группу
const int cmQuit = 101;//выход

//класс событие
struct TEvent
{
	int what;//тип события
	union
	{
		int command;//код команды
		struct
		{
			int message;
			int a;//параметр команды
		};
	};
};

class Object
{
public:
	Object();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object();
	virtual void HandleEvent(const TEvent& e) = 0;
};

Object::Object() = default; // тоже самое что и {}

Object::~Object() = default; // тоже самое что и {}

class Print : public Object
{
protected:
	string name;
	string author;
public:

	Print();//конструктор без параметров

	virtual ~Print();//деструктор

	void Show() override;//функция для просмотра атрибутов класса с полощью указателя

	void Input() override;//функция для ввода значений атрибутов

	Print(string, string);//конструктор с параметрами

	Print(const Print&);//конструктор копирования

	//геттеры
	string get_name();
	string get_author();

	//сеттеры
	void set_name(string);
	void set_author(string);

	Print& operator=(const Print&);//перегрузка операции присваивания

	virtual void HandleEvent(const TEvent& e);
};
//конструктор без параметров
Print::Print()
{
	name = "";
	author = "";
}
//деструктор
Print::~Print(){}

//конструктор с параметрами
Print::Print(string a, string b)
{
	name = a;
	author = b;
}

//конструктор копирования
Print::Print(const Print& a)
{
	name = a.name;
	author = a.author;
}

//селекторы
void Print::set_name(string newName)
{
	name = newName;
}
void Print::set_author(string newAuthor)
{
	author = newAuthor;
}

//геттеры
string Print::get_name() { return name; }
string Print::get_author() { return author; }

//оператор присваивания
Print& Print::operator=(const Print& a)
{
	if (&a == this)
	{
		return *this;
	}
	name = a.name;
	author = a.author;
	return *this;
}

//метод для просмотра атрибутов
void Print::Show()
{
	cout << "Название: " << name;
	cout << "Автор: " << author;
	cout << "\n";
}

//метод для ввода значений атрибутов
void Print::Input()
{
	cout << "\nНазвание: ";cin >> name;
	cout << "\nАвтор: ";cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:
			cout << "name=" << get_name() << endl;
			break;
		}
	}
}


class Magazin:public Print
{
protected:
	int sizebook;
public:
	Magazin();
	~Magazin() override;
	void Show() override;
	void Input() override;

	Magazin(string, string, int);
	Magazin(const Magazin&);
	int get_size();
	void set_size(int);
	Magazin& operator=(const Magazin&);
};

//без параметров
Magazin::Magazin() : Print()
{
	sizebook = 0;
}
//деструктор
Magazin::~Magazin(){}
//с параметрами
Magazin::Magazin(string a, string b, int c) : Print(a, b)
{
	sizebook = c;
}
//копирование
Magazin::Magazin(const Magazin& a)
{
	name = a.name;
	author = a.author;
	sizebook = a.sizebook;
}
//Сеттер
void Magazin::set_size(int newSize)
{
	sizebook = newSize;
}
//Геттер
int Magazin :: get_size() 
{ 
	return sizebook; 
}
//оператор присваивания
Magazin& Magazin::operator=(const Magazin& a)
{
	if (&a == this)
	{
		return *this;
	}
	name = a.name;
	author = a.author;
	sizebook = a.sizebook;
	return *this;
}
//метод для просмотра атрибутов
void Magazin::Show()
{
	cout << "Название: " << name;
	cout << "Автор: " << author;
	cout << "Размер по стр: " << sizebook;
	cout << "\n";
}
//метод для ввода значений атрибутов
void Magazin::Input()
{
	cout << "\nНазвание: "; cin >> name;
	cout << "\nАвтор: "; cin >> author;
	cout << "\nРазмер по стр: "; cin >> sizebook;
}

class List:public Magazin
{
protected:
	Object** beg;//указатель на первый элемент List
	int size;//размер
	int cur;//текущая позиция
public:
	List();
	List(int);
	List(const List&);
	~List();
	void Add();
	void Delete();
	void Show();
	int operator()();
	virtual void HandleEvent(const TEvent& e);
};
//конструктор без параметров
List :: List()
{
	beg = 0;
	size = 0;
	cur = 0;
}
//конструктор копирования
List::List(const List& a)
{
	beg = a.beg;
	size = a.size;
	cur = a.cur;
}
//деструктор
List::~List()
{
	if (beg != 0)
	{
		delete[] beg;
	}
	beg = 0;
}
//конструктор с параметрами
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор
void List::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl << "Enter comand.num(y): " << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Print
	{
		Print* a = new (Print);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2)//добавление объекта класса Magazin
		{
			Magazin* b = new (Magazin);
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else { return; }
}
//просмотр List
void List::Show()
{
	if (cur == 0)
	{
		cout << "Empty" << endl;
		Object** p = beg;//указатель на указатель типа Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();//вызов метода Show() (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}
//операция, которая возвращает размер List
int List::operator()()
{
	return cur;
}
//удаление элемента из List, память не освобождается
void List::Delete()
{
	if (cur == 0)
	{
		return;//пустенький
	}
	cur--;
}
void List :: HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода(позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}



class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog();//конструктор
	virtual ~Dialog();//деструктор
	virtual void GetEvent(TEvent& event);//получить событие
	virtual int Execute();//главный цикл обработки событий
	virtual void HandleEvent(TEvent& event);//обработчик
	virtual void ClearEvent(TEvent& event);//очистить событие
	int Valid();//проверка атрибута EndState
	void EndExec();//обработка события "конец работы"
};
//конструктор
Dialog::Dialog() :List()
{
	EndState = 0;
}
//деструктор
Dialog::~Dialog(){}
//получение события
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-szqam";//строка содержит коды операции
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s; code = s[0];//первый символ команды
	if (OpInt.find(code) >= 0)//является ли символ кодом операции
	{
		event.what = evMessage;
		
		switch (code)
		{
		case 'm'://создать группу
			event.command = cmMake;
			break;
		case '+'://добавить объект в группу
			event.command = cmAdd;
			break;
		case '-'://удалить объект из группы
			event.command = cmDel;
			break;
		case 's'://вывести список
			event.command = cmShow;
			break;
		case 'z'://вывести атрибуты 1 объекта
			event.command = cmGet;
			break;
		case 'q'://выход
			event.command = cmQuit;
			break;
		}
		
		if (s.length() > 1) //выделяем параметры команды, ели они есть 
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());//преобразуем параметр в число
			event.a = A;//записываем в сообщение
		}
	}
	else
	{
		event.what = evNothing;//пустое событие
	}
}
//Главный цикл обработки событий 
int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);//получить событие
		HandleEvent(event);//обработать событие
	} 
	while (!Valid());
	return EndState;
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//пустое событие
}

int Dialog::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	else { return 1; }
}

void Dialog::EndExec()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
			size = event.a;//размер группы
			beg = new Object * [size];//выделяем память под массив указателей
			cur = 0;
			ClearEvent(event);//очищаем событие
			break;
		case cmAdd://добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Delete();//удаление
			ClearEvent(event);
			break;
		case cmShow:
			Show();//просмотр
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();//выход
			ClearEvent(event);
			break;
		default:
			HandleEvent(event);
		};
	};
}


int main()
{
	setlocale(LC_ALL, "RUS");


	Print* a = new Print;//создаём объект класса Print
	a->Input();
	Magazin* b = new Magazin;//создаём объект класса Magazin
	b->Input();

	List l(10);//создаём List
	l.Add();//добавляем объект в List (1)
	l.Add();//добавляем объект в List (2)
	l.Show();//вывод List
	l.Delete();//удаление элемента
	cout << endl  << "List size= " << l();

	cout << "Код-команды:\n";
	Dialog D;
	D.Execute();
	return 0;
}