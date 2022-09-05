#include <iostream>
#include <stdio.h>

using namespace std;

double fun(double a, double b, double c, double x)
{
    if (x < 1 && c != 0)
    {
        return (a * x * x) + (b / c);
    }
    else if (x > 1.5 && c == 0)
    {
        return (x - a) / ((x - c) * (x - c));
    }
    else
    {
        if (c==0 && x < 1.5)
            {
            return INFINITY;
            }
            else
            {
                return (x * x) / (c * c);
            }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, c;
    double x, x1, x2, dx;
    cout << "Все переменные действительные числа" << endl;
    cout << "Ввод несоответсвующих символов вызовет сбой в программе, удачи!" << endl;
    cout << "Введите переменную а: " << endl;
    cin >> a;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> a;
    }
    cout << "Введите переменную b: " << endl;
    cin >> b;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> b;
    }
    cout << "Введите переменную c: " << endl;
    cin >> c;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> c;
    }
    cout << "Введите начальный X: " << endl;
    cin >> x1;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> x1;
    }
    cout << "Введите конечный X: " << endl;
    cin >> x2;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> x2;
    }
    cout << "Введите шаг: " << endl;
    cin >> dx;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверное значение, введите число!" << endl;
        cin >> dx;
    }
    if (x2 > x1)
    {
        for (double x = x1; x <= x2; x += dx)
        {
            cout << "x=" << x << '\t';
            if ((fun(a, b, c, x) == INFINITY))
            {
                cout << "Деление на ноль" << endl;
            }
            else
            {
                cout << "y=" << fun(a, b, c, x) << '\n';
            }
        }
    }
    else
    {
        for (double x = x1; x >= x2; x -= dx)
        {
            cout << "x=" << x << '\t';
            if ((fun(a, b, c, x) == INFINITY))
            {
                cout << "Деление на ноль" << endl;
            }
            else
            {
                cout << "y=" << fun(a, b, c, x) << '\n';
            }
        }
    }
    return 0;
}
