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
        cout << "��� �������� ������ �������� ENTER, ���� �� ����� ��������� *: ";
        getline(cin, value);
        if (value == "*") {
            break;
        }
        Car p;
        cout << "\n������ ����� ���������: \n";
        cin >> p.brand;
        cout << "������ �� �������: \n";
        cin >> p.year;
        cout << "������ ������ ������: \n";
        cin >> p.model;
        cout << "������ ����������: \n";
        cin >> p.cost;
        cout << "������ ���������� ���� �������: \n";
        cin >> p.price;
        arr.push_back(p);
        cout << "��� ������ �������!\n";
    }
}

void coutCar(vector <Car>& arr) {
    cout << "\n���������� ��� ������!\n";
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        cout << endl << count << ". ";
        cout << "����� ���������: " << arr[i].brand << endl;
        cout << "г� �������: " << arr[i].year << endl;
        cout << "������ ������: " << arr[i].model << endl;
        cout << fixed << setprecision(3);
        cout << "����������: " << arr[i].cost << endl;
        cout << "���������� ���� �������: " << arr[i].price << endl;
        cout << endl;
        count++;
    }
}

void DeleteCar(vector <Car>& arr) {
    cout << "\n��������� ������!\n";
    cout << "��� ������ ��������?\n";
    int choice;
    cin >> choice;
    for (int i = 0; i < arr.size(); i++) {
        if (i == choice - 1) {
            arr.erase(arr.begin() + (choice - 1));
        }
    }
    cout << "������ ��������!\n";
}

void perezapisCar(vector<Car>& arr, string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cout << "�� ������� ������� ����!" << endl;
    }
    
    file << fixed << setprecision(3);

    for (const Car& c : arr) {
        file << "Brand - " << c.brand << endl
            << "Year - " << c.year << endl
            << "Model - " << c.model << endl
            << "Cost - " << c.cost << endl
            << "Potential price - " << c.price << endl << endl;
    }
    cout << "���� �������.\n";
    file.close();
}

int car()
{
    system("chcp 1251>null");

    cout << "\033[2J\033[1;1H";

    cout <<blue<< "=====������=====\n"<<clearColor;
    string namesCar = "car1.txt";
    bool run = true;
    while (run) {
        cout <<blue<< "\n����:"<<clearColor<<green<<"\n[1] ��������� ������\n[2] ��������� ������\n[3] ���������� ��� ������\n\
[0] - ��������\n��� ����: "<<clearColor;
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
            cout << "������ ������ ����!";
            break;
        }
    }

    return 0;
}
