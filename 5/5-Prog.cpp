#include <iostream>
using namespace std;
int main()
{ 
    //Заводим двумерный массив
    setlocale(LC_ALL, "rus");
    cout << "Двумерный массив - ЗАПОЛНЕН!" << endl;
    int** a;
    int rows = 5;
    int cons = 5;
    a = new int* [rows]; // указатели на 5 строк
    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[cons]; // 10 столбцов
        for (int j = 0; j < cons; j++)
            a[i][j] = (rand() % 101) - 50;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cons; j++)
            cout << a[i][j] << " ";
    }
    cout << endl << endl;
 //Появление нулей вместо строк с отрицательными элементами//
    cout << "Двумерный массив - ИЗМЕНЁН!" << endl;
    for (int i = 0; i < rows; i++)
    {
        int k = i;
        for (int j = 0; j < cons; j++)
        {
            if (a[i][j] < 0)
            {
                for (int i = k; i < k+1; i++)
                {
                    for (int j = 0; j < cons; j++)
                    {
                        a[i][j] = 0;
                    }
                }
                
            }
        }
    }
//**********************************//

//Перенос строчек из нулей в конец//
    int count = 0;
    int** tmp;
    tmp = new int* [rows - 1];
    int n = 0;
    for (int i = 0; i < rows; i++)
    {       
            if (a[i][1] > 0)
            {
                tmp[i] = a[n];
                a[n] = a[i];
                a[i] = tmp[i];
                n++;
            }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cons; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}