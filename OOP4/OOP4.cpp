
#include <iostream>
#include <windows.h>

using namespace std;

class Money
{
protected:
    int ten = 10;
    int fifty = 50;
    int hundred = 100;
    int five_hundred = 500;
    int thousand = 1000;
    int five_thousand = 5000;
    int summa = 0;
public:
    Money()
    {
        ten = summa / 10;
        fifty = summa / 50;
        hundred = summa / 100;
        five_hundred = summa / 500;
        thousand = summa / 1000;
        five_thousand = summa / 5000;
    }

    ~Money()
    {}
    
};

class Bankomat : protected Money
{
public:
    Bankomat() : Money ()
    {}
    
    void deposit();
    void withdraw();
    void showSumm();
    void menu();
    void choose(char what);
    bool isvalid(char ch);
};

void Bankomat::showSumm() 
{
    cout << "\nДоступный остаток: \n\n" << summa <<" рублей";
    ten = summa / 10;
    fifty = summa / 50;
    hundred = summa / 100;
    five_hundred = summa / 500;
    thousand = summa / 1000;
    five_thousand = summa / 5000;
    cout << "\n\nВ купюрах: \n";
    cout << "\nДесятки: " << ten << "\n";
    cout << "\nПолтинники: " << fifty << "\n";
    cout << "\nСотни " << hundred << "\n";
    cout << "\nПять сотен: " << five_hundred << "\n";
    cout << "\nТысячи: " << thousand << "\n";
    cout << "\nПять тысяч: " << five_thousand << "\n";
}

void Bankomat::deposit()
{
    int dep = 0;
    cout << "Введите сумму: \n\n";
    cin >> dep;
    if (cin.fail()||dep % 10 != 0)
    {
        cout << "\nВнесение на счет кратно 10. Ввод состоит из цифр \n";
        cout << "\n";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        return deposit();
    }
    cout << "\nВнесение наличных в размере: " << dep << " рублей\n\n";
    summa = summa + dep;
    cout << "\nОстаток на счету: " << summa << " рублей\n\n";
}

void Bankomat::withdraw()
{
    int wdr = 0;
    cout << "Введите сумму: \n\n";
    cin >> wdr;
    if (cin.fail()||wdr % 10 != 0)
    {
        cout << "\nCнятие со счета кратно 10. Ввод состоит из цифр  \n\n";
        cout << "\n";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        return withdraw();
    }
    else if (summa < 0 || summa - wdr < 0)
    {
        cout << "\nНевозможно обналичить сумму\n\n";
        cout << "\n";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        return showSumm();
    }
    cout << "\nВыдача наличных в размере: " << wdr << " рублей\n\n";
    summa = summa - wdr;
    cout << "\nОстаток на счету: " << summa << " рублей\n\n";
}

void Bankomat::choose(char what) {
    switch (what)
    {
    case '1':
        system("cls");
        deposit();
        cout << "\n\n\n\n\n";
        system("pause");
        system("cls");
        break;
    case '2':
        system("cls");
        withdraw();
        cout << "\n\n\n\n\n";
        system("pause");
        system("cls");
        break;
    case '3':
        system("cls");
        showSumm();
        cout << "\n\n\n\n\n";
        system("pause");
        system("cls");
        break;
    }
    cout << "\n";
}

void Bankomat::menu()
{
    cout << "\nБанкомат\n";
    cout << "1. Пополнить счет\n";
    cout << "2. Снять наличные\n";
    cout << "3. Показать остаток счета\n";
    cout << "4. Выход\n\n";
}

bool Bankomat::isvalid(char ch) {
    if (ch < '1' || ch > '3' && ch != '4')
        return false;
    else
        return true;
}

int main()
{
    system("color F1");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    char choice;
    Bankomat obj1;
    for (;;)
    {
        do {
            obj1.menu();
            cin >> choice;
            system("cls");
        }         while (!obj1.isvalid(choice));
        if (choice == '4') break;
        cout << "\n";
        obj1.choose(choice);
    }
    return 0;
}

