#pragma once

#include "Stadium.h"

class FootballStadium : public Stadium {
public:
    FootballStadium();
    FootballStadium(int id, const std::string& name, const std::string& location, float price, float rating);

    std::string getType() const override;
    void displayInfo() const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
};
