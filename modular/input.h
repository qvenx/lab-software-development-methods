#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

#include "output.h"

using namespace std;

void addCar();

void addCar() {
    Car car;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Brand: ";
    cin.getline(car.brand, 30);

    while (cin.fail() || strlen(car.brand) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Brand is too long. Maximum 29 characters: ";
        } else {
            cout << "Brand cannot be empty" << endl;
        }

        cin.getline(car.brand, 30);
    }

    cout << "Model: ";
    cin.getline(car.model, 30);

    while (cin.fail() || strlen(car.model) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Model is too long. Maximum 29 characters" << endl;
        } else {
            cout << "Model cannot be empty" << endl;
        }

        cin.getline(car.model, 30);
    }

    cout << "Year: ";

    while (!(cin >> car.year) || car.year < 1886 || car.year > 2026) {
        cout << "Wrong year. Enter year from 1886 to 2026" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Price: ";

    while (!(cin >> car.price) || car.price <= 0) {
        cout << "Wrong price. Enter positive number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Body: ";
    cin.getline(car.body, 20);

    while (cin.fail() || strlen(car.body) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Body car is too long. Maximum 19 characters" << endl;
        } else {
            cout << "Body car cannot be empty" << endl;
        }

        cin.getline(car.body, 20);
    }

    cout << "Segment: ";
    cin.getline(car.segment, 10);

    while (cin.fail() || strlen(car.segment) == 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Segment is too long. Maximum 9 characters" << endl;
        } else {
            cout << "Segment cannot be empty" << endl;
        }

        cin.getline(car.segment, 10);
    }

    ofstream file("cars.dat", ios::binary | ios::app);

    if (!file) {
        cout << "File open error" << endl;
    } else {
        file.write(reinterpret_cast<char*>(&car), sizeof(Car));
        file.close();

        cout << "Car added." << endl;
    }
}

#endif
