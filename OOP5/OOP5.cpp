
#include <windows.h>
#include <iostream>
#include <exception>

using namespace std;

class arr
{
private:
    int size;
    int* p;
public: 
    arr(int);
    void sort();
    void summNegative();
    void multiplicationMinMax();
    void print();
    ~arr();
};

class negativeAbsence : public exception
{
public:
    negativeAbsence() {};
    ~negativeAbsence() {};
    virtual const char* what() const throw()
    { return "в массиве отсутствуют отрицательные элементы\n";}
};

class elemMinMaxAbsence : public exception
{
public:
    elemMinMaxAbsence() {};
    ~elemMinMaxAbsence() {};
    virtual const char* what() const throw()
    {
        return "между максимальным и минимальным элементами массива, элементы отстутствуют.\n";
    }
};

arr::arr(int i = 0) : size(i)
{
    if (i < 0 || i > 15)
        throw std::out_of_range("\nОшибка: размер массива слишком большой либо отрицательный");
    p = new int[size];
    cout << "Введите значения массива: \n";
        for (int i = 0; i < size; i++) {
            cin >> p[i];
            cout << "Элемент массива [" << i << "] = " << p[i] << endl;
        }
};

arr::~arr() 
{
    delete[] p;
};

void arr::sort()
{
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < size - 2; i += 2) {
            if (p[i] > p[i + 1]) {
                swap(p[i], p[i + 1]);
                sorted = false;
            }
        }
        for (int i = 0; i < size - 1; i += 2) {
            if (p[i] > p[i + 1]) {
                swap(p[i], p[i + 1]);
                sorted = false;
            }
        }
    }
    cout << "\nМассив отсортирован... ";
}

void arr::summNegative()
{
    int summ = 0;
    for (int i = 0; i < size; i++)
    {
        if (p[i] < 0)
        {
            summ = summ + p[i];
        }
    }
    // Когда у нас отсутствуют отрицательные элементы 
    try
    {
        if (summ == 0)
            throw negativeAbsence();
    }
    catch (negativeAbsence &e)
    {
        cout << "\nОшибка: " << e.what();
        exit(1);
    }
    cout << "\nСумма отрицательных элементов массива = " << summ;
}

void arr::multiplicationMinMax()
{
    int min = p[0];
    int max = p[0];
    int minI = 0;
    int maxI = 0;
    int multiplication = 1;
    for (int i = 0; i < size; i++)
    {
        if (min < p[i])
        {
            min = p[i];
            minI = i;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (max > p[i])
        {
            max = p[i];
            maxI = i;
        }
    }
        if (minI < maxI)
        {
            int nextmin = minI + 1;
            for (nextmin; nextmin < maxI; nextmin++)
            {
                multiplication = multiplication * p[nextmin];
            }
        }
        else if (maxI < minI)
        {
            int nextmax = maxI + 1;
            for (nextmax; nextmax < minI; nextmax++)
            {
                multiplication = multiplication * p[nextmax];
            }
        }
        cout <<"\nMinimum: " << p[maxI] << endl;
        cout <<"\nMaximum: " << p[minI] << endl;
        try
        {
            if ((multiplication == p[maxI]) || (multiplication == p[minI]))
                throw elemMinMaxAbsence();
        }
        catch (elemMinMaxAbsence &e)
        {
            cout << "\nОшибка: " << e.what();
            exit(1);
        }
        cout << "\nПроизведение между максимальным и минимальным элементами массива = " << multiplication;
}

void arr::print()
{
    cout << "\nВаш массив: \n" << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << " " << p[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    system("color F1");

    SetConsoleCP(1251);
    
    SetConsoleOutputCP(1251);
    
    setlocale(LC_ALL, "Russian");

    int i = 10;

    arr obj(i);

    obj.print();

    obj.summNegative();

    obj.multiplicationMinMax();

    obj.sort();

    obj.print();

    // Слишком большой массив
    try
    {
        arr obj(20);
    }
    catch (out_of_range &e)
    { 
        cout << e.what() << endl; 
        exit(1);
    }
    return 0;
}
