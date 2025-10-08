#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "PeopleR.h"
#include "CarR.h"
#include "SaleR.h"
#include "Final.h"

#define green "\033[32m"
#define blue "\033[34m"
#define clearColor "\033[0m"

//cout << fixed << setprecision(3); це дає змогу виводити нулі після . тобто не 888, а 888.000

using namespace std;

std::vector<People> arrPeople;
std::vector<Car> arrCar;
std::vector<Sale> arrSale;
std::vector<DataSale> arrData;

void fileZapisCar(vector <Car>& arr, string& fileName) {
    ifstream fileR(fileName);
    Car c;
    string lines;
    int count = 0;

    while (getline(fileR, lines)) {
        if (lines.empty()) continue;

        size_t pos = lines.find(" - ");
        if (pos == string::npos) continue;

        string key = lines.substr(0, pos);
        string val = lines.substr(pos + 3);

        if (key == "Brand") c.brand = val;
        else if (key == "Year") c.year = stoi(val);
        else if (key == "Model") c.model = val;
        else if (key == "Cost") c.cost = stod(val);
        else if (key == "Potential price") c.price = stod(val);
        count++;
        if (count == 5) {
            if (!c.brand.empty() && !c.model.empty() && c.year != 0 && c.cost != 0 && c.price != 0) {
                arr.push_back(c);
            }
            count = 0;
            c = Car();
        }
    }
    fileR.close();
}

void fileZapisPeople(vector <People>& arr, string& fileName) {
    ifstream fileR(fileName);
    People p;
    string lines;
    int count = 0;

    while (getline(fileR, lines)) {
        if (lines.empty()) continue;

        size_t pos = lines.find(" - ");
        if (pos == string::npos) continue;

        string key = lines.substr(0, pos);
        string val = lines.substr(pos + 3);

        if (key == "Name") p.name = val;
        else if (key == "Position") p.posada = val;
        else if (key == "PhoneNumber") p.phoneNumb = val;
        else if (key == "Email") p.email = val;
        count++;
        if (count == 4) {
            if (!p.name.empty() && !p.posada.empty() && !p.phoneNumb.empty() && !p.email.empty()) {
                arr.push_back(p);
            }
            count = 0;
            p = People();
        }
    }
    fileR.close();
}

void fileZapisSale(vector <Sale>& arr, string& fileName) {
    ifstream fileR(fileName);
    Sale s;
    string lines;
    int count = 0;

    while (getline(fileR, lines)) {
        if (lines.empty()) continue;

        size_t pos = lines.find(" - ");
        if (pos == string::npos) continue;

        string key = lines.substr(0, pos);
        string val = lines.substr(pos + 3);

        if (key == "Name") s.nameSale.name = val;
        else if (key == "Car") s.brandd.brand = val;
        else if (key == "Model") s.modell.model = val;
        else if (key == "DataSale") {
            size_t d1 = val.find('.');
            size_t d2 = val.find('.', d1+1);
            if (d1 != string::npos && d2 != string::npos) {
                s.data.day = stoi(val.substr(0, d1));
                s.data.month = stoi(val.substr(d1 + 1, d2 - d1 - 1));
                s.data.yearSale = stoi(val.substr(d2 + 1));
            }
        }
        else if (key == "PriseSale") s.realPrice = stod(val);
        count++;
        if (count == 5) {
            if (!s.nameSale.name.empty() &&
                !s.brandd.brand.empty() &&
                !s.modell.model.empty()&&
                s.data.day != 0 &&
                s.realPrice != 0)
            {
                arr.push_back(s);
            }
            count = 0;
            s = Sale();
        }
    }
    fileR.close();
}


void SaleData() {
    int days, months, years;
    cout << "Введіть дату за яку хочете дізнатись про продажі день|місяць|рік: ";
    cin >> days >> months >> years;
    cout << "\nЗа цей день було продано: \n";
    int count = 0;
    for (int j = 0; j < arrSale.size(); j++) {
        if (days == arrSale[j].data.day && months == arrSale[j].data.month && years == arrSale[j].data.yearSale) {
            cout << "\nПродав співробітник: " << arrSale[j].nameSale.name << endl;
            cout << "Проданий автомобіль: " << arrSale[j].brandd.brand << endl;
            cout << "Дата продажу: " << arrSale[j].data.day << "." << arrSale[j].data.month << "." << arrSale[j].data.yearSale << endl;
            cout << fixed << setprecision(3);
            cout << "Реальна ціна продажу: " << arrSale[j].realPrice << " грн." << endl;
            cout << endl;
            count++;
        }
    }
    if (count == 0) cout << "Нажаль немає ніякої інформації за цей день(\n\n";
}

