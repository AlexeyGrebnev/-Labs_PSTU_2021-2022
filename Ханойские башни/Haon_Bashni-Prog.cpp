#include <iostream>

using namespace std;

void move_step(char point1, char point2)//Функция передвигает один диск
{
	cout << "со стержня " << point1 << " на стержень " << point2 << endl; //Показ шагов переноса диска 
}

void moving_step(int num, char point1, char point2, char point3) //Функция передвигает всю башню - point3 (вспомогат.стержень)
{
	if (num != 0) //Условие выхода из функции 
	{
		moving_step(num - 1, point1, point3, point2);//Из стержня 1 на стержень 3
		move_step(point1, point2);//Переносим диск с 1 на 2 
		moving_step(num - 1, point3, point2, point1);//Переносим "обратно" с 3 на 2 к одному диску, который перевели в move_step
	}
}

int main()

{
	setlocale(LC_ALL, "rus");
	int num;
	cout << "Введите количество колец: " << endl;
	cin >> num;
	moving_step(num, 'A', 'B', 'C'); //Кол-во колец, 1 стержень , 2 стержень, 3 стержень
	return 0;

}