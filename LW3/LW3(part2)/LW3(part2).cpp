#include <iostream>
#include <stdio.h>

using namespace std;

unsigned short fundehex(unsigned short c, unsigned short u, unsigned short e, unsigned short b)
{
	short x;
	cout << "Введите значение x: ";
	cin >> hex >> x;
	c = (x >> 13) & 7;
	u = (x >> 8) & 0x1F;
	e = (x >> 1) & 0x7F;
	b = (x >> 0) & 1;
	cout << dec << "c=" << c << endl;
	cout << dec << "u=" << u << endl;
	cout << dec << "e=" << e << endl;
	cout << dec << "b=" << b << endl;
	cout << "X в 10 СС = " << dec << x << endl;
	cout << "X в 16 СС = " << hex << x << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short c = 0;
	unsigned short u = 0;
	unsigned short e = 0;
	unsigned short b = 0;
	unsigned short n = 0;
	short x = fundehex(c,u,e,b);
	return 0;
}
