#include <Windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <conio.h>

using namespace std;

//создаем матрицу или массив массивов
int** create_matrix(int strings, int columns)
{
	int** M;
	M = new int* [strings];
	for (int i = 0; i < strings; i++) {
		M[i] = new int[columns];

	}
	return M;
}

// заполняем матрицу рандомными значениями за основу взяли локальное время на пк 
void int** fill_matrix(int** M, int strings, int columns) 
{
	srand(time(0));
	for (int i = 0; i < strings; i++)  {
		for (int j = 0; i < columns; i++)
			M[i][j] = rand() % 10;
		cout << M[i][j] <<" " <<  endl;
		}
	cout << endl;
}

// преобразование матрицы в треугольную форму по методу Гаусса
void transform(int** M, int strings, int columns)
{
	
}

// найдем кол-во строк, среднее арифметическое элементов которых меньше заданной какой-либо величины
void findstr(int** M, int strings, int columns) 
{

}

int main() 
{
	setlocale(LC_ALL, "Russian");
	int strings(0), columns(0);
	cout << "Введите кол-во строк" << endl;
	cin >> strings >> endl;
	cout << "Введите кол-во столбцов" << endl;
	cin >> columns >> endl;
	int** M;
	
	M = create_matrix(strings, columns);
	fill_matrix(M, strings, columns);
	
	for (int i = 0; i < strings; i++)
	{
		delete[] M[i];
	}
	delete[] M; // Освобождение памяти
	return 0;
}