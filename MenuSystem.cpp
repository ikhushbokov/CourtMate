#include "MenuSystem.h"
#include "FootballStadium.h"
#include "BasketballStadium.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

MenuSystem::MenuSystem() : bookingManager(&stadiumManager) {
    stadiumManager.loadFromFile("stadiums.txt");
    bookingManager.loadFromFile("bookings.txt");
    userManager.loadFromFile("users.txt");
}

void MenuSystem::run() {
    stadiumManager.loadFromFile("stadiums.txt");
    bookingManager.loadFromFile("bookings.txt");
    userManager.loadFromFile("users.txt");
    userManager.loadSession(); // 🟢 загрузка текущей сессии

    if (!userManager.getCurrentUsername().empty()) {
        cout << "Welcome back, " << userManager.getCurrentUsername() << "!\n";
    }
    else {
        std::string choice;
        cout << "\n=== Welcome to the Stadium Booking System ===\n";
        cout << "1 - Login\n";
        cout << "2 - Register\n";
        cout << "Enter your choice: ";
        cin >> choice;

        std::string uname, pword;
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pword;

        if (choice == "1") {
            if (!userManager.loginUser(uname, pword)) {
                cout << "Login failed. Exiting program.\n";
                return;
            }
        }
        else if (choice == "2") {
            if (!userManager.registerUser(uname, pword)) {
                cout << "Registration failed. Exiting program.\n";
                return;
            }
        }
        else {
            cout << "Invalid choice. Exiting program.\n";
            return;
        }

        userManager.saveSession(); // 🟢 сохранить сессию
    }

    cout << "Welcome, " << userManager.getCurrentUsername() << "!\n";

    // 🔁 Запуск основного меню
    handleInput();

    // 💾 Сохранение после выхода
    stadiumManager.saveToFile("stadiums.txt");
    bookingManager.saveToFile("bookings.txt");
    userManager.saveToFile("users.txt");
    userManager.saveSession(); // 🔁 сохранить снова, на всякий случай
}


void MenuSystem::showMenu() {
    cout << "\n--- Sports Stadium Booking System ---\n";
    cout << "1. View Stadiums\n";
    cout << "2. Book Stadium\n";
    cout << "3. Add Stadium\n";
    cout << "4. View Stadium Details\n";
    cout << "5. View All Bookings\n";
    cout << "6. Logout\n";  // 🔁 было Exit
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
        case 1: viewStadiums(); break;
        case 2: bookStadium(); break;
        case 3: addStadium(); break;
        case 4: {
            int stadiumID;
            cout << "Enter Stadium ID to view details: ";
            cin >> stadiumID;
            viewStadiumDetails(stadiumID);
            break;
        }
        case 5:
            bookingManager.displayAllBookings();
            break;
        case 6:
            userManager.logout();
            cout << "You have been logged out.\n";
            run(); // ✅ безопасный повторный вход
            return;

            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}


void MenuSystem::viewStadiums() {
    stadiumManager.displayAllStadiums();
}

void MenuSystem::viewStadiumDetails(int stadiumID) {
    stadiumManager.displayStadiumDetails(stadiumID);
}

void MenuSystem::addStadium() {
    int id;
    string name, location, type;
    float pricePerHour;
    float rating;

    cout << "Enter Stadium ID: ";
    cin >> id; cin.ignore();
    cout << "Enter Stadium Name: ";
    getline(cin, name);
    cout << "Enter Stadium Location: ";
    getline(cin, location);
    cout << "Enter Type (Football/Basketball): ";
    getline(cin, type);
    cout << "Enter Price per Hour: ";
    cin >> pricePerHour;
    cout << "Enter Rating (0-5): ";
    cin >> rating;

    Stadium* stadium = nullptr;
    if (type == "Football" || type == "football") {
        stadium = new FootballStadium(id, name, location, pricePerHour, rating);
    }
    else if (type == "Basketball" || type == "basketball") {
        stadium = new BasketballStadium(id, name, location, pricePerHour, rating);
    }
    else {
        cout << "Invalid type.\n";
        return;
    }

    stadiumManager.addStadium(stadium);
    cout << "Stadium added.\n";
}

void MenuSystem::bookStadium() {
    int stadiumID;
    TimeSlot slot;

    cin.ignore();
    cout << "Enter Stadium ID: ";
    cin >> stadiumID;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> slot.date;
    cout << "Enter start hour (0-23): ";
    cin >> slot.startHour;
    cout << "Enter duration in hours: ";
    cin >> slot.duration;

    Stadium* stadium = stadiumManager.getStadiumByID(stadiumID);
    if (!stadium) {
        cout << "Stadium not found.\n";
        return;
    }

    string username = userManager.getCurrentUsername();
    Booking* booking = new Booking(stadiumID, username, slot, stadium);
    if (bookingManager.isBookingAvailable(*booking)) {
        bookingManager.addBooking(booking);
        cout << "Booking successful!\n";
    }
    else {
        delete booking;
        cout << "Time slot not available.\n";
    }
}
