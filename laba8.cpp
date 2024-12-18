#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillMatrix(int* A, int N, int M, int minVal, int maxVal) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            *(A + i * M + j) = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void printMatrix(int* A, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << *(A + i * M + j) << "\t";
        }
        cout << "\n";
    }
}

void processMatrix(int* A, int N, int M, int* B, int& size, int& sum, int& max) {
    sum = 0;
    max = INT_MIN;
    size = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Условие: элемент ниже побочной диагонали (i + j >= N)
            if (i + j >= N && *(A + i * M + j) % 2 != 0) {
                *(B + size) = *(A + i * M + j);
                sum += *(B + size);
                if (*(B + size) > max) {
                    max = *(B + size);
                }
                size++;
            }
        }
    }
}

void printArray(int* B, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(B + i) << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    const int N = 5; // Количество строк
    const int M = 5; // Количество столбцов
    int minVal = -10, maxVal = 10;

    int A[N][M];
    fillMatrix(&A[0][0], N, M, minVal, maxVal);

    cout << "Исходная матрица:\n";
    printMatrix(&A[0][0], N, M);

    int B[N * M]; // Одномерный массив для хранения результатов
    int size = 0, sum = 0, max = 0;

    processMatrix(&A[0][0], N, M, B, size, sum, max);

    cout << "\nОдномерный массив с нечетными элементами ниже побочной диагонали:\n";
    printArray(B, size);

    cout << "Сумма элементов: " << sum << endl;
    cout << "Максимальный элемент: " << max << endl;

    return 0;
}