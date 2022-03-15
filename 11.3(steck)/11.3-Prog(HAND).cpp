#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
struct Steck
{
	Node<T>* head = nullptr;
	int size = 0;
};

template <typename T>
void setNode(Node<T>& node, T data, Node<T>* next = null)
{
	node = new Node<T>;
	node->next = next;
	node->data = data;
}

template <typename T>
void pushS(Steck<T>& tmp, const T& data)
{
	Node<T>* newnode = new Node<T>;
	newnode->next = tmp.head;
	newnode->data = data;
	tmp.head = newnode;
	tmp.size++;
}

template <typename T>
void pop(Steck<T>& tmp)
{
	if (tmp.head != nullptr)
	{
		Node<T>* deleted = tmp.head;
		tmp.head = tmp.head->next;
		delete deleted;
		tmp.size--;
	}
}

template <typename T>
void printsteck(Steck<T>& tmp)
{
	Node<T>* currentnode = tmp.head;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << "   "; //Вывод стэка как метод стаканчика - каждый элемент летит "на дно" 
		currentnode = currentnode->next; //Переход на след
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int count = 1;
	cout << "Введите желаемый размер стэка: ";
	cin >> n;
	double k;
	Steck <double> st;
	Steck <double> st1;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		pushS(st, k);
	}
	cout << "Выводим стэк =>  " ;
	printsteck(st);
	cout << endl;
	int p = 1;
	for (int i = 0; i < n; i++)
	{
		if (count % 2 != 0)
		{
			pushS(st1, st.head->data);
			p++;
			cout << endl << "Изменения (шаг "<< p <<" )" << endl;
			printsteck(st1);		
		}
		pop(st);
		count++;
	}
	cout << endl <<  "Результат работы программы: ";
	printsteck(st1);
	return 0;
}