#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Review {
private:
    std::string username;
    std::string stadiumName;
    std::string comment;
    int rating; // от 1 до 5

public:
    Review();
    Review(const std::string& username, const std::string& stadiumName, const std::string& comment, int rating);

    std::string getUsername() const;
    std::string getStadiumName() const;
    std::string getComment() const;
    int getRating() const;

    void display() const;
};

#endif

