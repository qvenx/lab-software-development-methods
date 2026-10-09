#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

struct Car {
    char brand[30];
    char model[30];
    int year;
    int price;
    char body[20];
    char segment[10];
};

using namespace std;

void showAll();
void printHeader();
void printCar(const Car& car);

void showAll() {
    Car car;

    ifstream file("cars.dat", ios::binary);

    if (!file) {
        cout << "Error file read" << endl;
    } else {
        printHeader();

        while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
            printCar(car);
        }

        file.close();
    }
}

void printHeader() {
    cout << left
         << setw(31) << "Brand"
         << setw(31) << "Model"
         << setw(21) << "Body"
         << setw(11) << "Segment"
         << setw(8) << "Year"
         << setw(14) << "Price"
         << endl;

    cout << string(116, '-') << endl;
}

void printCar(const Car& car) {
    cout << left
         << setw(31) << car.brand
         << setw(31) << car.model
         << setw(21) << car.body
         << setw(11) << car.segment
         << setw(8) << car.year
         << setw(14) << car.price
         << endl;
}

#endif
