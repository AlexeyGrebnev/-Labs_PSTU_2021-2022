//Проход с начала и с конца массива xleft > middle xright < middle 
//4 18 9 0 90 8 (15) 88 9 7 18 1 22

#include <stdio.h>
#include <iostream>

using namespace std;

void QS(int* s_arr, int first, int last);

int main()
{
    const int size = 6;
    int arr[size] = { 2,54,10,3,6,1 };
    printf("NO-SortArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    QS(arr, 0, size - 1);//Задаём массив левый и правые индексы, соответственно 
    cout << endl;
    printf("SortArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void QS(int* s_arr, int first, int last) //Указатель на массив, Индекс первого и Индекс последнего 
{
    if (first < last)
    {
        int left = first; //0
        int right = last; //12
        int middle = s_arr[(left + right) / 2]; // 15
        while (left < right)//Проверка
        {
            while (s_arr[left] < middle)//Нахождение "предателя", который должен надожится в другой части сортировки
            {
                left++;//сдвиг вправо
            }
            while (s_arr[right] > middle)//Нахождение "предателя", который должен надожится в другой части сортировки
            {
                right--;//сдвиг влево
            }
            if (left <= right)//Проверка, чтобы наши "концы не столкнулись"
            {
                int tmp = s_arr[left];//Перемещег=ние через временный 
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;//Идём дальше после перестановки
                right--;//Идём дальше после перестановки 
            }
        }
        QS(s_arr, first, right); //бахаем рекурсию
        QS(s_arr, left, right);
    }
    return;
}