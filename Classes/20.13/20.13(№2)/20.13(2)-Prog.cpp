#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "Money.h"

using namespace std;

typedef priority_queue <Money> Queue;
typedef vector <Money> Vector;

Money s;

struct Greater_s
{
    bool operator()(Money m)
    {
        if(m>s) {return true;}
        else {return false;}
    }
};

Queue make_queue(int n)
{
    Money a;
    Queue q;
    for(int i = 0; i<n; i++)
    {
        cin >> a;
        q.push(a);
    }
}

Vector q_to_v(Queue st)
{
    Vector v;
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

Queue v_to_q(Vector v)
{
    Queue q;
    for(int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }
    return q;
}

void print_queue(Queue st)
{
    Vector v_tmp;
    v_tmp = q_to_v(st);
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    st = v_to_q(v_tmp);
}

Money srednee(Vector v)
{
    Money m = v[0];//сумма
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
    setlocale(LC_ALL,"RUS");
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    Queue q = make_queue(n);
    print_queue(q);

    Vector v = q_to_v(q);
    Vector :: iterator i;
    //поставим итератор на макс элемент
    i = max_element(v.begin(),v.end());
    cout << "max= " << *(i) << endl;
    Money k = *(i);

    s = srednee(v);//нашли сред арифм вектора
    cout << "srednee vect= "<<s<<endl;

    //замена с использованием предиката
    replace_if(v.begin(),v.end(),Greater_s(),k);
    cout << "Zamena: " << endl;
    q = v_to_q(v);
    print_queue(q);

    v = q_to_v(q);
    cout << "Sort po ubiv: " << endl;
    sort(v.begin(),v.end(),Comp_less());
    q = v_to_q(v);
    print_queue(q);

    v = q_to_v(q);
    cout << "Sort po vozrst: " << endl;
    sort(v.begin(),v.end());
    q = v_to_q(v);
    print_queue(q);

    v = q_to_v(q);
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
    q = v_to_q(v);
    print_queue(q);

    v = q_to_v(q);
    cout << "Delenie: " << endl;
    i=max_element(v.begin(),v.end());
    s=*i;
    //для каждого элемента вектора вызывается функция del
    for_each(v.begin(),v.end(),del);//выполнение какого-то действия с каждым элементом диапазона по отдельности
    q = v_to_q(v);
    print_queue(q);
}