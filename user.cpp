#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>   // для std::istringstream
using namespace std;

User::User() {}

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
}

std::string User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& input) const {
    return input == password;
}

void User::addBookingToHistory(const std::string& bookingInfo) {
    bookingHistory.push_back(bookingInfo);
}

const std::vector<std::string>& User::getBookingHistory() const {
    return bookingHistory;
}

void User::displayBookingHistory() const {
    if (bookingHistory.empty()) {
        std::cout << "Нет записей о бронированиях.\n";
        return;
    }

    std::cout << "История бронирований:\n";
    for (const auto& booking : bookingHistory) {
        std::cout << "- " << booking << std::endl;
    }
}
bool UserManager::registerUser(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            std::cout << "Пользователь уже существует!\n";
            return false;
        }
    }
    users.emplace_back(username, password);
    currentUsername = username;
    std::cout << "Регистрация успешна!\n";
    return true;
}

bool UserManager::loginUser(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            currentUsername = username;
            std::cout << "Вход выполнен!\n";
            return true;
        }
    }
    std::cout << "Неверный логин или пароль.\n";
    return false;
}

void UserManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string line;
    while (getline(inFile, line)) {
        std::string uname, pword;
        std::istringstream iss(line);
        getline(iss, uname, ',');
        getline(iss, pword, ',');
        users.emplace_back(uname, pword);
    }
    inFile.close();
}

void UserManager::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& user : users) {
        outFile << user.getUsername() << "," << "password_hidden" << "\n"; // ⚠️ необязательно сохранять пароль открыто
    }
    outFile.close();
}

std::string UserManager::getCurrentUsername() const {
    return currentUsername;
}
void UserManager::saveSession() const {
    std::ofstream out("session.txt");
    if (out.is_open()) {
        out << currentUsername;
        out.close();
    }
}

void UserManager::loadSession() {
    std::ifstream in("session.txt");
    if (in.is_open()) {
        getline(in, currentUsername);
        in.close();
    }
}

void UserManager::logout() {
    currentUsername = "";
    std::ofstream out("session.txt", std::ios::trunc); // Очистка файла
    out.close();
}

