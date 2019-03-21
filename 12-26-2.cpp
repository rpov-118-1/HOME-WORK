#include "pch.h"
#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "iomanip"
#include "time.h"
using namespace std;
void printdesk(int arr[], int n,int& i0);

int main()
{
	srand(time(NULL));
	const size_t N = 16;
	long int r = 0;
	int play[N] = {};
	int i = 0, i1, i2, i0=0, temp;
	for (i = 0; i < N; i++)
	{
		play[i] = i;
	}
	
	for (i = 0; i < 50; i++)
	{

		i1 = rand() % 15;
		i2 = rand() % 15;
		if (i1 != i2)
		{
			int temp = play[i1];
			play[i1] = play[i2];
			play[i2] = temp;
		}
	}
	printdesk(play, N,i0);
	cout << endl;
	char key;
	while(true)
	{
		cin >> key;
		switch (key)
		{
		case's':
			if (i0 > 3)
			{
				temp = play[i0];

				play[i0] = play[i0 - 4];

				play[i0 - 4] = temp;
				i0 = i0 - 4;
			}
			break;
		case'w':
			if (i0 < 12)
			{
				temp = play[i0];

				play[i0] = play[i0 + 4];

				play[i0 + 4] = temp;
				i0 = i0 - 4;
			}
			break;
		case'd':
			if (i0 != 0 || i0 != 4 || i0 != 8 || i0 != 12)
			{
				temp = play[i0];

				play[i0] = play[i0 - 1];

				play[i0 - 1] = temp;
				i0 = i0 - 1;
			}
			break;
		case'a':
			if (i0 != 3 || i0 != 7 || i0 != 11 || i0 != 15)
			{
				temp = play[i0];

				play[i0] = play[i0 + 1];

				play[i0 + 1] = temp;
				i0 = i0 + 1;
			}
			break;
		}
		system("cls");
		printdesk(play, N, i0);
		for (int k = 0, i = 0; i < N; i++)
		{
			if (i == play[i]) { k++; }
			if(k==15){ break; }
		}
	}
	cout << "YOAR WINE";
	
	return 0;
}
void printdesk(int arr[], int n,int& i0)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) {
			cout << " ";
			i0 = i;
		}
		else {
			cout << arr[i];
		}
		cout << "\t";
		if (j == 3)
		{
			cout << endl;
			j = 0;
		}
		else { j++; }
	}
}
