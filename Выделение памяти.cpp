#include "iostream"
#include "ctime"
using namespace std;
void createArr(int*& arr, int size);
void printArr(int* arr);
void fillArr(int* arr);
void deleteArr(int*& arr);
void push_back(int*& arr, const int value);
void push_ind(int*& arr, int ind, const int value);
void delete_ind(int*& arr, int ind);
int main(){
	int* pArr;
	createArr(pArr, 10);
	fillArr(pArr);
	printArr(pArr);	
	delete_ind(pArr, 4);
	printArr(pArr);
    return 0;
}
//выделение памяти под массив
void createArr(int*& arr, int size) {
	arr = (int*)malloc(sizeof(int) * size);
}
//печать массива
void printArr(int* arr) {
	int size = _msize(arr) / sizeof(int);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}
//заполнение массива случайными числами от 0 до 20
void fillArr(int* arr) {
	srand(time(NULL));
	int size = _msize(arr) / sizeof(int);
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20;
	}
}
//удаление выделенной памяти
void deleteArr(int*& arr) {
	free(arr);
}
//добавление элемента вконец массива
void push_back(int*& arr, const int value) {
	int size = _msize(arr) / sizeof(int);
	int* newArr = (int*)malloc(sizeof(int) * (size + 1));
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	free(arr);
	arr = newArr;
}
//вставка элемента по указанному индексу
void push_ind(int*& arr, int ind, const int value) {
	int size = _msize(arr) / sizeof(int);
	int* newArr = (int*)malloc(sizeof(int) * (size + 1));
	for (int i = 0; i < ind; i++) {
		newArr[i] = arr[i];
	}
	newArr[ind] = value;
	for (int i = ind + 1; i < size + 1; i++) {
		newArr[i] = arr[i - 1];
	}
	free(arr);
	arr = newArr;
}
//Удаление элемента по указанному индексу
void delete_ind(int*& arr, int ind) {
	int size = _msize(arr) / sizeof(int);
	int* newArr = (int*)malloc(sizeof(int) * (size - 1));
	for (int i = 0; i < ind; i++) {
		newArr[i] = arr[i];
	}
	for (int i = ind; i < size - 1; i++) {
		newArr[i] = arr[i + 1];
	}
	free(arr);
	arr = newArr;
}
