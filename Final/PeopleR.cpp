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
        cout << "��� �������� ����������� �������� ENTER, ���� �� ����� ��������� *: ";
        getline(cin, value);
        if (value == "*") {
            break;
        }
        People p;
        cout << "\n������ ��'� �����������: \n";
        cin >> p.name;
        cout << "������ ������ �����������: \n";
        cin >> p.posada;
        cout << "������ ����� ��������: \n";
        cin >> p.phoneNumb;
        cout << "������ email: \n";
        cin >> p.email;
        arr.push_back(p);
        cout << "��� ������ �������!\n";
    }
}

void coutPeople(vector <People>& arr) {
    cout << "\n���������� ��� �����������!\n";
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        cout<<endl << count << ". ";
        cout << "��'�: " << arr[i].name << endl;
        cout << "������: " << arr[i].posada << endl;
        cout << "����� ��������: " << arr[i].phoneNumb << endl;
        cout << "Email: " << arr[i].email << endl;
        count++;
    }
}

void DeletePeople(vector <People>& arr) {
    cout << "\n��������� �����������!\n";
    cout << "���� ������ ��������?\n";
    int choice;
    cin >> choice;
    for (int i = 0; i < arr.size(); i++) {
        if (i == choice - 1) {
            arr.erase(arr.begin() + (choice - 1));
        }
    }
    cout << "������ ��������!\n";
}

void perezapisPeople(vector<People>& arr, string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cout << "�� ������� ������� ����" << endl;
    }

    for (const People& p : arr) {
        file << "Name - " << p.name << endl
            << "Position - " << p.posada << endl
            << "PhoneNumber - " << p.phoneNumb << endl
            << "Email - " << p.email << endl << endl;
    }
    cout << "���� �������.\n";
    file.close();
}

int people()
{
    system("chcp 1251>null");

    cout << "\033[2J\033[1;1H";

    cout << blue<<"=====�����������=====\n"<<clearColor;
    string names = "people1.txt";
    bool run = true;
    while (run) {
        cout << blue<<"\n����:"<<clearColor<<green<<" \n[1] ��������� �����������\n[2] ��������� �����������\n[3] ���������� ��� �����������\n\
[0] - ��������\n��� ����: "<<clearColor;
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
            cout << "������ ������ ����!";
            break;
        }
    }

    return 0;
}
