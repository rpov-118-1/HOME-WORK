#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int mystrcmp(const char* str1, const char* str2) { // сравнение строк
	if (str1 > str2) return 1;
	else if (str1 < str2) return -1;
	else return 0;
}

int StringToNumber(char * str, int n) { // Из строки в число
	string S = str;
	n = atoi(S.c_str());
	return n;
}

template<size_t N> char* NumberToString(int number, char (&buf)[N]) { //функция конвертирует число в строку и возвращает указатель на эту строку.
	_itoa_s(number, buf, 10);
	return buf;
}

void Uppercase(char * str1){ //функция преобразует строку в верхний регистр.
	string s = str1;
	for (int i = 0; str1[i]; i++)
		{
			str1[i] = toupper(str1[i]);
			cout << str1[i];
		}
}
void Lowercase(char * str1){// функция преобразует строку в нижний регистр.
	string s = str1;
	for (int i = 0; str1[i]; i++)
	{
		str1[i] = tolower(str1[i]);
		cout << str1[i];
	}
}

int main() {
	int a = 1234;
	char arr[100] = {};
	NumberToString(a, arr);
}
