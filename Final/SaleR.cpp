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

void AddSale(vector <Sale>& arr, vector <Car>& arrCarr, vector <People>& arrPeoplee) {
    while (true) {
        string value;
        cout << "Для додаваня продажу натисніть ENTER, якщо не треба натисність *: ";
        getline(cin, value);
        if (value == "*") {
            break;
        }
        Sale s;
        cout << "\nВиберіть співробітника:\n";
        for (int i = 0; i < arrPeoplee.size(); i++)
            cout << i + 1 << ". " << arrPeoplee[i].name << endl;
        int numPerson;
        cin >> numPerson;
        s.nameSale = arrPeoplee[numPerson - 1];

        cout << "Виберіть машину:\n";
        vector<string> proverkaCar;
        for (int i = 0; i < arrCarr.size(); i++) {
            bool prov = false;
            for (int j = 0; j < proverkaCar.size(); j++) {
                if (proverkaCar[j] == arrCar[i].brand) {
                    prov = true;
                    break;
                }
            }
            if (!prov) {
                proverkaCar.push_back(arrCarr[i].brand);
                cout << proverkaCar.size() << ". " << arrCarr[i].brand << endl;
            }
        }
        int numCar;
        cin >> numCar;
        string Brands = proverkaCar[numCar - 1];
        s.brandd.brand = Brands;

        cout << "Виберіть модель машини:\n";
        vector<string>models;
        for (int i = 0; i < arrCarr.size(); i++)
            if (arrCarr[i].brand == Brands) {
                models.push_back(arrCarr[i].model);
                cout << models.size() << ". " << arrCarr[i].model << endl;
            }
        int numModel;
        cin >> numModel;
        s.modell.model = models[numModel-1];

        cout << "Введіть дату продажу: \nДень: ";
        cin >> s.data.day;
        cout << "\nМісяць: ";
        cin >> s.data.month;
        cout << "\nРік: ";
        cin >> s.data.yearSale;
        cout << "Введіть реальну ціну продажу: ";
        cin >> s.realPrice;
        arrSale.push_back(s);
        cout << "Продаж додано!\n";
        cin.ignore();
    }
}

void coutSale(vector <Sale>& arr) {
    cout << "\nІнформація про продажі!\n";
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        cout << endl << count << ". ";
        cout << "Продав співробітник: " << arr[i].nameSale.name << endl;
        cout << "Проданий автомобіль: " << arr[i].brandd.brand <<" "<<arr[i].modell.model << endl;
        cout << "Дата продажу: " << arr[i].data.day <<"."<< arr[i].data.month<<"."<< arr[i].data.yearSale << endl;
        cout << fixed << setprecision(3);
        cout << "Реальна ціна продажу: " << arr[i].realPrice << " грн." << endl;
        cout << endl;
        count++;
    }
}

void DeleteSale(vector <Sale>& arr) {
    cout << "\nВидалення продажу!\n";
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

void perezapisSale(vector<Sale>& arr, string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return;
    }

    file << fixed << setprecision(3);

    for (const Sale& s : arr) {
        file << "Name - " << s.nameSale.name << endl;
        file << "Car - " << s.brandd.brand << endl;
        file << "Model - " << s.modell.model << endl;
        file << "DataSale - " << s.data.day << "." << s.data.month << "." << s.data.yearSale << endl;
        file << "PriseSale - " << s.realPrice << endl;
        file << endl;
    }

    cout << "Файл оновлен." << endl;
    file.close();
}

int sale()
{
    system("chcp 1251>null");

    cout << "\033[2J\033[1;1H";

    cout << blue<<"=====Продажі=====\n"<<clearColor;
    string namesSale = "sale1.txt";
    bool run = true;
    while (run) {
        cout <<blue<< "\nМеню:"<<clearColor<<green<<" \n[1] Додавання продажу\n[2] Видалення продажу\n[3] Інформація про продажі\n\
[0] - Закінчити\nВаш вибір: "<<clearColor;
        int choice;
        cin >> choice;
        switch (choice) {
        case 0:
            run = false;
            main();
            break;
        case 1:
            AddSale(arrSale, arrCar, arrPeople);
            perezapisSale(arrSale, namesSale);
            break;
        case 2:
            DeleteSale(arrSale);
            perezapisSale(arrSale, namesSale);
            break;
        case 3:
            coutSale(arrSale);
            break;
        default:
            cout << "Такого вибору немає!";
            break;
        }
    }

    return 0;
}

