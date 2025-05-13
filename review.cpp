#include "Review.h"

Review::Review(const std::string& user, const std::string& stadium, const std::string& comment, int rating)
    : username(user), stadiumName(stadium), comment(comment), rating(rating) {
}

std::string Review::getUsername() const { return username; }
std::string Review::getStadiumName() const { return stadiumName; }
std::string Review::getComment() const { return comment; }
int Review::getRating() const { return rating; }

std::string Review::serialize() const {
    return username + ";" + stadiumName + ";" + comment + ";" + std::to_string(rating) + "\n";
}

Review Review::deserialize(const std::string& data) {
    size_t pos1 = data.find(';');
    size_t pos2 = data.find(';', pos1 + 1);
    size_t pos3 = data.find(';', pos2 + 1);

    std::string user = data.substr(0, pos1);
    std::string stadium = data.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string comment = data.substr(pos2 + 1, pos3 - pos2 - 1);
    int rating = std::stoi(data.substr(pos3 + 1));

    return Review(user, stadium, comment, rating);
}

void Review::display() const {
    std::cout << "User: " << username << "\n"
        << "Stadium: " << stadiumName << "\n"
        << "Comment: " << comment << "\n"
        << "Rating: " << rating << "/5\n";
}
