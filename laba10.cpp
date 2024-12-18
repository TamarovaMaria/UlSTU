#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Структура для хранения информации о телефонном абоненте
struct Subscriber {
    string fullName;    // ФИО абонента
    string street;      // Улица проживания
    string phoneNumber; // Номер телефона
};

// Функция для поиска абонента по улице
void findSubscribersByStreet(const vector<Subscriber>& subscribers, const string& street) {
    bool found = false;
    
    for (const auto& subscriber : subscribers) {
        if (subscriber.street == street) {
            cout << "ФИО: " << subscriber.fullName << endl;
            cout << "Улица: " << subscriber.street << endl;
            cout << "Телефон: " << subscriber.phoneNumber << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Абоненты на улице " << street << " не найдены." << endl;
    }
}

int main() {
    vector<Subscriber> subscribers = {
        {"Иванов Иван Иванович", "Ленина", "123-45-67"},
        {"Петров Петр Петрович", "Калинина", "234-56-78"},
        {"Сидоров Сидор Сидорович", "Ленина", "345-67-89"},
        {"Кузнецова Анна Николаевна", "Троицкая", "456-78-90"}
    };

    string street;
    cout << "Введите улицу для поиска: ";
    getline(cin, street);

    findSubscribersByStreet(subscribers, street);

    return 0;
}