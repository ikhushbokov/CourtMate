#include "Stadium.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

Stadium::Stadium() : id(0), name(""), location(""), type(""), pricePerHour(0), rating(0), totalRatings(0), ratingSum(0), openHour(0), closeHour(0) {}

Stadium::Stadium(int id, string name, string location, string type, float price, int open, int close)
    : id(id), name(name), location(location), type(type), pricePerHour(price), rating(0), totalRatings(0), ratingSum(0), openHour(open), closeHour(close) {}

Stadium::~Stadium() {}

void Stadium::displayInfo() const {
    cout << "ID: " << id << ", Name: " << name << ", Type: " << type
         << ", Location: " << location << ", Price/Hour: " << pricePerHour << " sums/hour"
         << ", Rating: " << rating << "/5.0"
         << ", Available Hours: ";
    for (int hour : availableHours) {
        cout << hour << " ";
    }
    cout << endl;
}

void Stadium::rateStadium(int stars) {
    if (stars < 1 || stars > 5) return;
    ratingSum += stars;
    totalRatings++;
    rating = ratingSum / totalRatings;
}

void Stadium::rateStadium(float stars) {
    if (stars < 1.0 || stars > 5.0) return;
    ratingSum += stars;
    totalRatings++;
    rating = ratingSum / totalRatings;
}

int Stadium::getID() const { return id; }
string Stadium::getType() const { return type; }
string Stadium::getLocation() const { return location; }
float Stadium::getPrice() const { return pricePerHour; }
float Stadium::getRating() const { return rating; }
int Stadium::getOpenHour() const { return openHour; }
int Stadium::getCloseHour() const { return closeHour; }
std::string Stadium::getName() const { return name; }


const std::vector<int>& Stadium::getAvailableHours() const { return availableHours; }

void Stadium::addAvailableHour(int hour) {
    if (hour >= openHour && hour <= closeHour) {
        availableHours.push_back(hour);
        sort(availableHours.begin(), availableHours.end()); // Keep hours sorted
    }
}

bool Stadium::isAvailableAt(int hour) const {
    return find(availableHours.begin(), availableHours.end(), hour) != availableHours.end();
}

string Stadium::serialize() const {
    ostringstream oss;
    oss << id << ',' << name << ',' << location << ',' << type << ',' << pricePerHour << ',' << rating << ',' << openHour << ',' << closeHour << '\n';
    return oss.str();
}

void Stadium::deserialize(const string& data) {
    istringstream iss(data);
    getline(iss, name, ',');
    getline(iss, location, ',');
    getline(iss, type, ',');
    iss >> pricePerHour >> rating >> openHour >> closeHour;
}

