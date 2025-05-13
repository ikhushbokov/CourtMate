#pragma once
#include <string>
#include <iostream>

class Review {
private:
    std::string username;
    std::string stadiumName;
    std::string comment;
    int rating;

public:
    Review() = default;
    Review(const std::string& user, const std::string& stadium, const std::string& comment, int rating);

    std::string getUsername() const;
    std::string getStadiumName() const;
    std::string getComment() const;
    int getRating() const;

    std::string serialize() const;
    static Review deserialize(const std::string& data);

    void display() const;
};
