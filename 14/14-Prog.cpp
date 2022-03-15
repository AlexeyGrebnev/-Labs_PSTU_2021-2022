#include<iostream>

using namespace std;

int Line_search(char* arr, int size, int key) //Возьмём за ю - АНГЛИЙСКУЮ u, т.к с русскими буквами не работает
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; // Проходом по шагу в единицу мы ищем элемент множества равный заданному key и получаем индекс элемента 
        }
    }
    return -1; //Если не найдём - выводим -1 !
}

bool destroy(char* arr, int size, int index)
{
    if (index < 0 || index > size)
        return false;

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return true;
}

void inprint(char* arr, int n)
{
    cout << "Заданное множество: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void outprint(char* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер множества: ";
    cin >> n;
    char* arr = new char[n];
    cout << "Введите строчку букв через пробел  =>   ";
    inprint(arr, n);
    char key = 'u';
    cout << endl << "Ищем в множестве букву Ю " << endl;
    int index;
    index = Line_search(arr, n, key);
    int k = n - 1;
    char* arr_tmp = new char[k];
    int j = 0;
    if (index == -1)
    {
        cout << "В множестве отсутствует данное число!" << endl;
    }
    else
    {
        cout << " Получили индекс искомой буквы " << endl << endl;
        cout << "  => " << index << " <=  ";
      
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 'u')
            {
                arr_tmp[j] = arr[i];
                j++;
            }
        }
    }
    
    cout << "Изменённое множество: ";
    outprint(arr_tmp, k);
}
