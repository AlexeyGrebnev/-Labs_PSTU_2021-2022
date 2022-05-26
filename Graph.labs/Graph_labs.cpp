#include <iostream>
#include <cmath>
const int SIZE = 6;
using namespace std;

void print_matr(int a[6][6])
{
	cout << "Матрица смежности: " << endl;
	// Вывод матрицу смежности
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	// Матрица смежности
	int a[SIZE][SIZE] = { 
		{0,  7, 14, 33,  5, 12},
		{7,  0, 19, 23,  3,  0},
		{14,19,  0,  2, 15,  0},
		{33,23,  2,  0, 28,  9},
		{5,  3, 15, 28,  0, 0},
		{12, 0,  0,  9, 0,  0} };
	int min_dist[SIZE]; // массив минимального расстояния
	int visit[SIZE]; // визит в веришины
	int tmp;
	int min_index, min;
	int begin_index = 5;//идём от 6-ой вершины

	print_matr(a);

	//Предварительное создание вершин и веса рёбер
	for (int i = 0; i < SIZE; i++)
	{
		min_dist[i] = INT_MAX;
		visit[i] = 1;
	}
	min_dist[begin_index] = 0;
	do {
		min_index = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < SIZE; i++)
		{ 
			if ((visit[i] == 1) && (min_dist[i] < min))// Если вершину ещё не посещали и вес меньше min
			{
				min = min_dist[i]; // Переприсваиваем значение
				min_index = i; // Переприсваиваем значение
			}
		}

		if (min_index != INT_MAX)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[min_index][i] > 0)
				{
					tmp = min + a[min_index][i];// Добавляем найденный минимальный вес к текущему весу вершины
					if (tmp < min_dist[i])//Сравниваем с текущим минимальным весом вершины
					{
						min_dist[i] = tmp;
					}
				}
			}
			visit[min_index] = 0;
		}
	} while (min_index < INT_MAX);
	// Вывод кратчайших расстояний до вершин
	cout << endl << "Кратчайшие расстояния от 6-ой вершины до вершин остальных: " << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		cout << " 6 -> " << i + 1 << " = " << min_dist[i] << endl;
	}
}