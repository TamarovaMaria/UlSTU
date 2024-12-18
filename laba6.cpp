#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int rows = 5, cols = 5; // Размер матрицы
    int matrix[rows][cols];

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение матрицы случайными числами от -50 до 50
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    // Вывод сгенерированной матрицы
    cout << "Сгенерированная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    // Поиск максимального отрицательного элемента
    int maxNegative = -51; // Минимально возможное отрицательное значение
    int maxRow = -1;       // Строка, где найден максимальный отрицательный элемент

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < 0 && matrix[i][j] > maxNegative) {
                maxNegative = matrix[i][j];
                maxRow = i;
            }
        }
    }

    if (maxRow == -1) {
        cout << "В матрице нет отрицательных элементов.\n";
        return 0;
    }

    // Вывод результирующей матрицы без строки с максимальным отрицательным элементом
    cout << "\nРезультирующая матрица (после удаления строки " << maxRow + 1 << "):\n";
    for (int i = 0; i < rows; ++i) {
        if (i == maxRow) continue; // Пропускаем строку с максимальным отрицательным элементом
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}