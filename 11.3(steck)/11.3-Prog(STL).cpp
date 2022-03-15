#include <iostream> 
#include <stack> //ПРАВИЛЬНО НАПИСАНИЕ СТЭКА - stack, а не steck!!!

using namespace std;

void printstack(stack<double> st)
{
	int num = st.size();
	for (int i = 0; i < num; i++)
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	double k;
	cout << "Введите желаемый размер стэка: ";
	cin >> n;
	stack<double> st;
    stack<double> st1;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		st.push(k);
	}
	printstack(st);
	cout << endl;
	int count = 1;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (count % 2 != 0)
		{
			st1.push(st.top());
			p++;
			cout << endl << "Изменения (шаг " << p << " )" << endl;
			printstack(st1);
		}
		st.pop();
		count++;
	}
	int new_num = st1.size(); //Берём новый размер для изменённого стэка 
	cout << endl << "Финальный вывод стэка после изменений =>  ";
	for (int i = 0; i < new_num; i++)
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	return 0;
}