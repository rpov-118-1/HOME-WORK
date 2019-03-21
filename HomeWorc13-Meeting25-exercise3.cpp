#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "iomanip"
#include "ctime"

int main()
{
	srand(time(NULL));
	int Arr1[10], Arr2[10];
	int *pArr1, *pArr2;
	pArr1 = &Arr1[0];
	pArr2 = &Arr2[0];
	for (int i = 0; i < 10; i++)
	{
		*(pArr1 + i) = rand() % 100;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << *(pArr1 + i) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		*(pArr2 + i) = *(pArr1 + (9 - i));
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << *(pArr2 + i) << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
