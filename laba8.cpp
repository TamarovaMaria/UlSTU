#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    const int N = 5; // Количество строк
    const int M = 5; // Количество столбцов
    int minVal = -10, maxVal = 10, size = 0, sum = 0, max = 0;
    int B[N * M]; // Одномерный массив для хранения результатов
    int A[N][M];  // Матрица

    // Заполнение матрицы случайными числами 
    // Вывод сгенерированной матрицы
    cout << "Сгенерированная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            A[i][j] = rand() % 21 - 10;
            cout << A[i][j] << "\t";
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Условие: элемент ниже побочной диагонали (i + j >= N)
            if (i + j >= N && A[N][M] % 2 != 0) {
                B[size] = A[N][M];
                sum += B[size];
                if (B[size] > max) {
                    max = B[size];
                }
                size++;
            }
        }
    }

    cout << "Одномерный массив с нечетными элементами ниже побочной диагонали:\n";
    for (int i = 0; i < size; ++i) {
        cout << B[size] << " ";
    }

    cout << endl;
    cout << "Сумма элементов: " << sum << endl;
    cout << "Максимальный элемент: " << max << endl;
}