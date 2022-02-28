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
