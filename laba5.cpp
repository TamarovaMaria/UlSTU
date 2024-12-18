#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int n = 5; // Размер матрицы
    int matrix[n][n];
    int positive[n * (n - 1) / 2]; // Массив для хранения положительных элементов и их максимальное число
    int count = 0; // Счётчик положительных элементов

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение матрицы случайными числами
    // Вывод сгенерированной матрицы
    cout << "Сгенерированная матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 21 - 10;
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    // Сбор положительных элементов ниже побочной диагонали
    for (int i = 1; i < n; ++i) { // Строки ниже главной побочной диагонали
        for (int j = n - i; j < n; ++j) { // Столбцы правее побочной диагонали
            if (matrix[i][j] > 0) {
                positive[count++] = matrix[i][j];
            }
        }
    }

    // Вывод результатов
    cout << endl;
    cout << "Положительные элементы ниже побочной диагонали: ";
    if (count == 0) {
        cout << "нет положительных элементов.\n";
    } 
    else {
        for (int i = 0; i < count; ++i) {
            cout << positive[i] << " ";
        }
        cout << "\n";
    }
    
}