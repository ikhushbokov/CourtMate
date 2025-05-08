#pragma once
#include <string>

class Stadium {
protected:
    int id;
    std::string name;
    std::string location;
    float pricePerHour;
    float rating;

public:
    Stadium() = default;
    Stadium(int id, const std::string& name, const std::string& location, float price, float rating);

    virtual ~Stadium() = default;

    int getID() const;
    std::string getName() const;
    std::string getLocation() const;
    float getPricePerHour() const;
    float getRating() const;

    virtual std::string getType() const = 0;

    virtual void displayInfo() const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
};
