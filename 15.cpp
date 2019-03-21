#include "iostream"
#include "ctime"
#include "stdlib.h"
using namespace std;
void printdesk(int arr[], int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		(arr[i] == 0) ? cout << " " : cout << arr[i];
		cout << "\t";
		if (j == 3) {
			cout << endl;
			j = 0;
		}
		else
			j++;
	}
}
int nullindex(int arr[], int n) {
	for (int i = 0; i < n; i++)
		if (arr[i] == 0) return i;
}
int main() {
	srand(time(NULL));
	const int size = 16;
	int play[size];
	int i, i1, i2, i0;
	for (i = 0; i < size; i++)
		play[i] = i;
	//printdesk(play, size);
	//cout << endl;
	for (i = 0; i < 1; i++) {
		i2 = rand() % 15;
		i1 = rand() % 15;
		if (i1 != i2) {
			int temp = play[i1];
			play[i1] = play[i2];
			play[i2] = temp;
		}
	}
	printdesk(play, size);
	cout << endl;
	//cout << nullindex(play, size);
	while (true) {
		int res = 0;
		i0 = nullindex(play, size);
		char key;
		cin >> key;
		switch (key) {
		case 's': {
			if (i0 > 3) {
				int temp = play[i0];
				play[i0] = play[i0 - 4];
				play[i0 - 4] = temp;
			}
		}break;
		case 'w': {
			if (i0 < 12) {
				int temp = play[i0];
				play[i0] = play[i0 + 4];
				play[i0 + 4] = temp;
			}
		}break;
		case 'a': {
			if ((i0 != 3) && (i0 != 7) && (i0 != 11) && (i0 != 15)) {
				int temp = play[i0];
				play[i0] = play[i0 + 1];
				play[i0 + 1] = temp;
			}
		}break;
		case 'd': {
			if ((i0 != 0) && (i0 != 4) && (i0 != 8) && (i0 != 12)) {
				int temp = play[i0];
				play[i0] = play[i0 - 1];
				play[i0 - 1] = temp;
			}
		}break;
		}
		system("cls");
		printdesk(play, size);
		cout << endl;
		for (i = 0; i < size - 1; i++) {
			if (play[i] == i + 1) res++;
		}
		if (res == 15) break;
	}
	cout << "Congradulations! You win!\n";
	return 0;
}
