#include <iostream>

using namespace std;

class Iterator
{
    friend class Variety;

private:
    int* elem;

public:
    Iterator() //Конструктор без параметров
    {
        elem = 0;
    }

    int& operator*() const
    {
        return *elem;
    }

    Iterator(const Iterator& a)
    {
        elem = a.elem;
    }

    void operator++()
    {
        ++elem;
    }
    void operator--()
    {
        cout << "Переход к предыдущему элементу: ";
        --elem;
    }
    bool operator!=(const Iterator& a)
    {
        return elem != a.elem;
    }
};

class Variety
{
private:
    int size;
    int* data;
    Iterator beg;
    Iterator end;

public:
    ~Variety()
    {

    }

    Variety(int size)
    {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = rand() % 96;
        }
        beg.elem = &data[0];
        end.elem = &data[size];
    }

    int& operator[](int num)
    {
        if (num < size && num >= 0)
        {
            return data[num];
        }

        else
        {
            cout << endl << "*******************" << endl << "Ошибка" << endl << "*******************" << endl;
        }
    }

    Variety operator-(const Variety& a) //-a
    {
        Variety temp(size);

        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i] - a.data[i];
        }
        delete[] data;
        return temp;
    }
    int& operator() ()
    {
        return size;
    }

    Iterator first()
    {
        return beg;
    }

    Iterator last()
    {
        return end;
    }

};


int main()
{
    setlocale(LC_ALL, "RUS");
    int index;
    int size;
    Iterator iter;

    cout << "Задайте размер(size): ";
    cin >> size;

    Variety a(size);
    cout << "class Variety a: ";
    for (iter = a.first(); iter != a.last(); ++iter)
    {
        cout << *iter << ", ";
    }

    cout << endl << "Определение размера множества a: " << a() << endl;

        cout << endl << "Задайте индекс(index) для поиска: ";
        cin >> index;
        if (index >=0 && index < size) 
        {
            cout << "Доступ по заданному индексу: " << a[index] << endl;
        }
        else 
        {
            cout << endl << "Доступ по заданному индексу невозможен!"<< endl;
        }
    
    cout << endl;
    --iter;
    cout << *iter << endl;
    --iter;
    cout << *iter << endl << endl;

    Variety b(size);
    cout << "class Variety b: ";
    for (iter = b.first(); iter != b.last(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl << "Определение размера множества b: " << b() << endl;

    Variety c = a - b;
    cout << endl << "class Variety c => " << "*Разность 'Variety a' и 'Variety b'*: ";
    for (iter = c.first(); iter != c.last(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl << "Определение размера множества с: " << c() << endl;
    cout << endl;
}