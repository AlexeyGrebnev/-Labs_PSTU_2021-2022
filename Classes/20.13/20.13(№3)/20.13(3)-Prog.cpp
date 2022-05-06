#include <iostream>
#include "Money.h"
#include <vector>
#include <set>

using namespace std;

typedef multiset <Money> mySet;
typedef multiset<Money> :: iterator Iter; //для работы в действиях

Money s;

struct Greater_s
{
    bool operator()(Money m)
    {
        if(m>s) {return true;}
        else {return false;}
    }
};
mySet make_MulSet(int n)
{
    Money a;
    mySet mst;
    for(int i = 0; i<n; i++)
    {
        cin >> a;
        mst.insert(a);
    }
    return mst;
}


void print_MulSet(mySet mst)
{
    Iter iter = mst.begin();
    while (iter != mst.end())
    {
        cout << *iter;
        iter++;
    }
    cout << endl;
}

Money srednee(mySet mst)
{
    Iter iter = mst.begin();
    Money m;//сумма
    //перебор вектора
    int n = 0;
    while (iter != mst.end())
    {
        m=m+(*iter);
        n++; //кол-во элементов в векторе
        iter++;
    }
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
    mySet mt;

    mySet mt1;
    mt1 = make_MulSet(6);
    mt1.swap(mt);

    int n = 6;
    mt = make_MulSet(n);
    print_MulSet(mt);

    //iter = max_element(mt.begin(),mt.end());

    s = srednee(mt);
    cout << "srednee (multiset) = "<<s<<endl;
    print_MulSet(mt);

    Iter iter = mt.begin();
    Money k = *(iter);
    remove_if(mt.begin(),mt.end(),Greater_s());
    print_MulSet(mt);

    cout << "Poisk: " << endl;
    cin >> s;
    //поиск элементов, удовлетворяющих условию предиката
    iter = find(mt.begin(),mt.end(),Equal_s());
    if( iter != mt.end()) //если нет конца вектора
    {
        cout << *(iter) << endl;
    }
    else
    {
        cout << "ERROR POISK!" << endl;
    }

    cout << "Delete_move: "<<endl;
    iter = min(mt.begin(),mt.end());
    s=*iter;
    //переместим элементы совпадающие с min в конец вектора
    iter=remove_if(mt.begin(),mt.end(),Equal_s());

    //удалить все элементы, начиная с i и до конца вектора
    mt.erase(iter,mt.end());
    print_MulSet(mt);
}