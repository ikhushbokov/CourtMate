#include "review.h"
#include <iostream>

Review::Review() : rating(0) {}

Review::Review(const std::string& username, const std::string& stadiumName, const std::string& comment, int rating)
    : username(username), stadiumName(stadiumName), comment(comment), rating(rating) {
}

std::string Review::getUsername() const {
    return username;
}

std::string Review::getStadiumName() const {
    return stadiumName;
}

std::string Review::getComment() const {
    return comment;
}

int Review::getRating() const {
    return rating;
}

void Review::display() const {
    std::cout << "Пользователь: " << username << "\n";
    std::cout << "Стадион: " << stadiumName << "\n";
    std::cout << "Оценка: " << rating << "/5\n";
    std::cout << "Комментарий: " << comment << "\n\n";
}
