#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    int n;
    cout << "Введите количество фраз: ";
    cin >> n;

    vector<string> strs(n);  // Некоторое количество строк

    // Ввод фраз
    cout << "Введите фразы:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    
    // Сортировка методом пузырька
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Подсчёт длины слов для текущих фраз
            int len_1 = 0, len_2 = 0;
            for (char c : strs[j]) {
                if (!isspace(c)) len_1++;
            }
            for (char c : strs[j + 1]) {
                if (!isspace(c)) len_2++;
            }

            // Меняем местами, если текущая фраза меньше следующей
            if (len_1 < len_2) {
                swap(strs[j], strs[j + 1]);
            }
        }
    }
    
    
    // Вывод фраз в отсортированном порядке
    cout << "Фразы в порядке убывания общей длины слов:" << endl;
    for (const string& str : strs) {
        cout << str<< endl;
    }

}