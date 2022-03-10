#include <iostream>

using namespace std;

struct Node //Реализация узла 
{
	double data;
	Node* ptr_next = nullptr;
};

struct List //Реализация списка 
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

void pushBack(List& list, int& data) //Функция заполнения списка
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.head == nullptr)
	{
		list.head = newnode;
		list.tail = newnode;
	}
	else
	{
		list.tail->ptr_next = newnode;
		list.tail = newnode;
	}
}

void printList(List& list) //Функция вывода списка
{
	Node* currentnode = list.head;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

void changeList(List& list) //Изменение списка (Удаление чётных номеров элементов) 
{
	Node* currentnode = list.head;
	Node* prednode = list.head;
	int count = 1;
	while (currentnode != nullptr)
	{
		if (count % 2 == 0)
		{
			prednode->ptr_next = currentnode->ptr_next;
			prednode = currentnode->ptr_next;
		}
		currentnode = currentnode->ptr_next;
		count++;
	}

}

int main()
{
	setlocale(LC_ALL, "RUS");
	List list; //Объявление списка
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	cout << "Введите значения для списка" << " ";
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		pushBack(list, k); //Вносим значения в список
	}
	cout << "First LIST"<< " ";
	printList(list); //Вывод списка
	changeList(list);//Изменение списка 
	cout << endl;
	cout << "Final LIST" << " ";
	printList(list); 
	return 0;
}