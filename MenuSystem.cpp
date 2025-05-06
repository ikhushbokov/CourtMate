#include "MenuSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

MenuSystem::MenuSystem() {}

void MenuSystem::showMenu() {
    cout << "\n--- Sports Stadium Booking System ---\n";
    cout << "1. View Stadiums\n";
    cout << "2. Book Stadium\n";
    cout << "3. Add Stadium\n";
    cout << "4. View Stadium Details\n"; // Add option for full stadium details
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

void MenuSystem::handleInput() {
    int choice;
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                viewStadiums();
                break;
            case 2:
                bookStadium();
                break;
            case 3:
                addStadium();
                break;
            case 4:
                {
                    int stadiumID;
                    cout << "Enter Stadium ID to view details: ";
                    cin >> stadiumID;
                    viewStadiumDetails(stadiumID);
                }
                break;
            case 5:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

void MenuSystem::viewStadiums() {
    ifstream inFile("stadiums.txt");
    string line;
    cout << "\nAvailable Stadiums:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void MenuSystem::bookStadium() {
    int stadiumID;
    string customerName;
    cout << "Enter Stadium ID to book: ";
    cin >> stadiumID;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, customerName);

    // Booking logic here (implement with booking manager or other logic)
    cout << "Stadium booked successfully.\n";
}

void MenuSystem::addStadium() {
    int id, capacity;
    string name, location, type;
    float pricePerHour;
    int availableHoursCount;

    cout << "Enter Stadium ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Stadium Name: ";
    getline(cin, name);

    cout << "Enter Stadium Location: ";
    getline(cin, location);

    cout << "Enter Stadium Type: ";
    getline(cin, type);

    cout << "Enter Price per Hour in Uzbek Sums: ";
    cin >> pricePerHour;

    cout << "Enter number of Available Hours: ";
    cin >> availableHoursCount;
    // Note: You might need to implement the available hours storage and logic

    ofstream outFile("stadiums.txt", ios::app);
    outFile << "ID: " << id << ", Name: " << name << ", Location: " << location
            << ", Type: " << type << ", Price per Hour: " << pricePerHour
            << ", Available Hours: " << availableHoursCount << "\n";
    outFile.close();

    cout << "Stadium added successfully.\n";
}

void MenuSystem::viewStadiumDetails(int stadiumID) {
    // Logic to display all the details of the stadium
    // This could call the StadiumManager's methods to get all the stadium data
    cout << "Fetching details for Stadium ID: " << stadiumID << "...\n";

    // Assuming you have a StadiumManager instance and the stadium exists
    // For simplicity, just displaying sample info (replace with actual call to your stadium manager)
    cout << "ID: " << stadiumID << ", Name: Example Stadium, Location: Someplace, Type: Football, Price: 1000 sums/hour, Rating: 4.5/5\n";
}

void MenuSystem::run() {
    handleInput();
}
