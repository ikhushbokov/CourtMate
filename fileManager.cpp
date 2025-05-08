#include "fileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FileManager::saveUsers(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при сохранении пользователей.\n";
        return;
    }

    for (const auto& user : users) {
        file << user.getUsername() << "," << "placeholder_password"; // пароли не сохраняются для простоты
        file << "\n";
    }

    file.close();
}

void FileManager::loadUsers(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Файл пользователей не найден.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.emplace_back(username, password);
    }

    file.close();
}

void FileManager::saveReviews(const std::vector<Review>& reviews, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при сохранении отзывов.\n";
        return;
    }

    for (const auto& review : reviews) {
        file << review.getUsername() << "," << review.getStadiumName() << "," << review.getRating() << "," << review.getComment() << "\n";
    }

    file.close();
}

void FileManager::loadReviews(std::vector<Review>& reviews, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Файл отзывов не найден.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string username, stadium, ratingStr, comment;
        getline(ss, username, ',');
        getline(ss, stadium, ',');
        getline(ss, ratingStr, ',');
        getline(ss, comment);

        int rating = std::stoi(ratingStr);
        reviews.emplace_back(username, stadium, comment, rating);
    }

    file.close();
}
