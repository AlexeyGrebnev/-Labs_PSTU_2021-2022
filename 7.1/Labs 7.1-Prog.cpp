// labs1 "Перегрузка программы"10.
// а) для вычитания десятичных дробей;
// б) для вычитания обыкновенных дробей.
#include <iostream>
#include <cmath>

using namespace std;
int nod(int a, int b) // Наименьший общий делитель для использования в сокращениях обыкновенной дроби
{
    while (a != 0 && b != 0)
    {
        if (a > b) { a = a % b; }
        else { b = b % a; }
    }
    return a + b;
}



double calcVichet(double a, double b) // Для десятичных дробей
{
    return a - b; // вывод 
}
void calcVichet(int a1, int a, int b1, int b) //Для обыкновенных дробей
{
    int rez1; //Результат числителя 
    int rez2; //Результат знаменателя
    int acount; //Доп множитель для числителя первой дроби
    int bcount; //Доп множитель для числителя второй дроби
    int gcount; //Сокращение на общий множитель результата вычисления
    rez2 = a * b; //Результирующий знаменатель без сокращения
    acount = nod(a, rez2); //определение
    //cout << acount << endl; 
    bcount = nod(b, rez2); //Определение
    //cout << bcount << endl;
    rez1 = (a1 * acount) - (b1 * bcount); //Результирующий числитель без сокращения
    gcount = nod(rez1, rez2); //определение
    rez1 = rez1 / gcount; //сокращение числителя
    rez2 = rez2 / gcount; //сокращение знаменателя
    if (rez1 == 0 || rez2 == 0) // Защита от Нуля
    {
        cout << "Обыкновенные дроби (вычитание):  " << a1 << " / " << a << " - " << b1 << " / " << b << " = " << 0 << endl;
    }
    else
    {
        cout << "Обыкновенные дроби (вычитание):  " << a1 << " / " << a << " - " << b1 << " / " << b << " = " << rez1 << " / " << rez2 << endl;
    }
}
//return отсутвствует по причине void, где он не нужен совсем
int main()
{
    setlocale(LC_ALL, "RUS");
    calcVichet(5, 6, 3, 4); // без cout т.к Void
    cout << "Десятичные дроби (вычитание):  " << calcVichet(5.3, 3.1) << endl; //А здесь без него, поэтому cout
}