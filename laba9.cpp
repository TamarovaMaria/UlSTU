#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Функция для подсчета общей длины всех слов в предложении
int calculateLength(const string& sentence) {
    int length = 0;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        length += word.length();
    }
    return length;
}

int main() {
    int n;
    cout << "Введите количество фраз: ";
    cin >> n;
    cin.ignore();  // Игнорируем символ новой строки после числа

    vector<string> sentences(n);
    vector<pair<string, int>> sentencesWithLength;

    // Ввод фраз
    cout << "Введите фразы:" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, sentences[i]);
        int length = calculateLength(sentences[i]);
        sentencesWithLength.push_back(make_pair(sentences[i], length));
    }

    // Сортировка фраз по общей длине слов в порядке убывания
    sort(sentencesWithLength.begin(), sentencesWithLength.end(), 
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

    // Вывод фраз в отсортированном порядке
    cout << "\nФразы в порядке убывания общей длины слов:" << endl;
    for (const auto& sentence : sentencesWithLength) {
        cout << sentence.first << endl;
    }

    return 0;
}