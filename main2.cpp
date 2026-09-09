#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

struct Car {
    char brand[30];
    char model[30];
    int year;
    int price;
    char body[20];
    char segment[10];
};

int main(){
    Car* car = new Car;
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
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Brand: ";
                cin.getline(car->brand, 30);

                while(cin.fail() || strlen(car->brand) == 0){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Brand is too long. Maximum 29 characters: ";
                    } else {
                        cout << "Brand cannot be empty" << endl;
                    }

                    cin.getline(car->brand, 30);
                }

                cout << "Model: ";
                cin.getline(car->model, 30);

                while(cin.fail() || strlen(car->model) == 0){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Model is too long. Maximum 29 characters" << endl;
                    } else {
                        cout << "Model cannot be empty" << endl;
                    }

                    cin.getline(car->model, 30);

                }

                cout << "Year: ";
                while (!(cin >> car->year) || car->year < 1886 || car->year > 2026){
                    cout << "Wrong year. Enter year from 1886 to 2026" << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                cout << "Price: ";
                while(!(cin >> car->price) || car->price <= 0){
                    cout << "Wrong price. Enter positive number: ";

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Body: ";
                cin.getline(car->body, 20);

                while (cin.fail() || strlen(car->body) == 0){
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Body car is too long. Maximum 19 characters" << endl;
                    } else {
                        cout << "Body car cannot be empty" << endl;
                    }
                    cin.getline(car->body, 20);
                }

                cout << "Segment: ";
                cin.getline(car->segment, 10);

                while(cin.fail() || strlen(car->segment) == 0){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Segment is too long. Maximum 9 characters" << endl;
                    } else {
                        cout << "Segment cannot be empty" << endl;
                    }
                    cin.getline(car->segment, 10);
                }

                ofstream file("cars.dat", ios::binary | ios::app);
                if (!file) {
                    cout << "File open error" << endl;
                } else {
                    file.write(reinterpret_cast<char*>(car), sizeof(Car));

                    file.close();

                    cout << "Car added." << endl;
                }

                break;
            }
            case 2: {
                ifstream file("cars.dat", ios::binary);

                if (!file) {
                    cout << "Error file read" << endl;
                } else {
                    while (file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                        cout << "Brand: " << car->brand << endl;
                        cout << "Model: " << car->model << endl;
                        cout << "Year: " << car->year << endl;
                        cout << "Price: " << car->price << endl;
                        cout << "Body: " << car->body << endl;
                        cout << "Segment: " << car->segment << endl;
                        cout << "-------------------" << endl;
                    }

                    file.close();
                }
                break;
            }
            case 3: {
                int searchChoice;

                cout << "search by: " << endl;
                cout << "1 - brand" << endl;
                cout << "2 - model" << endl;
                cout << "3 - year" << endl;
                cout << "4 - price" << endl;
                cout << "5 - body" << endl;
                cout << "6 - segment " << endl;
                cout << "0 - back" << endl;

                while (!(cin >> searchChoice) || searchChoice < 0 || searchChoice > 6){
                    cout << "Wrong choice. Enter 0-6: ";

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                }

                if(searchChoice == 1) {
                    char searchBrand[30];

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Brand: ";
                    cin.getline(searchBrand, 30);

                    while (cin.fail() || strlen(searchBrand) == 0){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Brand is too long. Maximum 29 characters" << endl;
                        } else {
                            cout << "Brand cannot be empty" << endl;
                        }
                        cin.getline(searchBrand, 30);
                    }
                    
                    ifstream file("cars.dat", ios::binary);

                    if(!file) {
                        cout << "File open error" << endl;
                    } else {
                        while (file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if (strcmp(car->brand, searchBrand) == 0){
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                        file.close();
                    }
                }
                if(searchChoice == 2){
                    char searchModel[30];

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter model: " << endl;

                    cin.getline(searchModel, 30);
                    while(cin.fail() || strlen(searchModel) == 0){
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Model is too long. Maximum characters 29" << endl;
                        } else {
                            cout << "Model cannot be empty" << endl;
                        }
                        cin.getline(searchModel, 30);
                    } 

                    ifstream file("cars.dat", ios::binary);

                    if(!file) {
                        cout << "File open error" << endl;
                    } else {
                        while(file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if (strcmp(car->model, searchModel) == 0){
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                    file.close();
                    }
                }
                if (searchChoice == 3){
                    int minYear;
                    int maxYear;
                    cout << "From year: " << endl;
                    while(!(cin >> minYear) || minYear < 1886 || minYear > 2026){
                        cout << "Wrong year. Enter year from 1886 to 2026" << endl;

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "To year: " << endl;
                    while(!(cin >> maxYear) || maxYear < 1886 || maxYear > 2026 || maxYear < minYear){
                        cout << "Wrong year. Enter year from " << minYear << " to 2026: ";

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    ifstream file("cars.dat", ios::binary);
                    if (!file) {
                        cout << "File open error" << endl;
                    } else {
                        while(file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if(car->year >= minYear && car->year <= maxYear){
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                        file.close();
                    }
                }
                if (searchChoice == 4) {
                    int minPrice;
                    int maxPrice;
                    cout << "From price" << endl;
                    while (!(cin >> minPrice) || minPrice < 1){
                        cout << "Wrong price. Enter correct price." << endl;

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "To price" << endl;
                    while (!(cin >> maxPrice) || maxPrice < 1 || maxPrice < minPrice){
                        cout << "Wrong price. Enter correct price." << endl;

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    ifstream file("cars.dat", ios::binary);

                    if (!file) {
                        cout << "File open error" << endl;
                    } else {
                        while (file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if (car->price >= minPrice && car->price <= maxPrice) {
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                        file.close();   
                    }
                }
                if (searchChoice == 5){
                    char searchBody[20];

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter body: " << endl;
                    cin.getline(searchBody, 20);
                    while (cin.fail() || strlen(searchBody) == 0){
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Body is too long. Maximum characters 19" << endl;
                        } else {
                            cout << "Body cannot be empty" << endl;
                        }
                        cin.getline(searchBody, 20);
                    }

                    ifstream file("cars.dat", ios::binary);

                    if(!file){
                        cout << "File open error" << endl;
                    } else {
                        while (file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if(strcmp(searchBody, car->body) == 0){
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                        file.close();
                    }
                }
                if (searchChoice == 6){
                    char searchSegment[10];

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter segment: " << endl;
                    cin.getline(searchSegment, 10);

                    while(cin.fail() || strlen(searchSegment) == 0){
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Segment is too long. Maximum characters 9" << endl;
                        } else {
                            cout << "Segment cannot be empty" << endl;
                        }
                        cin.getline(searchSegment, 10);
                    }
                    
                    ifstream file ("cars.dat", ios::binary);

                    if (!file){
                        cout << "File open error" << endl;
                    } else {
                        while (file.read(reinterpret_cast<char*>(car), sizeof(Car))){
                            if (strcmp(searchSegment, car->segment) == 0){
                                cout << "Brand: " << car->brand << endl;
                                cout << "Model: " << car->model << endl;
                                cout << "Year: " << car->year << endl;
                                cout << "Price: " << car->price << endl;
                                cout << "Body: " << car->body << endl;
                                cout << "Segment: " << car->segment << endl;
                                cout << "-------------------" << endl;
                            }
                        }
                        file.close();
                    }

                }
                break;
            }
            case 0:
                {cout << "Exit" << endl;
                break;}

            default:
            cout << "Wrong choise" << endl;
            break;
        }

    } while (choice != 0);

    delete car;
    return 0;
}