void SaleDataTime() {
    int days1, months1, years1, days2, months2, years2;
    cout << "Введіть дату ВІД якої хочете дізнатись про продажі день|місяць|рік: ";
    cin >> days1 >> months1 >> years1;
    cout << "Введіть дату ДО якої хочете дізнатись про продажі день|місяць|рік: ";
    cin >> days2 >> months2 >> years2;
    int count = 0;
    cout << "\nЗа цей час було продано: \n";
    for (int j = 0; j < arrSale.size(); j++) {
        int d = arrSale[j].data.day, m=arrSale[j].data.month, y= arrSale[j].data.yearSale;
        bool afterStart = (y > years1) || (y == years1 && m > months1) || (y == years1 && m == months1 && d >= days1);
        bool beforeEnd = (y < years2) || (y == years2 && m < months2) || (y == years2 && m == months2 && d <= days2);
        if (afterStart && beforeEnd) {
            cout << "\nПродав співробітник: " << arrSale[j].nameSale.name << endl;
            cout << "Проданий автомобіль: " << arrSale[j].brandd.brand << endl;
            cout << "Дата продажу: " << arrSale[j].data.day << "." << arrSale[j].data.month << "." << arrSale[j].data.yearSale << endl;
            cout << fixed << setprecision(3);
            cout << "Реальна ціна продажу: " << arrSale[j].realPrice << " грн." << endl;
            cout << endl;
            count++;
        }
    }
    if (count == 0) cout << "Нажаль немає ніякої інформації за цей час(\n\n";
}

