#include <windows.h> 
#include <string>
#include <iostream>
#include <math.h>




using namespace std;

int main() 
{
	int size = 0;
	cout << "enter size" << endl;
	cin >> size;
	int* m = new int[size];
	for (int i = 0; i < size; i++)
	{
		m[i] = rand() % 10;
	}
	for (int i = 0; i < size; i++)
	{
		cout << m[i] << "\t";
		cout << m + i << endl;
	}

	delete [] m;
	return 0;
}