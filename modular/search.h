#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

#include "car.h"
#include "output.h"

using namespace std;

void findCar();
void searchByBrand();
void searchByModel();
void searchByYear();
void searchByPrice();
void searchByBody();
void searchBySegment();

void findCar() {
    int searchChoice;

    cout << "search by: " << endl;
    cout << "1 - brand" << endl;
    cout << "2 - model" << endl;
    cout << "3 - year" << endl;
    cout << "4 - price" << endl;
    cout << "5 - body" << endl;
    cout << "6 - segment " << endl;
    cout << "0 - back" << endl;

    while (!(cin >> searchChoice) || searchChoice < 0 || searchChoice > 6) {
        cout << "Wrong choice. Enter 0-6: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (searchChoice) {
    case 1:
        searchByBrand();
        break;

    case 2:
        searchByModel();
        break;

    case 3:
        searchByYear();
        break;

    case 4:
        searchByPrice();
        break;

    case 5:
        searchByBody();
        break;

    case 6:
        searchBySegment();
        break;

    case 0:
        break;

    default:
        break;
    }
}

void searchByBrand() {
    Car car;
    char searchBrand[30];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Brand: ";
    cin.getline(searchBrand, 30);

    while (cin.fail() || strlen(searchBrand) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Brand is too long. Maximum 29 characters" << endl;
        } else {
            cout << "Brand cannot be empty" << endl;
        }

        cin.getline(searchBrand, 30);
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (strstr(car.brand, searchBrand) != nullptr) {
                printCar(car);
            }
        }

        file.close();
    }
}

void searchByModel() {
    Car car;
    char searchModel[30];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter model: " << endl;
    cin.getline(searchModel, 30);

    while (cin.fail() || strlen(searchModel) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Model is too long. Maximum characters 29" << endl;
        } else {
            cout << "Model cannot be empty" << endl;
        }

        cin.getline(searchModel, 30);
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (strstr(car.model, searchModel) != nullptr) {
                printCar(car);
            }
        }

        file.close();
    }
}

void searchByYear() {
    Car car;
    int minYear;
    int maxYear;

    cout << "From year: " << endl;

    while (!(cin >> minYear) || minYear < 1886 || minYear > 2026) {
        cout << "Wrong year. Enter year from 1886 to 2026" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "To year: " << endl;

    while (!(cin >> maxYear) || maxYear < 1886 ||
           maxYear > 2026 || maxYear < minYear) {
        cout << "Wrong year. Enter year from " << minYear << " to 2026: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (car.year >= minYear && car.year <= maxYear) {
                printCar(car);
            }
        }

        file.close();
    }
}

void searchByPrice() {
    Car car;
    int minPrice;
    int maxPrice;

    cout << "From price" << endl;

    while (!(cin >> minPrice) || minPrice < 1) {
        cout << "Wrong price. Enter correct price." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "To price" << endl;

    while (!(cin >> maxPrice) || maxPrice < 1 || maxPrice < minPrice) {
        cout << "Wrong price. Enter correct price." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (car.price >= minPrice && car.price <= maxPrice) {
                printCar(car);
            }
        }

        file.close();
    }
}

void searchByBody() {
    Car car;
    char searchBody[20];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter body: " << endl;
    cin.getline(searchBody, 20);

    while (cin.fail() || strlen(searchBody) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Body is too long. Maximum characters 19" << endl;
        } else {
            cout << "Body cannot be empty" << endl;
        }

        cin.getline(searchBody, 20);
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (strstr(car.body, searchBody) != nullptr) {
                printCar(car);
            }
        }

        file.close();
    }
}

void searchBySegment() {
    Car car;
    char searchSegment[10];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter segment: " << endl;
    cin.getline(searchSegment, 10);

    while (cin.fail() || strlen(searchSegment) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Segment is too long. Maximum characters 9" << endl;
        } else {
            cout << "Segment cannot be empty" << endl;
        }

        cin.getline(searchSegment, 10);
    }

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            if (strstr(car.segment, searchSegment) != nullptr) {
                printCar(car);
            }
        }

        file.close();
    }
}

#endif
