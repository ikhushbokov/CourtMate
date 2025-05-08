#include "BasketballStadium.h"
#include <iostream>
#include <sstream>

BasketballStadium::BasketballStadium() {}

BasketballStadium::BasketballStadium(int id, const std::string& name, const std::string& location, float price, float rating)
    : Stadium(id, name, location, price, rating) {
}

std::string BasketballStadium::getType() const {
    return "Basketball";
}

void BasketballStadium::displayInfo() const {
    std::cout << "[Basketball] ID: " << id << ", Name: " << name
        << ", Location: " << location << ", Price: " << pricePerHour
        << ", Rating: " << rating << std::endl;
}

std::string BasketballStadium::serialize() const {
    std::ostringstream oss;
    oss << "Basketball," << id << "," << name << "," << location << "," << pricePerHour << "," << rating << "\n";
    return oss.str();
}

void BasketballStadium::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string token;
    getline(ss, token, ','); // Skip type
    getline(ss, token, ','); id = stoi(token);
    getline(ss, name, ',');
    getline(ss, location, ',');
    getline(ss, token, ','); pricePerHour = stof(token);
    getline(ss, token, ','); rating = stof(token);
}
