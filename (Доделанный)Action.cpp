#include "pch.h"
#include "iostream"
#include "ctime"
#include "iomanip"
using namespace std;

double Action(int* arr1, int size1, int* arr2, int size2, double(*ptrFunc)(int*, int)) {
	if (ptrFunc(arr1, size1) > ptrFunc(arr2, size2))
		return ptrFunc(arr1, size1);
	else
		return ptrFunc(arr2, size2);
}

void createArr(int*& arr, int size) {
	arr = new int[size];
}

void printArr(int*& arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(3) << arr[i] << " ";
	}cout << endl;
}

void fillArr(int* arr, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21 - 10;
	}
}

double max(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double min(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

double avg(int* arr, int size) {
	int avg = 0;
	for (int i = 0; i < size; i++) {
		avg += arr[i];
	}
	avg /= size;
	return avg;
}

int main() {
	srand(time(NULL));
	int c;
	int size;
	int* A;
	int* B;
	cout << "Enter a size of a arrays\n";
	cin >> size;
	createArr(A, size);
	createArr(B, size);
	fillArr(A, size);
	fillArr(B, size);
	printArr(A, size);
	printArr(B, size);
	double(*ptrFunc)(int* arr, int size);
	cout << "what do u need?" << endl;
	cout << "1. max of array\n" << "2.min of array\n" << "3.avg of array" << endl;
	cin >> c;
	switch (c) {
	case 1:
		ptrFunc = max;
		cout << Action(A, size, B, size, ptrFunc) << endl;
		break;
	case 2:
		ptrFunc = min;
		cout << Action(A, size, B, size, ptrFunc) << endl;
		break;
	case 3:
		ptrFunc = avg;
		cout << Action(A, size, B, size, ptrFunc) << endl;
		break;
	}
}

