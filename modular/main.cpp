#include <iostream>
#include <limits>

#include "input.h"
#include "output.h"
#include "search.h"

using namespace std;

// Точка входа: повторяет меню до выбора пункта 0.
int main(){
    int choice; // Выбранный пункт основного меню: 0 — выход, 1–3 — операции.

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
