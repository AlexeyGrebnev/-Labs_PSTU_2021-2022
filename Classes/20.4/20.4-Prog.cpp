#include <iostream>

using namespace std;

class Triad
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


int main()
{
    setlocale(LC_ALL, "RUS");
    //cin >> a;
    //cout << a << endl;
    Triad a(12, 11, 1254);
    cout << "Вывод трёх заданных чисел класса Triad: " << endl << a << endl;
    cout << endl << "Добавляем по единице к каждому части: " << endl;
    a.IncrementFirst();
    a.IncrementSecond();
    a.IncrementThird();
    cout << a << endl;

    Date b;
    cin >> b;
    cout << "Вывод даты из класса Date: " << endl << b << endl;
    int n;
    cout << "Введите кол-во дней, которые нужно добавить в заданную дату: ";
    cin >> n;
    b.PlusDays(n);
    cout << "Вывод даты из класса Date: " << endl << b << endl;
}