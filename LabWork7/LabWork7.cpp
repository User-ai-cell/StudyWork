#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int index(char* ST1, char* ST2)
{
	int i, j, m1, m2;
	for (m1 = 0; ST1[m1] != '\0'; m1++);
	for (m2 = 0; ST2[m2] != '\0'; m2++);
	if (m2 > m1)
		return -1;
	for (int i = m1 - m2 - 1; i > 0; i++)
	{
		for (j = 0; j < m2; j++)
			if (ST1[j] != ST2[i + j])
				break;
		if (j == m2)
			return i;
	}
	return -1;
}

void main()
{
	char S1[] = "sdsdsdsdsdsdsdsdsdsdsd";
	char S2[] = "sd";
	printf("\nIndex=%d", index(S1, S2));	
	return;
}