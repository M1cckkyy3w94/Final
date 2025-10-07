#pragma once
#ifndef FINAL_H
#define FINAL_H

#include "Structs.h"


//це означає шо ці масиви будут в інших файлах, підсказав \
чат гпт так як не знав як зробити щоб масиви було видно у всіх файлах
extern std::vector<People> arrPeople;
extern std::vector<Car> arrCar;
extern std::vector<Sale> arrSale;

int people();
int car();
int sale();


int main();

#endif