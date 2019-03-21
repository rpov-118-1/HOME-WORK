#include <iostream>
using namespace std;

int Action(int* a, int* b, int const* size);
void max(int* a, int* b, int const* size, int* result, int* arr);
void min(int* a, int* b, int const* size, int* result, int* arr);
void avg(int* a, int* b, int const* size, int* result, int* arr);

int main()
{
	int exits = 1;
	int const size = 10;
	int a[size]{ 1,2,3,4,5,6,7,8,9,10 };
	int b[size]{ 11,12,13,14,15,16,17,18,19 };
	system("cls");
	do
	{
		Action(a, b, &size);
		cout << "1. Continue enter \n2. EXIT \n";
		cin >> exits;
		if (exits != 1 &&
			exits != 0)
		{
			system("cls");
			cout << "Bye" << endl;
			exit(1);
		}
	} while (exits != 0);
}

int Action(int* a, int* b, int const* size)
{
	system("cls");
	int result;
	int arr;
	int foo;
	cout << "Select:\n1. maximum in arr: \n2. minimum in arr: \n3. average in arr: \n4. exit \nEnter: ";
	cin >> foo;
	if (foo == 1)
	{
		max(a, b, size, &result, &arr);
		cout << "Maximum in arr = " << result << endl;
	}
	else if (foo == 2)
	{
		min(a, b, size, &result, &arr);
		cout << "Minimum in arr = " << result << endl;
	}
	else if (foo == 3)
	{
		avg(a, b, size, &result, &arr);
		cout << "Average in arr = " << result << endl;
	}
	else if (foo == 4)
	{
		cout << "Bye" << endl;
		exit(1);
	}
	else
	{
		system("cls");
		cout << endl << endl << "Error wrong input" << endl;
		exit(1);
	}
	return 0;
}

void max(int* a, int* b, int const* size, int* result, int* arr)
{
	system("cls");
	*result = 0;
	for (int i = 0; i < *size; i++)
	{
		if (*result < a[i])
		{
			*result = a[i];
		}
		if (*result < b[i])
		{
			*result = b[i];
		}
	}
}

void min(int* a, int* b, int const* size, int* result, int* arr)
{
	system("cls");
	*result = 1;  // Тут можно любое число, но только при условии, что не будет меньше числа, которое в массиве считается минимальным
	for (int i = 0; i < *size; i++)
	{
		if (*result > a[i])
		{
			*result = a[i];
		}
		if (*result > a[i])
		{
			*result = b[i];
		}
	}
}


void avg(int* a, int* b, int const* size, int* result, int* arr)
{
	system("cls");
	*result = 0;
	for (int i = 0; i < *size; i++)
	{
		*result += a[i] + b[i];
	}
	*result /= (*size * 2);
	for (int i = 0; i < *size; i++)
	{
		if (*result == a[i])
		{
			*result = a[i];
		}
		if (*result == b[i])
		{
			*result = b[i];
		}
	}
}
