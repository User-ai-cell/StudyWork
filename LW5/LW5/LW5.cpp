#include <Windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

void fill_matrix(int m[], int size) 
{
	int size = 0;
	cout << "enter massive size" << endl;
	cin >> size;
	int* m = new int [];

	srand(time(NULL));
	for (int i = 0; i < size; i++)  {
			m[i] = rand() % 10;
		}
	delete[] m;
}

void output_matrix(int m[], const int size)
{
	int* m = new int[];
	for (int i = 0; i < size; i++) 
	{
		cout << m[i] << endl;
	}
	
}

void main()
{
	const int size = 10;
	int m[size][size];
	fill_matrix(*m, size);
	output_matrix(*m, size);




}







/*
const unsigned int l = 2;
const unsigned int c = 3;// размер матрицы



void output_matrix(const double M[c][l]) {
	unsigned int i, j;
	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}


int main()
{
	double M[c][l];
		output_matrix(M);
	return 0;

}
*/