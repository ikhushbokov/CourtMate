#include "FootballStadium.h"
#include <iostream>
#include <sstream>

FootballStadium::FootballStadium() {}

FootballStadium::FootballStadium(int id, const std::string& name, const std::string& location, float price, float rating)
    : Stadium(id, name, location, price, rating) {
}

std::string FootballStadium::getType() const {
    return "Football";
}

void FootballStadium::displayInfo() const {
    std::cout << "[Football] ID: " << id << ", Name: " << name
        << ", Location: " << location << ", Price: " << pricePerHour
        << ", Rating: " << rating << std::endl;
}

std::string FootballStadium::serialize() const {
    std::ostringstream oss;
    oss << "Football," << id << "," << name << "," << location << "," << pricePerHour << "," << rating << "\n";
    return oss.str();
}

void FootballStadium::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string token;
    getline(ss, token, ','); // Skip type
    getline(ss, token, ','); id = stoi(token);
    getline(ss, name, ',');
    getline(ss, location, ',');
    getline(ss, token, ','); pricePerHour = stof(token);
    getline(ss, token, ','); rating = stof(token);
}
