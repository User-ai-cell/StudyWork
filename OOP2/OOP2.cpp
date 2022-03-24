// OOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Worker
{
private:
    string name;
    string surname;
    int rate;
    int days;
    int copynumber;
public:

    int getSalary() 
    { 
        return rate * days;
    }

    // конструктор по умолчанию
    Worker()
    {
        rate = 1500;
        days = 1;
        name = "Иван";
        surname = "Иванов";
        copynumber = 0;
        cout << "\nИмя, фамилия сотрудника: " << name + surname << endl;
        cout << "\nСтавка: " << rate << " рублей \n";
        cout << "\nКол-во смен: " << days <<"\n";
    }
    // конструктор для установки начальных значений полей
    Worker(string n, string s, int r, int d)
    {
        copynumber = 0;
        cout << "\nВведите имя сотрудника: ";
        getline(cin, n);
        name = n;
        cout << "Введите фамилию сотрудника: ";
        getline(cin, s);
        surname = s;
        cout << "Введите cтавку: ";
        cin >> r;
        rate = r;
        cout << "Введите кол-во смен: ";
        cin >> d;
        days = d;
    }
    // конструктор копирования
    Worker(const Worker &obj)
    {
        rate = obj.rate;
        days = obj.days;
        name = obj.name;
        surname = obj.surname;
        copynumber = obj.copynumber + 1;
        cout << "\nСоздание копии...\n\n";
    }

    ~Worker()
    {
        if (copynumber == 0)
            cout << "\nУничтожение оригинала.\n\n";
        else
            cout << "Уничтожение копии " << copynumber << "\n";
    }

};


void display(Worker ob)
{
    cout << "Зарплата сотрудника: " << ob.getSalary() << " Рублей.\n" << endl;
}

int main()
{
    string n;
    string s;

    int r, d;
    r = 0;
    d = 0;

    Worker ob1;

    Worker ob2(n, s, r, d);

    Worker ob3 = ob1;

    //Конструктор копирования вызывается, когда объект передается (функции) по значению в качестве аргумента

    display(ob1);

    display(ob2);

    display(ob3);

    return 0;
}

