#include <iostream>
#include "Money.h"
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<Money> Tvector;
Money s;

struct Greater_s
{
    bool operator()(Money m)
    {
        if(m>s) {return true;}
        else {return false;}
    }
};

Tvector make_vector(int n)
{
    Money a;
    Tvector v;
    for(int i = 0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
}

void print_vector(Tvector v)
{
    for (int i = 0; i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

Money srednee(Tvector v)
{
    Money m = v[0];
    //перебор вектора
    for(int i = 1; i < v.size(); i++)
    {
        m=m+v[i];
    }
    int n = v.size();//кол-во элементов в векторе
    return m/n;
}

struct Comp_less //предикат для сортировки по убыванию (т.е его изменения)
{
    public:
        bool operator()(Money m1,Money m2)
        {
            if (m1 > m2) return true;
            else return false;
        }
};

struct Equal_s//предикат для поиска заданного значения
{
    bool operator() (Money m)
    {
        return m == s;
    }
};

void del(Money& m)
{
    m = m / s;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    Tvector v;
    v = make_vector(n);
    print_vector(v);

    Tvector :: iterator i;
    //поставим итератор на макс элемент
    i = max_element(v.begin(),v.end());
    cout << "max= " << *(i) << endl;
    Money k = *(i);

    s = srednee(v);//нашли сред арифм вектора
    cout << "srednee vect= "<<s<<endl;

    //замена с использованием предиката
    replace_if(v.begin(),v.end(),Greater_s(),k);
    cout << "Zamena: " << endl;
    print_vector(v);

    cout << "Sort po ubiv: " << endl;
    sort(v.begin(),v.end(),Comp_less());
    print_vector(v);

    cout << "Sort po vozrst: " << endl;
    sort(v.begin(),v.end());
    print_vector(v);

    cout << "Poisk: " << endl;
    cin >> s;
    //поиск элементов, удовлетворяющих условию предиката
    i = find_if(v.begin(),v.end(),Equal_s());
    if( i != v.end()) //если нет конца вектора
    {
        cout << *(i) << endl;
    }
    else
    {
        cout << "ERROR POISK!" << endl;
    }

    cout << "Delete_move: "<<endl;
    i = min_element(v.begin(),v.end());
    s=*i;
    //переместим элементы совпадающие с min в конец вектора
    i=remove_if(v.begin(),v.end(),Equal_s());
    //удалить все элементы, начиная с i и до конца вектора
    v.erase(i,v.end());
    print_vector(v);

    cout << "Delenie: " << endl;
    i=max_element(v.begin(),v.end());
    s=*i;
    //для каждого элемента вектора вызывается функция del
    for_each(v.begin(),v.end(),del);//выполнение какого-то действия с каждым элементом диапазона по отдельности
    print_vector(v);
}