void SalePeople() {
    int peop;
    int count=1;
    cout << "Продажі якого співробітника ви б хотіли дізнатися?\n";
    for (int i = 0; i < arrPeople.size(); i++) {
        cout << count << ". " << arrPeople[i].name << endl;
        count++;
    }
    cin >> peop;
    count = 0;
    cout << "\nПродажі " << arrPeople[peop - 1].name << ": ";
    for (int i = 0; i < arrSale.size(); i++) {
        if (arrPeople[peop-1].name == arrSale[i].nameSale.name) {
            cout << endl << count + 1 << ". ";
            cout << "Проданий автомобіль: " << arrSale[i].brandd.brand << endl;
            cout << "Дата продажу: " << arrSale[i].data.day << "." << arrSale[i].data.month << "." << arrSale[i].data.yearSale << endl;
            cout << fixed << setprecision(3);
            cout << "Реальна ціна продажу: " << arrSale[i].realPrice << " грн." << endl;
            cout << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << " нажаль нічого не продав.";
    }
}

void PopulationPeopleTime() {
    int days1, months1, years1, days2, months2, years2;
    cout << "Введіть дату ВІД якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days1 >> months1 >> years1;
    cout << "Введіть дату ДО якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days2 >> months2 >> years2;
    int countPeople[100] = { 0 };
    string PeopleSales[100];
    int size = 0;
    cout << "\nЗа цей час найуспішніший співробітник: ";
    for (int j = 0; j < arrSale.size(); j++) {
        int d = arrSale[j].data.day, m = arrSale[j].data.month, y = arrSale[j].data.yearSale;
        bool afterStart = (y > years1) || (y == years1 && m > months1) || (y == years1 && m == months1 && d >= days1);
        bool beforeEnd = (y < years2) || (y == years2 && m < months2) || (y == years2 && m == months2 && d <= days2);
        if (afterStart && beforeEnd) {
            bool flag = false;
            for (int i = 0; i < size; i++) {
                if (PeopleSales[i] == arrSale[j].nameSale.name) {
                    countPeople[i]++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                PeopleSales[size] = arrSale[j].nameSale.name;
                countPeople[size] = 1;
                size++;
            }
        }
    }
    if (size == 0) {
        cout << " не знайден\n";
    }
    else if (size > 0) {
        int maxSalePeople = 0;
        string popularPeople;
        for (int i = 0; i < size; i++) {
            if (countPeople[i] > maxSalePeople) {
                maxSalePeople = countPeople[i];
                popularPeople = PeopleSales[i];
            }
        }
        cout << "\nНайуспішніший співробітник: " << popularPeople << " продав " << maxSalePeople << " машини\n";
    }
}

void PopulationCarTime() {
    int days1, months1, years1, days2, months2, years2;
    cout << "Введіть дату ВІД якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days1 >> months1 >> years1;
    cout << "Введіть дату ДО якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days2 >> months2 >> years2;
    int countCar[100] = { 0 };
    string brands[100];
    int size = 0;
    cout << "\nЗа цей час було продано: ";
    for (int j = 0; j < arrSale.size(); j++) {
        int d = arrSale[j].data.day, m = arrSale[j].data.month, y = arrSale[j].data.yearSale;
        bool afterStart = (y > years1) || (y == years1 && m > months1) || (y == years1 && m == months1 && d >= days1);
        bool beforeEnd = (y < years2) || (y == years2 && m < months2) || (y == years2 && m == months2 && d <= days2);
        if (afterStart && beforeEnd) {
            bool flag = false;
            for (int i = 0; i < size; i++) {
                if (brands[i] == arrSale[j].brandd.brand) {
                    countCar[i]++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                brands[size] = arrSale[j].brandd.brand;
                countCar[size] = 1;
                size++;
            }
        }
    }
    if (size == 0) {
        cout << " нажаль за цей час немає ніякої інформації\n";
    }
    else if (size > 0) {
        int maxSaleCar = 0;
        string popularBrand;
        for (int i = 0; i < size; i++) {
            if (countCar[i] > maxSaleCar) {
                maxSaleCar = countCar[i];
                popularBrand = brands[i];
            }
        }
        cout << "\nНайпопулярніший автомобіль: " << popularBrand << " продали " << maxSaleCar << " машин\n";
    }
}

void SummaPrise() {
    int days1, months1, years1, days2, months2, years2;
    cout << "Введіть дату ВІД якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days1 >> months1 >> years1;
    cout << "Введіть дату ДО якої хочете дізнатись про найпопулярніший автомобіль день|місяць|рік: ";
    cin >> days2 >> months2 >> years2;
    double summa = 0;
    cout << "\nЗа цей час було продано на: ";
    for (int j = 0; j < arrSale.size(); j++) {
        int d = arrSale[j].data.day, m = arrSale[j].data.month, y = arrSale[j].data.yearSale;
        bool afterStart = (y > years1) || (y == years1 && m > months1) || (y == years1 && m == months1 && d >= days1);
        bool beforeEnd = (y < years2) || (y == years2 && m < months2) || (y == years2 && m == months2 && d <= days2);
        if (afterStart && beforeEnd) {
            double temp = 0;
            for (int i = 0; i < arrCar.size(); i++) {
                if (arrSale[j].brandd.brand == arrCar[i].brand && arrSale[j].modell.model == arrCar[i].model) {
                    temp = arrSale[j].realPrice - arrCar[i].cost;
                }
            }
            summa += temp;
        }
    }
    if (summa == 0) {
        cout << "сумму - 0 грн.";
    }
    else if (summa > 0) {
        cout << fixed << setprecision(3);
        cout << "сумму - " << summa <<" грн." << endl;
    }
}


int main()
{
    system("chcp 1251>null");
    cout << "\033[2J\033[1;1H";
    
    arrCar.clear();
    arrPeople.clear();
    arrSale.clear();
    string namesCar = "car1.txt";
    string namesPeople = "people1.txt";
    string namesSale = "sale1.txt";
    fileZapisCar(arrCar, namesCar);
    fileZapisPeople(arrPeople, namesPeople);
    fileZapisSale(arrSale, namesSale);


    cout <<blue<< "=====ОБЛІК ПРОДАЖУ АВТОМОБІЛІВ В АВТОСАЛОНІ=====\n"<<clearColor;
    while (true) {
        cout << blue<<"\nМеню додавання | видалення | вивід інформаці:"<<clearColor<<green<<"\n[1] Для співробітників\n[2] Для автомобілів\n\[3] Для продажів\n"<<clearColor<<blue<<"\
Меню звітів:"<<clearColor<<green<<"\n\
[4] Продажі за певну дату\n[5] Продажі за період часу\n[6] Продажі конкретного співробітника\n[7] Найпопулярніший автомобіль, за певний час\
\n[8] Найуспішніший співробітник за певний час \n[9] Сумарний прибуток за певний час\nВаш вибір: "<<clearColor;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            people();
            break;
        }
        case 2: {
            car();
            break;
        }
        case 3: {
            sale();
            break;
        }
        case 4: SaleData(); break;
        case 5: SaleDataTime(); break;
        case 6: SalePeople(); break;
        case 7: PopulationCarTime(); break;
        case 8: PopulationPeopleTime(); break;
        case 9: SummaPrise(); break;
        }
    
    }

    return 0;
}
