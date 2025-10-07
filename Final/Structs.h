#pragma once
#include <string>
#include <vector>
using namespace std;

struct People {
    string name;
    string posada;
    string phoneNumb;
    string email;
};

struct Car {
    string brand;
    int year;
    string model;
    double cost;
    double price;
};

struct DataSale {
    int day;
    int month;
    int yearSale;
};

struct Sale {
    People nameSale;
    Car brandd, modell;
    DataSale data;
    double realPrice;
};
