/*
Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.
*/
#include "iostream"
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	const size_t a = 10;
	const size_t b = 10;
	int arr[a] = {};
	int arr2[b] = {};
	int *pa = arr;
	int *pb = arr2;

	cout << "Random number in 'a' Massiv: ";
	for (int i = 0; i < a; i++) 
	{
			arr[i] = rand() % 11;
			cout << arr[i] << " ";
	}

	cout << endl << endl;
	cout << "Massive A :" << endl;

	for (int *pa = arr; pa <= &arr[a] - 1; pa++)
	{
		cout << "address= " << pa << "\tvalue= " << *pa << endl;
	}

	cout << endl << endl;

	cout << "Massive B: " << endl;

	for (int j = 0; j < 10; j++) 
	{
		(*(pb + j) = *(pa + j));
	}

	for (int j = 0; j < 10; j++)
	{
		cout << "address = " << (pb+j) << "\tvalue = " << *(pb+j) << endl;
	} 
	cout << endl << endl;
	return 0;
}
