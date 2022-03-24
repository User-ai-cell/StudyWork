#include <iostream>
using namespace std;

// Условия существования прямоугольного треугольника;
// 1. Все стороны больше нуля;
// 2. Большая сторона равна сумме квадратов двух остальных;

// класс прям треуг;
class triangle
{
private:
	int first_side; // 1 сторона;
	int sec_side; // 2 сторона;
	int third_side; // 3 сторона;
public:
	void max(int a, int b, int c) // функция подстановки квадрата максимума и двух остальных значений, а также опредиляет прямоугольный ли треугольник;
	{
		int max, zn1, zn2;
		first_side = a;
		sec_side = b;
		third_side = c;

		if (a == b || a == c)
		{
			max = a;
			zn1 = b;
			zn2 = c;
		}
		if (b == a || b == c)
		{
			max = b;
			zn1 = a;
			zn2 = c;
		}
		if (c == b || c == a)
		{
			max = c;
			zn1 = b;
			zn2 = a;
		}
		if (a > b && a > c)
		{
			max = a;
			zn1 = b;
			zn2 = c;
		}
		if (b > a && b > c)
		{
			max = b;
			zn1 = a;
			zn2 = c;
		}
		if (c > b && c > a)
		{
			max = c;
			zn1 = b;
			zn2 = a;
		}
		int tmp_max = max * max;
		int tmp_zn1 = zn1 * zn1;
		int tmp_zn2 = zn2 * zn2;
		if (tmp_max == tmp_zn1 + tmp_zn2 && !isdigit(tmp_max) && !isdigit(tmp_zn2) && !isdigit(tmp_zn1))
			cout << "\nДанная фигура является прямоугольным треугольником\n";
		else if (a <= 0 || b <= 0 || c <= 0)
			cout << "\nДанная фигура не является треугольником\n";
		else
			cout << "\nДанная фигура не является прямоугольным треугольником\n";

	}
	// меню;
	void menu()
	{
		cout << "\n";
		cout << "Программа определения прямоугольного треугольника по значениям 3-х сторон\n\n";
		cout << "1. Введите стороны треугольника\n\n";
		cout << "(q для завершения) ";
	}
	// управление меню;
	bool isvalid(char ch)
	{
		if (ch != '1' && ch != 'q')
			return false;
		else
			return true;
	}

};
// функция проверки ввода данных;
int test(int a, int b, int c)
{
	while (!cin.good() || isdigit(a))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nВведен неверный символ!" << endl;
		break;
		return 0;
	}
	while (!cin.good() || isdigit(b))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nВведен неверный символ!" << endl;
		break;
		return 0;
	}
	while (!cin.good() || isdigit(c))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nВведен неверный символ!" << endl;
		break;
		return 0;
	}
}

int main()
{
	int a, b, c;
	char choice;
	triangle Obj;

	for (;;) {
		do {
			Obj.menu();
			cin >> choice;
		} while (!Obj.isvalid(choice));
		if (choice == 'q') break;
		cout << "\n";
		cin >> a >> b >> c;
		test(a, b, c);
		Obj.max(a, b, c);
	}
	return 0;
}
