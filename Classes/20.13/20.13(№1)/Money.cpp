#include <iostream>
#include "Money.h"

using namespace std;

    Money :: Money()
    {
        rub = 0;
        cop = 0;
    }

    Money :: Money(long k, int p)
    {
        rub = k;
        cop = p;
    }

    Money :: Money(const Money& g)
    {
        rub = g.rub;
        cop = g.cop;
    }

    Money :: ~Money()
    {

    }

    long Money :: get_rub()
    {
        return rub;
    };

    int Money :: get_cop()
    {
        return cop;
    };

    void Money :: set_rub(long k)
    {
        rub = k;
    };

    void Money :: set_cop(int p)
    {
        cop = p;
    };

    void Money :: show_money()
    {
        cout <<  "Рубли: " << rub << endl << "Копейка: " << cop << endl;
    }


    Money& Money :: operator+(const Money& m)
    {
        long rez;
        rez = (rub * 100 + cop) - (m.rub * 100 + m.cop);
        rub = rez / 100; //целое
        cop = rez % 100; //остаток

        return *this;
    }

    Money& Money :: operator/(Money& m)
    {
        long rez;
        rez = (rub * 100 + cop) / (m.rub*100 + m.cop);
        rub = rez / 100;//целое
        cop = rez % 100;//остаток

        return *this;
    }

    Money& Money :: operator/(int m)
    {
        long rez;
        rez = (rub * 100 + cop) / m;
        rub = rez / 100;//целое
        cop = rez % 100;//остаток

        return *this;
    }

    bool Money :: operator==(const Money& m1)
    {
    if ((rub == m1.rub) && (cop == m1.cop)) {return true;}
    else{return false;}
    }

    bool Money :: operator!=(const Money& m1)
    {
    if ((rub != m1.rub) && (cop != m1.cop)) {return true;}
    else{return false;}
    }

    bool Money :: operator<(const Money& m1)
    {
        if(rub < m1.rub) {return true;}
        if(rub == m1.rub && cop < m1.cop)
        {return true;}

        return false;//если ничего не сработало!
    }

    bool Money :: operator>(const Money& m1)
    {
        if(rub > m1.rub) {return true;}
        if(rub == m1.rub && cop > m1.cop)
        {return true;}

        return false;//если ничего не сработало
    }

    istream& operator>>(istream& in, Money& tmp)
    {
    cout << "Введите кол-во рублей: "; in >> tmp.rub;
    cout << "Введите кол-во копеек: "; in >> tmp.cop;
    return in;
    }

    ostream& operator<<(ostream& out, const Money& tmp)
    {
    return (out << endl << "RUB: " << tmp.rub << ", COP: " << tmp.cop << endl);
    }