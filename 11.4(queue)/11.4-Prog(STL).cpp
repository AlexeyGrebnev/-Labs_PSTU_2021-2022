#include <iostream>
#include <queue>

using namespace std;

void print(queue<char> q)
{
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		cout << q.front();
		q.pop();
	}
}

template <typename T>
void change(Queue<T>& q, const int& index)
{
	int count = 1;
	int i = 1;
	while (i < index + 1) //пока не дойдём до нужного элемента
	{
		q.push(q.front());
		q.pop(); 
		i++;
	}
	char a;
	cout << "Введите элемент для добавления: ";
	for (int j = 0; j < count; j++)
	{
		cin >> a;
		q.push(a); //добавляем count новых элементов
	}
	for (i; i <= q.size - count; i++)//чтобы первый элемент оказался на своём месте
	{
		q.push(q.front());
		q.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	char a;
	int index;
	cout << "Введите размер очереди: ";
	cin >> n;
	queue<char> qu;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		qu.push(a);
	}
	print(qu);
	cout << endl;
	cout << "Введите номер элемента, после которого мы добавим новый элемент: ";
	cin >> index;
	cout << endl;
	change(q, index);
	cout << endl;
	print(q);
    return 0;
}