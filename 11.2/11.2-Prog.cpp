#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* ptr_prev = nullptr;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;
};

void push(List& list, char& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
		return;
	}
	Node* currentnode = list.headnode;
	newnode->ptr_prev = currentnode;
	if (currentnode->ptr_next != nullptr)
	{
		newnode->ptr_next = currentnode->ptr_next;
		currentnode->ptr_next->ptr_prev = newnode;
	}
	currentnode->ptr_next = newnode;
	list.tailnode = newnode;
}

void printList(List& list)
{
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

void add(List& list, char& value, char& add_value)
{
	Node* newnode = new Node;
	newnode->data = add_value;
	Node* currentnode;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
		return;
	}
	for (currentnode = list.headnode; currentnode->data != value; currentnode = currentnode->ptr_next);
	newnode->ptr_next = currentnode->ptr_next;
	currentnode->ptr_next = newnode;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	List list;
	int n;
	int index = 3;
	char tmp;
	cout << "Введите размер списка: ";
	cin >> n;
	cout << "Введите элементы двусвязного списка: ";
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		push(list, tmp);
	}
	cout << "Изначальный список" << endl;
	printList(list);
	cout << endl;
	char sl;
	cout << "Введите элемент после которого мы должны добавить новый: ";
	cin >> sl;
	char newsl;
	cout << "Введите добавляемый элемент: ";
	cin >> newsl;
	add(list, sl, newsl);
	cout << "Финальный список" << endl;
	printList(list);
	return 0;
}