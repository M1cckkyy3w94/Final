#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "Structs.h"
#include "SaleR.h"
#include "PeopleR.h"
#include "Final.h"

#define green "\033[32m"
#define blue "\033[34m"
#define clearColor "\033[0m"

using namespace std;

void AddCar(vector <Car>& arr) {
    while (true) {
        string value;
        cin.ignore();
        cout << "Для додаваня машини натисніть ENTER, якщо не треба натисність *: ";
        getline(cin, value);
        if (value == "*") {
            break;
        }
        Car p;
        cout << "\nВведіть назву виробника: \n";
        cin >> p.brand;
        cout << "Введіть рік випуску: \n";
        cin >> p.year;
        cout << "Введіть модель машини: \n";
        cin >> p.model;
        cout << "Введіть собівартість: \n";
        cin >> p.cost;
        cout << "Введіть потенційну ціну продажу: \n";
        cin >> p.price;
        arr.push_back(p);
        cout << "Дані успішно записані!\n";
    }
}

void coutCar(vector <Car>& arr) {
    cout << "\nІнформація про машини!\n";
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        cout << endl << count << ". ";
        cout << "Назва виробника: " << arr[i].brand << endl;
        cout << "Рік випуску: " << arr[i].year << endl;
        cout << "Модель машини: " << arr[i].model << endl;
        cout << fixed << setprecision(3);
        cout << "Собівартість: " << arr[i].cost << endl;
        cout << "Потенційна ціна продажу: " << arr[i].price << endl;
        cout << endl;
        count++;
    }
}

void DeleteCar(vector <Car>& arr) {
    cout << "\nВидалення машини!\n";
    cout << "Яку хочете видалити?\n";
    int choice;
    cin >> choice;
    for (int i = 0; i < arr.size(); i++) {
        if (i == choice - 1) {
            arr.erase(arr.begin() + (choice - 1));
        }
    }
    cout << "Успішно видалено!\n";
}

void perezapisCar(vector<Car>& arr, string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
    }
    
    file << fixed << setprecision(3);

    for (const Car& c : arr) {
        file << "Brand - " << c.brand << endl
            << "Year - " << c.year << endl
            << "Model - " << c.model << endl
            << "Cost - " << c.cost << endl
            << "Potential price - " << c.price << endl << endl;
    }
    cout << "Файл оновлен.\n";
    file.close();
}

int car()
{
    system("chcp 1251>null");

    cout << "\033[2J\033[1;1H";

    cout <<blue<< "=====Машини=====\n"<<clearColor;
    string namesCar = "car1.txt";
    bool run = true;
    while (run) {
        cout <<blue<< "\nМеню:"<<clearColor<<green<<"\n[1] Додавання машини\n[2] Видалення машини\n[3] Інформація про машини\n\
[0] - Закінчити\nВаш вибір: "<<clearColor;
        int choice;
        cin >> choice;
        switch (choice) {
        case 0:
            run = false;
            main();
            break;
        case 1:
            AddCar(arrCar);
            perezapisCar(arrCar, namesCar);
            break;
        case 2:
            DeleteCar(arrCar);
            perezapisCar(arrCar, namesCar);
            break;
        case 3:
            coutCar(arrCar);
            break;
        default:
            cout << "Такого вибору немає!";
            break;
        }
    }

    return 0;
}
