#include <iostream>
using namespace std;

void ShellSort(int* arr, int n) //Сортировка Шелла
{
    int tmp = 0;
    int d;
    int j;
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                tmp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = tmp;
                j--;
            }
        }
        d = d / 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; //вывод массива
    }
}
int main()
{
    int const n = 10;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 14;
    }
    cout << "Sort MASSive: ";
    ShellSort(arr, n);
    delete[] arr;
}

