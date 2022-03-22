#include <iostream>
#include <string>
using namespace std;

int KMP_search(string str, string templ)
{
    int i, j, strlen, templlen;

    strlen = str.size();
    templlen = templ.size();
    int* d = new int[templlen];
    //Вычисление префикс-функции
    i = 0;
    j = -1;
    d[0] = -1;
    while (i < templlen - 1)
    {
        while ((j >= 0) && (templ[j] != templ[i]))
        {
            j = d[j];
        }
        ++i;
        ++j;
        if (templ[i] == templ[j])
        {
            d[i] = d[j];
        }
        else
        {
            d[i] = j;
        }
    }
    
    //Поиск строки 
    for (i = 0, j = 0; (i <= strlen - 1) && (j <= templlen - 1); i++, j++)
    {
        while ((j >= 0) && (templ[j] != str[i]))
        {
            j = d[j];
        }
    }
    delete[] d;
    //Если совпадения есть, то возвращаем позицию
    //Если нет, вывод -1 
    if (j == templlen)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    string str, templ;
    cout << "Введите строку, в которой будем искать: ";
    cin >> str;
    cout << "Введите образец того, что мы должны найти: ";
    cin >> templ;
    int strlen = str.size();
    int k = templ.size();
    string newstr;
    string tmp2str;
    int index;
    int j = 0;
    index = KMP_search(str, templ);
    int pos = index + k;
    if (KMP_search(str, templ) != -1)
    {
        cout << "Заданный образец в строке находится под индексом => " << index << " !" << endl;
        for(int i=pos; i<pos+k; i++)
        {
            tmp2str[j] = str[i];
            j++;
        }
        newstr=str;
        for (int i = index; i < strlen; i++)
        {
            newstr[i] = str[pos];
            pos++;
        }
    }
    else
        cout << "Заданный образец не найден в строке! " << endl;

    cout << "Изменённая строка (newstr): " << endl;
    for(int i = 0; i < strlen; i++)
    {
        cout << newstr[i] << "  ";
    }
}