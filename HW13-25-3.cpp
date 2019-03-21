#include "iostream"
using namespace std;

int main() {
	const int SIZE = 10;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr1[10] = { 0 };
	for (int i = 0, j = SIZE - 1; i < SIZE; i++, j--) {
		arr1[i] = *(arr + j);
	}
	for (int i = 0; i < SIZE; i++) {
		cout << arr1[i] << " \n";
	}
	   	return 0;
}
