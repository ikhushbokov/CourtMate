#include "StadiumManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "FootballStadium.h"
#include "BasketballStadium.h"

using namespace std;

Stadium* StadiumManager::getStadiumByID(int id) const {
    for (Stadium* stadium : stadiums) {
        if (stadium->getID() == id) {
            return stadium;
        }
    }
    return nullptr;
}


StadiumManager::StadiumManager() {}

StadiumManager::~StadiumManager() {
    for (Stadium* stadium : stadiums) {
        delete stadium;
    }
}

void StadiumManager::addStadium(Stadium* stadium) {
    stadiums.push_back(stadium);
}

void StadiumManager::displayAllStadiums() const {
    for (const Stadium* stadium : stadiums) {
        stadium->displayInfo();
    }
}

void StadiumManager::displayStadiumDetails(int stadiumID) const {
    for (const Stadium* stadium : stadiums) {
        if (stadium->getID() == stadiumID) {
            stadium->displayInfo(); // Display full info for this stadium
            return;
        }
    }
    cout << "Stadium with ID " << stadiumID << " not found." << endl;
}

void StadiumManager::searchStadiumsByType(const string& type) const {
    for (const Stadium* stadium : stadiums) {
        if (stadium->getType() == type) {
            stadium->displayInfo();
        }
    }
}

void StadiumManager::searchStadiumsByLocation(const string& location) const {
    for (const Stadium* stadium : stadiums) {
        if (stadium->getLocation() == location) {
            stadium->displayInfo();
        }
    }
}

void StadiumManager::searchStadiumsByRating(float rating) const {
    for (const Stadium* stadium : stadiums) {
        if (stadium->getRating() >= rating) {
            stadium->displayInfo();
        }
    }
}

void StadiumManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        getline(ss, type, ',');

        Stadium* stadium = nullptr;
        if (type == "Football") {
            stadium = new FootballStadium();
        }
        else if (type == "Basketball") {
            stadium = new BasketballStadium();
        }
        else {
            continue; // skip unknown type
        }

        stadium->deserialize(line);
        stadiums.push_back(stadium);
    }

    file.close();
}


void StadiumManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Stadium* stadium : stadiums) {
            file << stadium->serialize();
        }
        file.close();
    }
    else {
        cerr << "Unable to open file." << endl;
    }
}
