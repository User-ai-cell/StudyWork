//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <windows.h>
#include <clocale>
#include <cstdio>

//c использованием библиотек стандартного ввода ввывода
using namespace std;

char twonumeric(char* symbol, bool istwo) {
	ifstream finput("myfile.txt");
	ofstream foutput("myfile1.txt");
	while (finput.getline(symbol, 128))
	{
		istwo = true;
		int n = strlen(symbol);
		if (isdigit(symbol[0]) && isdigit(symbol[1]) && (ispunct(symbol[2]) ||
			isspace(symbol[2])))
		{
			istwo = false;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (isspace(symbol[i]) || ispunct(symbol[i]))
				{
					if (isdigit(symbol[i + 1]) && isdigit(symbol[i + 2]))
					{
						if (isspace(symbol[i + 3]) || ispunct(symbol[i + 3]) ||
							(symbol[i + 3] == '\0'))
						{
							istwo = false;
							break;
						}
					}
					else istwo = true;
				}
			}
		}
		if (istwo)
			foutput << symbol << endl;
	}
	return *symbol;
}

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char line[128];
	bool istwo = true;
	ifstream finput("myfile.txt");
	ofstream foutput("myfile1.txt");
	
	if (!finput)
	{
		cout << ("Файла не существует!");
		return -1;
	}
	if (!foutput)
	{
		cout << ("Файла не существует!");
		return -1;
	}
	twonumeric (line, istwo);
	cout << ("Весь текст скопирован в файл myfile2.txt!") << endl;
	finput.close();
	return 0;

}