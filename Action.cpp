#include "iostream"
#include "ctime"
#include "iomanip"
using namespace std;
void createArr(int*& arr, int size);
void printArr(int*& arr, int size);
void fillArr(int* arr, int size);
int max(int* arr, int size);
int min(int* arr, int size);
float avg(int* arr, int size);
float Action(int* arr1, int size1, int* arr2, int size2, int(*ptrFunc)(int*, int));


int main() {
	srand(time(NULL));
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
	int(*ptrFunc)(int* arr, int size);
	ptrFunc = max;
	cout << Action(A, size, B, size, ptrFunc) << endl;


	return 0;
}

float Action(int* arr1, int size1, int* arr2, int size2, int(*ptrFunc)(int*, int)) {
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

int max(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int min(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

float avg(int* arr, int size) {
	int avg = 0;
	for (int i = 0; i < size; i++) {
		avg += arr[i];
	}
	avg /= size;
	return avg;
}
