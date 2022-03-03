#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 3;
    bool flag = false;
    int min = 99;
    string minslv;
    string first1 = "", first2 = "";
    string str;
    string text = "";
    ofstream F1("F1.txt"); //из файла* 
    ifstream F2("F2.txt"); //в файл*
    F1.open("F1.txt");
    for (int i = 0; i < n; i++)
    {
        cout << "Введите строки(с условием - вначале ставим пробел) : " << endl;
        getline(cin, str);
        F1 << str << endl;
    }
    F1.close();
    if (F2.open())
        if (F1.open())
        {
            while (getline(F2, str))
            {
                flag = false;

                for (int i = 0; i < size(str); i++)
                {
                    if (str[i] == ' ')
                    {
                        first2 = first1;
                        first1 = str[i + 1];
                    }
                    if (first1 == first2)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                {
                    F2 << str << endl;
                    if (size(str) > min)
                    {
                        min = size(str);
                        minslv = str;
                    }
                }
            }
            F2 << "Короткое слово из файла F2" << minslv << endl;
        }
    F2.close();
    F1.close();
}