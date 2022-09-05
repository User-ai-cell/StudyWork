#include <iostream>
#include <cstdio>
#include <math.h>
#include <windows.h>

using namespace std;

class rectangle {
private:
	int x1, y1, x2, y2;
public:

	// constructor
	rectangle();
	// destructor
	~rectangle();

	// определение операции вычисления площади прямоугольника
	int getSquare();
	// показать площадб
	int showSquare();

	void input();

	void coordinates();

	bool operator*(rectangle obj);
	friend bool operator<(rectangle obj1, rectangle obj2);
	bool operator<=(rectangle obj);
	friend bool operator>(rectangle obj1, rectangle obj2);
	bool operator>=(rectangle obj);
	friend bool operator==(rectangle obj1, rectangle obj2);

};

rectangle::rectangle()
{
}

void rectangle::input()
{
	std::cout << "\n\n\nВведите первую координату(верхнюю левую точку): \n";
	std::cout << "\nВведите x1: ";
	cin >> x1;
	std::cout << "\nВведите y1: ";
	cin >> y1;
	std::cout << "\n\n\nВведите вторую координату(нижнюю правую точку): \n";
	std::cout << "\nВведите x2: ";
	cin >> x2;
	std::cout << "\nВведите y2: ";
	cin >> y2;
}

rectangle::~rectangle(){}

int rectangle::getSquare()
{
	int S = (abs(x1 - x2) * abs(y1 - y2));
	return S;
}

int rectangle::showSquare()
{
	int a, b;
	a = abs(x1 - x2);
	b = abs(y1 - y2);
	int S = (a * b);
	std::cout << "\nСтороны равны " << "a = " << a << "," << "b = " << b;
	std::cout << "\n";
	std::cout << "\nПлощадь прямоугольника равна: " << S;
	std::cout << "\n";
	return S;
}

void rectangle::coordinates()
{
	cout << "Координаты: \n";
	cout << "(" << x1 << "," << y1 << ") " << "(" << x2 << "," << y1 << ") " << "(" << x1 << "," << y2 << ") " << "(" << x2 << "," << y2 << ") ";
}

bool rectangle::operator*(rectangle obj)
{

	if ((obj.x1 > x2 && obj.x2 > x2) || (obj.x1 < x1 && obj.x2 < x1) || (obj.x1 < x2 && obj.y2 > y1) || (obj.x1 < x1 && obj.y1 < y2 && obj.y2 < y2))
			{
				cout << "Нет ";
				return false;
			}
		else
			{
				cout << "Да ";
				return true;
			}
}


bool rectangle::operator<=(rectangle obj)
{
	if (getSquare() <= obj.getSquare())
	{
		cout << "Да ";
		return true;
	}
	else
	{
		cout << "Нет ";
		return false;
	}
}


bool rectangle::operator>=(rectangle obj)
{
	if (getSquare() >= obj.getSquare())
	{
		cout << "Да ";
		return true;
	}
	else
	{
		cout << "Нет ";
		return false;
	}
}


bool operator<(rectangle obj1, rectangle obj2)
{
	if (obj1.getSquare() < obj2.getSquare())
	{
		cout << "Да ";
		return true;
	}
	else
	{
		cout << "Нет ";
		return false;
	}
}
 
 
bool operator>(rectangle obj1, rectangle obj2)
{
	if (obj1.getSquare() > obj2.getSquare())
	{
		cout << "Да ";
		return true;
	}
	else
	{
		cout << "Нет ";
		return false;
	}
}

 
bool operator==(rectangle obj1, rectangle obj2)
{
	if (obj1.getSquare() == obj2.getSquare())
	{
		cout << "Да ";
		return true;
	}
	else
	{
		cout << "Нет ";
		return false;
	}
}

int main()
{
	system("color F1");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	rectangle a;
	a.input();
	a.showSquare();
	a.coordinates();
	rectangle b;
	b.input();
	b.showSquare();
	b.coordinates();
	cout << "\nПервый прямоугольник меньше второго? -";
	a < b;
	cout << "\n";
	cout << "\nПервый прямоугольник меньше либо равен второму? -";
	a <= b;
	cout << "\n";
	cout << "\nПервый прямоугольник больше второго? -";
	a > b;
	cout << "\n";
	cout << "\nПервый прямоугольник больше либо равен второму? -";
	a >= b;
	cout << "\n";
	cout << "\nПервый прямоугольник равен второму? -";
	a == b;
	cout << "\n";
	cout << "\nПрямоугольники пересекаются? -";
	a * b;
	cout << "\n";
	return 0;
}