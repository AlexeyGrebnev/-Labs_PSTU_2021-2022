#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;


class Money
{
private:
    long rub;
    int cop;

public:
    Money()
    {
        rub = 0;
        cop = 0;
    };

    Money(long k, int p)
    {
        rub = k;
        cop = p;
    };

    Money(const Money& g)
    {
        rub = g.rub;
        cop = g.cop;
    };
    friend bool operator==(const Money& m1, const Money& m2);
    friend bool operator!=(const Money& m1, const Money& m2);

    ~Money()
    {
        cout << "Вызван деструктор: " << endl;
    };

    long get_rub()
    {
        return rub;
    };

    int get_cop()
    {
        return cop;
    };

    void set_rub(long k)
    {
        rub = k;
    };

    void set_cop(int p)
    {
        cop = p;
    };

    void show_money()
    {
        cout << "Для объекта " << this << " => " << "Рубли: " << rub << "; Копейка: " << cop << endl;
    }

    Money& operator--()
    {
        this->cop -= 1;
        return *this;
    }

    Money& operator--(int p)
    {
        this->cop -= 1;
        return *this;
    }

};



bool operator==(const Money& m1, const Money& m2)
{
    if ((m1.rub == m2.rub) && (m1.cop == m2.cop))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Money& m1, const Money& m2)
{
    if ((m1.rub != m2.rub) && (m1.cop != m2.cop))
    {
        return true;
    }
    else
    {
        return false;
    }
}





int main()
{
    setlocale(LC_ALL, "RUS");

    Money m_first;
    Money m_second;

    m_first.set_rub(123);
    m_first.set_cop(33);

    m_second.set_rub(43);
    m_second.set_cop(21);

    m_first.get_rub(); m_first.get_cop();

    m_second.get_rub(); m_second.get_cop();

    m_first--; m_first.show_money();

    --m_second; m_second.show_money();

    cout << endl << endl << "**************************************************************************************" << endl << endl;

    Money m_third;
    Money m_fourth;

    m_third.set_rub(62);
    m_third.set_cop(65);

    m_fourth.set_rub(87);
    m_fourth.set_cop(99);

    m_third.get_rub(); m_third.get_cop();

    m_fourth.get_rub(); m_fourth.get_cop();

    m_third.show_money();
    m_fourth.show_money();


    //Сравнение по operator==
    bool answer_compare1;
    answer_compare1 = m_third == m_fourth;
    if (answer_compare1 == true)
    {
        cout << "Одна сумма равна другой?: 'Да!' " << endl;
    }
    else
        cout << "Одна сумма равна другой?: 'Нет!' " << endl;

    bool answer_compare2;
    answer_compare2 = m_third != m_fourth;
    if (answer_compare2 == true)
    {
        cout << "Одна сумма неравна другой?: 'Да!' " << endl;
    }
    else
        cout << "Одна сумма неравна другой?: 'Нет!' " << endl;

    cout << endl << endl << "**************************************************************************************" << endl << endl;

    return 0;

}