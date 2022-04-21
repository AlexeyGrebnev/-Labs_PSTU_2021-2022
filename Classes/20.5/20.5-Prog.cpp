#include <iostream>

using namespace std;

class Object
{
    public:
        virtual void Print() = 0; //чисто вирутальная функция
};

class Triad : Object
{
protected:
    int first;
    int second;
    int third;
public:
    Triad()
    {
        first = 0;
        second = 0;
        third = 0;
    }
    Triad(int f, int s, int t)
    {
        first = f;
        second = s;
        third = t;
    }
    Triad(const Triad& tmp)
    {
        first = tmp.first;
        second = tmp.second;
        third = tmp.third;
    }
    void setFirst(int f)
    {
        first = f;
    }
    void setSecond(int s)
    {
        second = s;
    }
    void setThird(int t)
    {
        third = t;
    }
    int getFirst() { return first; }
    int getSecond() { return second; }
    int getThird() { return third; }

    void IncrementFirst()
    {
        first = first + 1;
    }
    void IncrementSecond()
    {
        second = second + 1;
    }
    void IncrementThird()
    {
        third = third + 1;
    }

    friend istream& operator>>(istream& in, Triad& tmp);
    friend ostream& operator<<(ostream& out, const Triad& tmp);
    virtual ~Triad()
    {
        cout << "Delete Triad..." << endl << endl;
    }

    void Print() override
    {
        cout << "Вывод тройки чисел: " << first << ", "<< second <<", "<<third;
    }
};

istream& operator>>(istream& in, Triad& tmp)
{
    cout << "Введите первое число: "; in >> tmp.first;
    cout << "Введите второе число: "; in >> tmp.second;
    cout << "Введите третье число(год): "; in >> tmp.second;
    return in;
}

ostream& operator<<(ostream& out, const Triad& tmp)
{
    return (out << "First NUM: " << tmp.first << ", Second NUM: " << tmp.second << ", Third NUM: " << tmp.third);
}



class Date : public Triad
{
public:
    Date()
    {
        first = 0;
        second = 0;
        third = 0;
    }
    Date(int f, int s, int t)
    {
        first = f;
        second = s;
        third = t;
    }
    Date(const Date& tmp)
    {
        first = tmp.first;
        second = tmp.second;
        third = tmp.third;
    }
    void setFirst(int f)
    {
        first = f;
    }
    void setSecond(int s)
    {
        second = s;
    }
    void setThird(int t)
    {
        third = t;
    }
    int getFirst() { return first; }
    int getSecond() { return second; }
    int getThird() { return third; }

    void PlusDays(int n)
    {
        first = first + n;
        while (first > 31)
        {
            first -= 31;
            second += 1;
        }
        while (second > 12)
        {
            second -= 12;
            third += 1;
        }
    }


    friend istream& operator>>(istream& in, Date& tmp);
    friend ostream& operator<<(ostream& out, const Date& tmp);

    ~Date()
    {
        cout << endl << "Delete Date..." << endl << endl;
    }
};

istream& operator>>(istream& in, Date& tmp)
{
    cout << endl << "Сформируем дату: " << endl;
    cout << "Введите день: "; in >> tmp.first;
    cout << "Введите месяц: "; in >> tmp.second;
    cout << "Введите год: "; in >> tmp.third;
    return in;
}

ostream& operator<<(ostream& out, const Date& tmp)
{
    return (out << endl << "Days: " << tmp.first << ", Month: " << tmp.second << ", Year: " << tmp.third << endl);
}


class Vector
{
    private:
        Object** beg;//указатель на первый элемент вектора
        int size;//размер
        int cur;//текущ.позиция
    public:

        Vector()//конструктор без параметров
        {
            beg=0;
            size = 0;
            cur = 0;
        }
        Vector(int n)//конструктор с параметрами
        {
            beg = new Object*[n];
            cur = 0; 
            size = n;
        }
        ~Vector()//Деструктор
        {
            if(beg != 0)
            {
                delete [] beg;
                beg = 0;
            }
        }
        void AddObj(Object* p) //Добавление объекта, на который указывает указатель p в вектор
        {
            if(cur < size)
            {
                beg[cur] = p;
                cur++;
            }
        }
        friend ostream& operator <<(ostream& out, const Vector& v);
};

ostream& operator<<(ostream& out, const Vector& v)
{
    if(v.size == 0)
    {
        out << "Empty" << endl;
    }
    Object** p = v.beg; //указатель на указатель типа Object
        for (int i = 0; i < v.cur; i++)
        {
            (*p)->Print(); //вызов метода Show() - (позднее связывание)
            p++;
        }
    return out;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    //cin >> a;
    //cout << a << endl;
    Vector v(5); //Вектор из пяти элементов 
    Triad a; //объект класса Triad
    cin >> a;
    Date b; //объект класса Date
    cin>>b;
    Object* p = &a; //ставим указатель на объект класса Car
    v.AddObj(p);//добавляем объект в вектор
    p = &b;//ставим указатель на объект класса Date
    v.AddObj(p); //добавляем объект в вектор
    cout << v; //вывод вектора
}