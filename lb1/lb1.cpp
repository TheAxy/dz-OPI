#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

void Menu() {
	cout << "Меню: " << endl;
	cout << "1.Разделить каждую строку на минимальный элемент строки" << endl;
	cout << "2.Изменить порядок следования элементов главной диагонали на обратный" << endl;
	cout << "3.Найти минимальный элемент среди положительных элемнтов матрицы в определеной области" << endl;
	cout << "0.Выход" << endl;
	cout << "=>";            
}

void ChangeNumbers(double** matrix, int row, int column) {
	int buff{};
	for (int i = 0; i < row / 2; i++) {
		for (int j = 0; j < column / 2; j++) {
			if (i == j) {
				buff = matrix[row - i - 1][column - j - 1];
				matrix[row - i - 1][column - j - 1] = matrix[i][j];
				matrix[i][j] = buff;

			}
		}
	}
}

void PrintMatrix(double** matrix, int row, int column) {
	cout << "\nВывод матрицы: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
		{
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

double SearchMin(double* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}            






	return min;
}

int SearchMinInArea(double** matrix, int row, int column) {
	int min = INT_MAX;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (matrix[i][j] > 0) {
				if (i >= j && column - i - 1 <= j) {
					if (matrix[i][j] < min) min = matrix[i][j];
					cout << matrix[i][j] << ' ';
				}

			}
		}
		cout << endl;
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const ROWS = 14;
	int const COLUMNS = 14;

	double** matrix = new double* [ROWS] {};
	for (int i = 0; i < ROWS; i++)
	{
		matrix[i] = new double[COLUMNS] {};
	}

	double min{};

	srand(time(0));

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			matrix[i][j] = -12 + rand() % 25;
		}
	}

	PrintMatrix(matrix, ROWS, COLUMNS);
	Menu();

	while (true) {
		int k{};
		cin >> k;
		switch (k) {
		case 1: {

			for (int i = 0; i < ROWS; i++) {
				min = SearchMin(matrix[i], 14);
				for (int j = 0; j < COLUMNS; j++) {
					matrix[i][j] = matrix[i][j] / min;
				}
			}
			PrintMatrix(matrix, ROWS, COLUMNS);
			Menu();
			break;
		}
		case 2: {
			ChangeNumbers(matrix, ROWS, COLUMNS);

			PrintMatrix(matrix, ROWS, COLUMNS);

			Menu();
			break;
		}
		case 3: {
			cout << SearchMinInArea(matrix, ROWS, COLUMNS) << endl;
			Menu();
			break;
		}
		case 0: {
			return 0;
		}
		}
	}
}
