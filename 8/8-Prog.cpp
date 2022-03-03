#include<iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

struct info
{
    char name[20];
    int V;
    char autor[15];
    char nositel[15];
};

int Index(int DefV, info* kempl)
{
    for (int i = 0; i < 4; i++)
    {
        if (kempl[i].V == DefV)
        {
            return i;
        }
    }
}

int main()
{
    int DefV = 35;
    int index;
    setlocale(LC_ALL, "Russian");
    info kempl[4];
    kempl[0] = { "Джонс ", 35, "Гендрикс Мл ", "Иван" };
    kempl[1] = { "Кельвин По ",  43 , " Толстовин ", "Мотя" };
    kempl[2] = { "Солнце ", 43, " Людин ", "Вова" };
    kempl[3] = { "Лунный свет ", 54, " Риккенс ", "Дима" };
    cout << endl;

    ofstream fout;

    info* quert = new info[4];
    index = Index(DefV, kempl);

    switch (index)
    {
    case 3:
        quert[0] = kempl[0];
        quert[1] = kempl[1];
        quert[2] = kempl[2];
        quert[3] = { "Ночь в точке", 34, " Ригеранн ", "Влад" };
        fout.open("myFile.txt");
        fout << "*******************************************************" << endl;
        for (int i = 0; i < 3; i++)
        {
            fout << "****************************" << endl;
            fout << "Название: " << quert[i].name << "\n";
            fout << "Объём: " << quert[i].V << "\n";
            fout <<"Автор: " << quert[i].autor << "\n";
            fout << "Носитель: " << quert[i].nositel << "\n";
            fout << "\n";
            fout << "****************************" << endl;
        }
        fout << "*******************************************************" << endl;
        fout.close();
        break;
    case 2:
        quert[0] = kempl[0];
        quert[1] = kempl[1];
        quert[2] = kempl[3];
        quert[3] = { "Ночь в точке", 34, " Ригеранн ", "Влад" };
        fout.open("myFile.txt");
        fout << "*******************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            fout << "****************************" << endl;
            fout << "Название: " << quert[i].name << "\n";
            fout << "Объём: " << quert[i].V << "\n";
            fout <<"Автор: " << quert[i].autor << "\n";
            fout << "Носитель: " << quert[i].nositel << "\n";
            fout << "\n";
            fout << "****************************" << endl;
        }
        fout << "*******************************************************" << endl;
        fout.close();
        break;
    case 1:
        quert[0] = kempl[0];
        quert[1] = kempl[2];
        quert[2] = kempl[3];
        quert[3] = { "Ночь в точке", 34, " Ригеранн ", "Влад" };

        fout.open("myFile.txt");
        fout << "*******************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            fout << "****************************" << endl;
            fout << "Название: " << quert[i].name << "\n";
            fout << "Объём: " << quert[i].V << "\n";
            fout <<"Автор: " << quert[i].autor << "\n";
            fout << "Носитель: " << quert[i].nositel << "\n";
            fout << "\n";
            fout << "****************************" << endl;
        }
        fout << "*******************************************************" << endl;
        fout.close();

        break;
    case 0:
        quert[0] = kempl[1];
        quert[1] = kempl[2];
        quert[2] = kempl[3];
        quert[3] = { "Ночь в точке", 34, " Ригеранн ", "Влад" };

        fout.open("myFile.txt");
        fout << "*******************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            fout << "****************************" << endl;
            fout << "Название: " << quert[i].name << "\n";
            fout << "Объём: " << quert[i].V << "\n";
            fout <<"Автор: " << quert[i].autor << "\n";
            fout << "Носитель: " << quert[i].nositel << "\n";
            fout << "\n";
            fout << "****************************" << endl;
        }
        fout << "*******************************************************" << endl;
        fout.close();

        break;
    default:
        quert[0] = kempl[0];
        quert[1] = kempl[1];
        quert[2] = kempl[2];
        quert[3] = kempl[3];

        fout.open("myFile.txt");
        fout << "*******************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            fout << "****************************" << endl;
            fout << "Название: " << quert[i].name << "\n";
            fout << "Объём: " << quert[i].V << "\n";
            fout <<"Автор: " << quert[i].autor << "\n";
            fout << "Носитель: " << quert[i].nositel << "\n";
            fout << "\n";
            fout << "****************************" << endl;
        }
        fout << "*******************************************************" << endl;
        fout.close();

    }
    delete[] quert;
    return 0;
}
