#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
    long rub;
    int cop;
public:
    Money();
    Money(long k, int p);
    Money(const Money& g);
    ~Money();

    long get_rub();
    int get_cop();

    void set_rub(long k);
    void set_cop(int p);

    void show_money();

    Money& operator-(const Money&);
    Money& operator+(const Money&);
    Money operator=(const Money&);
    Money& operator/(Money&);
    Money& operator/(int);
    Money& operator*(const Money&);

    bool operator!=(const Money&);
    bool operator==(const Money&);
    bool operator<(const Money&);
    bool operator>(const Money&);

    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);
};