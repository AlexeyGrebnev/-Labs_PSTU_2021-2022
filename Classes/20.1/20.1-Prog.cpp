#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Triangle

{
    double first;
    double second;

public:

    void hipotinus(double first, double second)
    {
        double a,b,c;
        a = pow(2,first);
        b = pow(2,second);
        c = a+b;
        c = sqrt(c);
        cout << "Гипотенуза треугольника равна: ";
        cout << c;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    Triangle tringle;
    double kat1, kat2;
    cout << "Введите значения катетов: "<< endl << endl;
    cout << "Значение первого катета: ";
    //kat1=4;
    cin >> kat1;
    cout << endl;
    cout << "Значение второго катета: ";
    //kat2=4;
    cin >> kat2;
    cout << endl << endl;
    if((kat1 > 0) & (kat2 > 0))
    {
        tringle.hipotinus(kat1,kat2);
        cout << endl << endl;
    }
    else
    {
        cout << "Вы ввели недопустимые для работы программы данные по катетам треугольника!";
    }
    return 0;
}

