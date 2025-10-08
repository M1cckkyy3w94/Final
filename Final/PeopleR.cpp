#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Structs.h"
#include "SaleR.h"
#include "PeopleR.h"
#include "Final.h"

#define green "\033[32m"
#define blue "\033[34m"
#define clearColor "\033[0m"

using namespace std;

void AddPeople(vector <People>& arr) {
    while (true) {
        string value;
        cin.ignore();
        cout << "Для додаваня співробітника натисніть ENTER, якщо не треба натисність *: ";
        getline(cin, value);
        if (value == "*") {
            break;
        }
        People p;
        cout << "\nВведіть ім'я співробітника: \n";
        cin >> p.name;
        cout << "Введіть посаду співробітника: \n";
        cin >> p.posada;
        cout << "Введіть номер телефону: \n";
        cin >> p.phoneNumb;
        cout << "Введіть email: \n";
        cin >> p.email;
        arr.push_back(p);
        cout << "Дані успішно записані!\n";
    }
}

void coutPeople(vector <People>& arr) {
    cout << "\nІнформація про співробітників!\n";
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        cout<<endl << count << ". ";
        cout << "Ім'я: " << arr[i].name << endl;
        cout << "Посада: " << arr[i].posada << endl;
        cout << "Номер телефону: " << arr[i].phoneNumb << endl;
        cout << "Email: " << arr[i].email << endl;
        count++;
    }
}

void DeletePeople(vector <People>& arr) {
    cout << "\nВидалення співробітників!\n";
    cout << "Кого хочете видалити?\n";
    int choice;
    cin >> choice;
    for (int i = 0; i < arr.size(); i++) {
        if (i == choice - 1) {
            arr.erase(arr.begin() + (choice - 1));
        }
    }
    cout << "Успішно видалено!\n";
}

void perezapisPeople(vector<People>& arr, string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cout << "Не вдалося відкрити файл" << endl;
    }

    for (const People& p : arr) {
        file << "Name - " << p.name << endl
            << "Position - " << p.posada << endl
            << "PhoneNumber - " << p.phoneNumb << endl
            << "Email - " << p.email << endl << endl;
    }
    cout << "Файл оновлен.\n";
    file.close();
}

int people()
{
    system("chcp 1251>null");

    cout << "\033[2J\033[1;1H";

    cout << blue<<"=====Співробітники=====\n"<<clearColor;
    string names = "people1.txt";
    bool run = true;
    while (run) {
        cout << blue<<"\nМеню:"<<clearColor<<green<<" \n[1] Додавання співробітника\n\
[2] Видалення співробітника\n[3] Інформація про співробітників\n\
[0] - Закінчити\nВаш вибір: "<<clearColor;
        int choice;
        cin >> choice;
        switch (choice) {
        case 0:
            run = false;
            main();
            break;
        case 1:
            AddPeople(arrPeople);
            perezapisPeople(arrPeople, names);
            break;
        case 2:
            DeletePeople(arrPeople);
            perezapisPeople(arrPeople, names);
            break;
        case 3:
            coutPeople(arrPeople);
            break;
        default:
            cout << "Такого вибору немає!";
            break;
        }
    }

    return 0;
}
