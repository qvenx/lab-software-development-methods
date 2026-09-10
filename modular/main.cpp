#include <iostream>
#include <limits>

#include "functions.h"

using namespace std;

int main(){
    int choice;

    do {
        cout << "1 - Add car" << endl;
        cout << "2 - Show all" << endl;
        cout << "3 - Search" << endl;
        cout << "0 - Exit" << endl;
        
        while (!(cin >> choice) || choice < 0 || choice > 3) {
            cout << "Enter a number: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1: 
            addCar();
                break;
            
            case 2: 
            showAll();
                break;
            
            case 3: 
            findCar();
                break;
            
            case 0: 
            cout << "Exit" << endl;
                break;

            default:
            cout << "Wrong choice" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}