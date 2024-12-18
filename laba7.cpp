#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция проверки совместимости матриц для сложения
bool checkMatrixAdditionCompatibility(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    return A.size() == B.size() && A[0].size() == B[0].size();
}

// Функция проверки совместимости матриц для умножения
bool checkMatrixMultiplicationCompatibility(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    return A[0].size() == B.size();
}

// Функция проверки совместимости для векторов
bool checkVectorCompatibility(const vector<double>& X, const vector<double>& Y) {
    return X.size() == Y.size();
}

// Вычитание векторов
vector<double> subtractVectors(const vector<double>& X, const vector<double>& Y) {
    vector<double> result(X.size());
    for (size_t i = 0; i < X.size(); ++i) {
        result[i] = X[i] - Y[i];
    }
    return result;
}

// Умножение матрицы на скаляр
vector<vector<double>> scalarMultiplyMatrix(double scalar, const vector<vector<double>>& A) {
    vector<vector<double>> result = A;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            result[i][j] *= scalar;
        }
    }
    return result;
}

// Сложение матриц
vector<vector<double>> addMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    vector<vector<double>> result = A;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            result[i][j] += B[i][j];
        }
    }
    return result;
}

// Умножение вектора на матрицу
vector<double> multiplyVectorMatrix(const vector<double>& V, const vector<vector<double>>& A) {
    vector<double> result(A[0].size(), 0.0);
    for (size_t i = 0; i < A[0].size(); ++i) {
        for (size_t j = 0; j < V.size(); ++j) {
            result[i] += V[j] * A[j][i];
        }
    }
    return result;
}

// Генерация случайной матрицы
vector<vector<double>> generateRandomMatrix(int rows, int cols, int minVal, int maxVal) {
    vector<vector<double>> matrix(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    return matrix;
}

// Генерация случайного вектора
vector<double> generateRandomVector(int size, int minVal, int maxVal) {
    vector<double> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = minVal + rand() % (maxVal - minVal + 1);
    }
    return vec;
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Размеры матриц и векторов
    int size = 3; // Размер векторов и квадратных матриц
    int minVal = -10, maxVal = 10; // Диапазон случайных значений

    // Генерация случайных данных
    vector<double> X = generateRandomVector(size, minVal, maxVal);
    vector<double> Y = generateRandomVector(size, minVal, maxVal);
    vector<vector<double>> A = generateRandomMatrix(size, size, minVal, maxVal);
    vector<vector<double>> B = generateRandomMatrix(size, size, minVal, maxVal);

    double alfa = 2.0;
    double beta = 1.0;

    // Вывод сгенерированных данных
    cout << "Вектор X: ";
    for (double val : X) cout << val << " ";
    cout << "\n";

    cout << "Вектор Y: ";
    for (double val : Y) cout << val << " ";
    cout << "\n";

    cout << "Матрица A:\n";
    for (const auto& row : A) {
        for (double val : row) cout << val << "\t";
        cout << "\n";
    }

    cout << "Матрица B:\n";
    for (const auto& row : B) {
        for (double val : row) cout << val << "\t";
        cout << "\n";
    }

    // Проверка совместимости
    if (!checkVectorCompatibility(X, Y)) {
        cout << "Размерности векторов X и Y не совпадают!" << endl;
        return 1;
    }

    if (!checkMatrixAdditionCompatibility(A, B)) {
        cout << "Размерности матриц A и B не совпадают для сложения!" << endl;
        return 1;
    }

    if (!checkMatrixMultiplicationCompatibility(A, B)) {
        cout << "Матрицы A и B несовместимы для умножения!" << endl;
        return 1;
    }

    // Вычисления
    vector<double> diffXY = subtractVectors(X, Y);
    vector<vector<double>> modifiedB = scalarMultiplyMatrix(alfa - beta, B);
    vector<vector<double>> sumAB = addMatrices(A, modifiedB);
    vector<double> result = multiplyVectorMatrix(diffXY, sumAB);

    // Вывод результата
    cout << "\nРезультат уравнения: ";
    for (double val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}