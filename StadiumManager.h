#pragma once
#include "Stadium.h"
#include <vector>
#include <fstream>

class StadiumManager {
private:
    std::vector<Stadium*> stadiums;


public:
    StadiumManager();
    ~StadiumManager();

    void addStadium(Stadium* stadium);
    void displayAllStadiums() const;
    void displayStadiumDetails(int stadiumID) const; // Display full details for a stadium by ID
    void searchStadiumsByType(const std::string& type) const;
    void searchStadiumsByLocation(const std::string& location) const;
    void searchStadiumsByRating(float rating) const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    Stadium* getStadiumByID(int id) const;

};

