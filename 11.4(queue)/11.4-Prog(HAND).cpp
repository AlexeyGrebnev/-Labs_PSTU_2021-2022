#include <iostream>

using namespace std;

template <typename T>
struct Node                     //T - тип данных
{
	T data; //данные
	Node<T>* next; //указатель на следующий элемент
};

template <typename T>
struct Queue
{
	int size = 0; //размер
	Node<T>* head = nullptr; // указатель на голову
	Node<T>* tail = nullptr; //указатель на хвост
};

template <typename T>                   //T - тип данных
void new_queue(Queue<T>& q, const int& n)
{
	T a;
	cout << "Задайте " << n << " элементов для очереди ";
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		push(q, a); //Функция элемент и вставляем в конец очереди  (q-куда, a-что )
	}
}

template <typename T>
void push(Queue<T>& q, const T& value)
{
	if (q.head != nullptr) //если очередь не пуста
	{
		Node<T>* new_node = new Node<T>; //Резервируем память под новый элемент
		q.size++; //Увеличиваем размер очереди на 1
		new_node->data = value; //в поле ключа присваиваем передаваемое значение
		new_node->next = nullptr; //Последний элемент ни на что не указывает
		q.tail->next = new_node; //предпоследний элемент указывает на последний
		q.tail = new_node; //указатель на последний элемент теперь указывает на новый
	}
	else
	{
		Node<T>* new_node = new Node<T>; //резервируем память под первый элемент
		new_node->data = value; //в поле ключа присваиваем передаваемое значение
		q.head = new_node;
		q.tail = new_node;
		q.size = 1;
	}
}

template <typename T>
void pop(Queue<T>& q)
{
	Node<T>* tmp = q.head;
	q.head = q.head->next;
	q.size--;
	delete tmp;
}

template <typename T>
void print(Queue<T>& q)
{
	Node<T>* tmp = q.head;
	while (tmp != nullptr)
	{
		cout << tmp->data;
		tmp = tmp->next;
	}
}



template <typename T>
void insert(Queue<T>&q, const int& index)
{
	const int count=1;
	int i = 1;
	while (i < index+1) //пока не дойдём до нужного элемента
	{
		push(q, q.head->data);
		pop(q); //переставляем элементы с головы в хвост
		i++;
	}
	T a;
	cout << "Введите элемент для добавления: ";
	for (int j = 0; j < count; j++)
	{
		cin >> a;
		push(q, a); //добавляем count новых элементов
	}
	for (i; i <= q.size - count; i++)//чтобы первый элемент оказался на своём месте
	{
		push(q, q.head->data);
		pop(q);//переставляем элементы с головы в хвост
	}
}

template <typename T>
void deleteQ(Queue<T>& q)
{
	while (q.head != nullptr)
	{
		pop(q);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int index = 3;
	cout << "Введите размер очереди: ";
	cin >> n;
	cout << endl;
	Queue<char> q;
	new_queue(q, n);
	cout << endl;
	cout << "Введите номер элемента, после которого мы добавим новый элемент: ";
	cin >> index;
	cout << endl;
	insert(q, index);
	cout << endl;
	print(q);
	deleteQ(q);
	return 0;
}