#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

class Exam
{   
    
public:
            string stud;
            string teacher;
            int score;

            Exam()  //Конструктор без параметров
            {
                stud="-";
                teacher="-";
                score=0;
                cout << "Конструктор без параметров для объекта "<< this << endl;
                cout << endl;
            }

            Exam(string S, string T, int N) //Конструктор с параметрами
            {
                stud=S;
                teacher=T;
                score=N;
                cout << "Конструктор с параметрами для объекта "<< this << endl;
                cout << endl;
            }

            Exam(const Exam &t) //Конструктор копирования
            {
                stud=t.stud;
                teacher=t.teacher;
                score=t.score;
                cout << "Конструктор копирования для объекта "<< this << endl;
                cout << endl;
            }

            ~Exam()
            {
                cout << "Деструктор "<< this << endl;
                cout << endl;
            }

            void show()
            {
                cout << "ФИО студента: " << stud << endl <<"Преподаватель: "<< teacher << endl << "Оценка: "<< score << endl;
            }
};

int main()
{
    setlocale(LC_ALL,"RUS");
    string S="Студент №3";
    string T="Преподаватель №4123";
    int N=4;
    //Конструктор без параметров
    Exam exam1;
    exam1.show();
    //Конструктор с параметрами
    Exam exam2(S,T,N);
    exam2.show();
    //Конструктор копирования
    Exam exam3(*&exam2);
    exam3.show();
}