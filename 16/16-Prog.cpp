#include <iostream>
#include <string>
using namespace std;

int BM_Search(string tempstr, string str)
{
    int strlen = str.size();
    int tempstrlen = tempstr.size();
    int pos;
    bool flag = false;
    if (strlen != 0 && tempstrlen != 0 && !flag)
    {
        for (int i = 0; i < strlen - tempstrlen + 1; i++)
        {
            for (int j = 0; j < tempstrlen; j++)
            {
                if (tempstr[j] != str[i + j])
                {
                    flag = true;
                }
                else 
                {
                    if (j == tempstrlen - 1)
                    {
                        pos = i;
                        flag = true;
                    }
                }
            }
        }
        return pos;
    }
    else return -1;
}

int main()
{
    string tempstr;
    string str;
    int strlen = str.size();
    int tempstrlen = tempstr.size();
    cout << "Введите строчку: ";
    cin >> str;
    cout << "Введите строчку: ";
    cin >> tempstr;
    int index;
    int k=1;
    index = BM_Search(tempstr, str);
    int j = 0;
    for (int i = 0; i < strlen; i++)
    {
        while(i != strlen - templlen)
        {
            k++;
        }
    }
    if (index != -1)
    {
        cout << "Заданный образец в строке находится под первым индексом => " << index << " !" << endl;
        for(int i = k; i < strlen; i++)
        {
                str[i] = temp[j];
                j++;
        }
        for(int i = 0; i <= strlen - 1; i++)
        {
            cout <<" "<< str[i] <<" ";
        }
    }
    else
        cout << "Заданный образец не найден в строке! " << endl;

    for(int i = 0; i <= strlen - 1; i++)
    {
        cout <<" "<< str[i] <<" ";
    }
    
}