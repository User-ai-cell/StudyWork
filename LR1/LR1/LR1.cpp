// LR1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>


using namespace std;
// Функция проверки на ошибки ввода
double err()
{
	double a = 0;
	double z1;
	double z2;
	// ввод альфа
	cout << "Пожалуйста введите значение угла 'a' в градусах: ";
	cin >> a;
	//угол миним -360
	while (!cin.good() || !(a >= -360))
	{
		// очистка состояния потока
		cin.clear();
		// вычистка максимального размера буфера
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение." << endl;
		cin >> a;
	}
	return a;
}

double main()

{
	// русский язык в консоли
	setlocale(LC_ALL, "rus");
	cout << "Добро пожаловать в калькулятор!" << endl;
	cout << "В данной версии можно вычислить только две переменные" << endl;
	cout << "Переменная z1 = 1 - 2sin(a)^2 / 1 + sin(2a)" << endl;
	cout << "Переменная z2 = 1 - tg(a) / 1 + tg(a)" << endl;
	cout << "Все ответы в радианах " << endl;
	cout << "Пожалуйста учитывайте ОДЗ " << endl;
	// константа
	const double pi = atan(1.0) * 4;
	double a = err();
	// перевод альфы из градусов в радианы, для этого вводим переменную r
	double r = a * pi / 180;
	// выражения y1, y2(делитель, он не должен равняться нулю, иначе неправильное ОДЗ)
	double y1 = 1 + sin(2 * r);
	double y2 = 1 + tan(r);
	// проверка правильности ОДЗ
	while (!cin.good() || (y1 == 0 || y2 == 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неверный ОДЗ" << endl;
		return 0;
	}
	double z1 = (1 - 2 * sin(r) * sin(r)) / y1;
	double z2 = (1 - tan(r)) / y2;
	while (a == 45)
	{
		z1 = 0;
		z2 = 0;
		break;
	}
		cout << "z1 = " << z1 << " (в радианах)" << endl;
		cout << "z2 = " << z2 << " (в радианах)" << endl;
		cout << "Стоит уточнить что при значении 90 градусов" << endl;
		cout << "Программа проходит через примерное значение pi =  3.1415926" << endl;
		cout << "Поэтому в ответе не учитывается бесконечность" << endl;
	return 0;
}
