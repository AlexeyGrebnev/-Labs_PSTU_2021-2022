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
    int index;
    index = KMP_search(str, templ);
    if (KMP_search(str, templ) != -1)
    {
        cout << "Заданный образец в строке находится под индексом => " << index << " !" << endl;
    }
    else
        cout << "Заданный образец не найден в строке! " << endl;
    int strlen = str.size();
    int k = strlen;
    string newstr;
    string tmp1str;
    string tmp2str;

    do
    {
        cout << "Введите строчку длиной " << k << " для замены найденной подстроки ранее ";
        cin >> newstr;
    } while (newstr.size() != k); //Введите строчку длиной k
    tmp1str = str;


    for (int i=0; i <= strlen + k - index - 1; i++)
    {
        tmp1str[i] = ' ';
    }
    int i = 0;
    while (i != index)
    {
        tmp1str[i] = str[i];
        i++;
    }
    int j = 0;
    /*for (i = index; i <= tmp1str.size(); i++)
    {
        //str.size() + k - index - 1
        tmp1str[i] = newstr[j];
        j++;
    }*/
    cout << tmp1str;
}