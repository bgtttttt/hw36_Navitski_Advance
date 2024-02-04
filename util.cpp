#include <iostream>
#include <time.h>
#include <string>

#define m 3
#define n 4

using namespace std;

string matrToString(int matrix[][n]) {
	string s = "";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			s = s + to_string(matrix[i][j]) + "\t";
		}
		s += "\n";
	}
	return s;
}
void randMatr(int matrix[][n], int min, int max) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
