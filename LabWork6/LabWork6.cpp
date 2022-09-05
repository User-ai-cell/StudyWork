#include <Windows.h>
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <conio.h>
#include <iomanip>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

using namespace std;

//создаем матрицу или массив массивов
long double** create_matrix(int strings, int columns)
{
	long double** M;
	M = new long double* [strings];
	for (int i = 0; i < strings; i++) 
    {
		M[i] = new long double[columns];
	}
	return M;
}

// ручной ввод матрицы
long double** fill_matrix(long double** M, int strings, int columns)
{
    for (int i = 0; i < strings; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Введите [" << i << "][" << j << "] элемент: "; 
            cin >> M[i][j];
        }
    }
    cout << "Ваша матрица" << endl;
    for (int i = 0; i < strings; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "   " << M[i][j];
        }
        cout << "\n";
    }
    return 0;
}

/*{
	srand(int (time(0)));
	for (int i = 0; i < strings; i++) {
		for (int k = 0; k < columns; k++)
		{
			M[i][k] = rand() % 10;
			cout <<"   "<< M[i][k];
		}
		cout << "\n";
	}
	return 0;
}*/

// преобразование матрицы в треугольную форму по методу Гаусса
long double** transform(long double **M, int s, int c)
{
    //Число перестановок строк
    int rCnt = 0;
    //Ведущий элемент
    double ldn;
    //Номер ведущего элемента
    int index;
    int i, j, k;
    double temp;

    //Прямой ход
    for (j = 0; j < s; ++j)
    {
        //Выбор ведущего элемента столбца
        ldn = M[j][j];
        index = j;
        for (i = j; i < c; ++i)
            if (fabs(M[i][j]) > fabs(ldn))
            {
                ldn = M[i][j];
                index = i;
            }
        //Если ведущий элемент равен нулю
            if (!ldn)
            return 0;//Выход

        //Если ведущий элемент - не на гл. диагонали
        //меняем строки местами
        if (index != j)
        {
            ++rCnt;
            for (i = 0; i < c; ++i)
            {
                temp = M[j][i];
                M[j][i] = M[index][i];
                M[index][i] = temp;
            }
        }

        for (i = 0; i < s; i++)
            M[j][i] = M[j][i] / ldn; //делим строку на ведущий элемент

        //Обнуление элементов ниже гл. диагонали
        for (i = j + 1; i < c; ++i)
        {
            for (k = 0; k < s; ++k) //fabs для того, чтобы невылезало - 0 из - за точности типа double
                M[i][k] = fabs(M[i][k] - M[j][k] * M[i][k]);
        }
    }

        //контрольный вывод после преобразования
        for (i = 0; i < c; i++) {
            for (j = 0; j < s; j++)
                cout << " " << M[i][j];
            cout << "\n";
        }
}


// найдем кол-во строк, среднее арифметическое элементов которых меньше заданной какой-либо величины
long double** findstr(long double** M, int s, int c)
{
    cout << "Введите значение для сравнения " ; //ввод значения для сравнения
    double val, sr; //значение, среднее арифметическое
    int count = 0; //число заданных строк
    cin >> val; //ввод значения

    for (int i = 0; i < s; i++) { //идём по строкам
        sr = 0; //среднее арифметическое строки
        for (int j = 0; j < c; j++)
            sr += M[i][j]; //считаем сумму
        if (val > (sr / c)) 
            count++; //сравниваем с заданным значением и считаем нужные строки
    }

    cout << "Количество строк = "<< count << endl;
    return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int strings(0), columns(0);
	cout << "Введите кол-во строк" << endl;
	cin >> strings;
	cout << "Введите кол-во столбцов" << endl;
	cin >> columns;
    long double** M;

	M = create_matrix(strings, columns);

	fill_matrix(M, strings, columns);

    cout << "Преобразованная матрица по методу гаусса" << endl;

	transform(M, strings, columns);

    findstr(M, strings, columns);

	for (int i = 0; i < strings; i++)
	{
		delete[] M[i];
	}
	delete[] M; // Освобождение памяти
    // Для обнаружения утечек памяти
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
	return 0;
}