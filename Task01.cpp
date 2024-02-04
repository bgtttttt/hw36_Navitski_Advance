#include <iostream>
#include <time.h>
#include <string>

#define m 3
#define n 4

using namespace std;

string matrToString(int matrix[][n]);
void randMatr(int matrix[][n], int min, int max);
int countSedlEl(int matrix[m][n]);
bool isMinInRow(int* row, int elem);


int main() {
	srand(time(0));

	int matrix[m][n] = {
		{5, 6, 4, 5}, //пример с 1 седловой точкой (в данном случае - цифра 4)
		{-2, 5, 3, 7},
		{8, 7, -2, 6}
	};

	//int matrix[m][n] = {
	//	{2, 3, 5, 2}, //пример с 2 седловыми точками (в данном случае - две цифры 2)
	//	{2, 4, 6, 2},
	//	{-2, 7, 2, 0}
	//};

	//int matrix[m][n];
	//randMatr(matrix, -100, 100);

	cout << "Matrix:" << endl;
	cout << matrToString(matrix);

	cout << "\n\nNumber of saddle points: " << countSedlEl(matrix) << "\n";
	return 0;
}

int countSedlEl(int matrix[m][n]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int max = matrix[0][i], row = 0;
		for (int j = 1; j < m; j++) {
			if (max < matrix[j][i]) {
				max = matrix[j][i];
				row = j;
			}
		}
		if (isMinInRow(matrix[row], max)) {
			count++;
		}
	}
	return count;
}
bool isMinInRow(int* row, int elem) {
	for (int i = 0; i < n; i++) {
		if (elem > row[i] && row[i] != elem) {
			return false;
		}
	}
	return true;
}