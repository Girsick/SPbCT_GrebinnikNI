#include <stdarg.h>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	FILE* file = fopen(argv[1], "r");
	char* pEnd;
	char str[50];
	int counter = -1, max = strtoll(argv[2], &pEnd, 10);
	cout << "Original file:\n";
	while (true)
	{
		counter++;
		str[counter] = fgetc(file);
		if (str[counter] == EOF)
			break;
		cout << str[counter] << " ";
	}
	fclose(file);
	file = fopen(argv[1], "w");
	cout<<"\nNew file:\n";
	for (int i = 0; i < counter; i++) {
		if (i == max) {
			fprintf(file, "X");
			cout << "X ";
		}
		fprintf(file, "%c", str[i]);
		cout << str[i] <<" ";
	}
	if (counter <= max) {
		fprintf(file, "X");
		cout<< "X ";
	}
	fclose(file);
}