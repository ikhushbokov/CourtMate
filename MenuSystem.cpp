#include "MenuSystem.h"
#include "FootballStadium.h"
#include "BasketballStadium.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Review.h"

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
    cout << "6. Clear Screen\n"; // 🔁 было 5
    cout << "7. Edit Stadium\n";
    cout << "8. Remove Stadium\n";
    cout << "9. Logout\n";// 🔁 было Exit
    cout << "10. Add Review\n";
    cout << "11. View Reviews\n";

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
        case 5: bookingManager.displayAllBookings(); break;
        case 6: system("cls"); break; // Очистка экрана
        case 7: editStadium(); break;
        case 8: removeStadium(); break;
        case 9:
            cout << "You have been logged out.\n";
            userManager.logout();
            run();
            return;
        case 10: addReview(); break;
        case 11: viewReviews(); break;
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
void MenuSystem::editStadium() {
    int stadiumID;
    cout << "Enter Stadium ID to edit: ";
    cin >> stadiumID;
    Stadium* stadium = stadiumManager.getStadiumByID(stadiumID);
    if (!stadium) {
        cout << "Stadium not found.\n";
        return;
    }

    string name, location;
    float price, rating;

    cin.ignore();
    cout << "Enter new name (" << stadium->getName() << "): ";
    getline(cin, name);
    cout << "Enter new location (" << stadium->getLocation() << "): ";
    getline(cin, location);
    cout << "Enter new price per hour (" << stadium->getPricePerHour() << "): ";

    cin >> price;
    cout << "Enter new rating (" << stadium->getRating() << "): ";
    cin >> rating;

    stadium->setName(name);
    stadium->setLocation(location);
    stadium->setPrice(price);
    stadium->setRating(rating);

    cout << "Stadium updated successfully.\n";
}

void MenuSystem::removeStadium() {
    int stadiumID;
    cout << "Enter Stadium ID to remove: ";
    cin >> stadiumID;

    // Подтверждение удаления
    cout << "Are you sure you want to remove stadium with ID " << stadiumID << "? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm != 'y' && confirm != 'Y') {
        cout << "Operation canceled.\n";
        return;
    }

    if (stadiumManager.removeStadium(stadiumID)) {
        cout << "Stadium removed successfully.\n";
    }
    else {
        cout << "Stadium not found.\n";
    }
}

void MenuSystem::addReview() {
    cin.ignore();
    string stadiumName, comment;
    int rating;

    cout << "Enter stadium name to review: ";
    getline(cin, stadiumName);
    cout << "Enter your comment: ";
    getline(cin, comment);
    cout << "Enter your rating (0-5): ";
    cin >> rating;

    Review review(userManager.getCurrentUsername(), stadiumName, comment, rating);

    ofstream file("reviews.txt", ios::app);
    file << review.serialize();
    file.close();

    cout << "Review added.\n";
}

void MenuSystem::viewReviews() {
    ifstream file("reviews.txt");
    if (!file.is_open()) {
        cout << "No reviews found.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        Review review = Review::deserialize(line);
        review.display();
        cout << "-----------------\n";
    }
    file.close();
}

