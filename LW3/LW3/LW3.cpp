#include <iostream>
#include <stdio.h>

using namespace std;

unsigned short funhex(unsigned short b, unsigned short e, unsigned short u, unsigned short c)
{
	b = 0;
	c = 0;
	u = 0;
	e = 0;
	cout << "Интервал номера канала(с) от [0;7]" << endl;
	cout << "Введите переменную c: ";
	cin >> c;
	while (!cin.good() || !(c >= 0 && c <= 7))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение." << endl;
		cout << "Интервал c от [0;7]" << endl;
		cin >> c;
	}
	cout << "Интервал номера устройства в канале(u) от [0;31]" << endl;
	cout << "Введите переменную u: ";
	cin >> u;
	while (!cin.good() || !(u >= 0 && u <= 31))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение." << endl;
		cout << "Интервал г от [0;31]" << endl;
		cin >> u;
	}
	cout << "Интервал кода состояния(е) от [0;127]" << endl;
	cout << "Введите переменную e: ";
	cin >> e;
	while (!cin.good() || !(e >= 0 && e <= 127))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение." << endl;
		cout << "Интервал e от [0;127]" << endl;
		cin >> e;
	}
	cout << "Интервал признака занятости устройства(b) от [0;1]" << endl;
	cout << "Введите переменную b: ";
	cin >> b;
	while (!cin.good() || !(b >= 0 && b <= 1))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение." << endl;
		cout << "Интервал b от [0;1]" << endl;
		cin >> b;
	}
	cout << dec << "с в 10 СС = " << c << endl;
	cout << dec << "u в 10 СС = " << u << endl;
	cout << dec << "e в 10 СС = " << e << endl;
	cout << dec << "b в 10 СС = " << b << endl;
	cout << hex << "с в 16 СС = " << c << endl;
	cout << hex << "u в 16 СС = " << u << endl;
	cout << hex << "e в 16 СС = " << e << endl;
	cout << hex << "b в 16 СС = " << b << endl;
	return b | e << 2 | u << 8 | c << 13;

}

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short b = 0;
	unsigned short c = 0;
	unsigned short u = 0;
	unsigned short e = 0;
	unsigned short x;
	x = funhex(b,e,u,c);
	cout << "X в 16-ричной системе равен: "<< hex << x << endl; // вывод числа в шестнадцатеричном виде
	return 0;
}

