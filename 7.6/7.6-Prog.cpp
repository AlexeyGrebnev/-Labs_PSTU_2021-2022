//Вари
#include <iostream>
#include <string>
using namespace std;

void check_polindrom(string word)
{
	int k = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == word[word.length() - i - 1])
		{
			k++;
		}
	}
	if (k == word.length())
	cout << word << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите несколько слов в строчку через пробел: " << endl;
	string s = "";
	string word = "";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
			if (s[i] == ' ')
			{
				check_polindrom(word);
				word = "";
			}
			else
			{
				word += s[i];
			}
			if (i == s.length())
			{
				check_polindrom(word);
			}
	}
	return 0;
}
//Вариант 2
#include <iostream>
#include <string>
using namespace std;

void check_polindrom(string str)
{
	int k;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == str[str.length() - i - 1])
		{
			k++;
		}
	}
	if (k == str.length())
		cout « str « endl;
}
int main()
{
	string slova[3]{ "зараза", "один", "оно" };
	string str;
	for (int j = 0; j < 3; j++)
	{
		str = slova[j];
		check_polindrom(str);
	}
	return 0;
}
