#pragma once
#include <string>

class Stadium {
protected:
    int id = 0;
    std::string name;
    std::string location;
    float pricePerHour = 0;
    float rating = 0;

public:
    Stadium() = default;
    Stadium(int id, const std::string& name, const std::string& location, float price, float rating);

    virtual ~Stadium() = default;

    void setName(const std::string& name) { this->name = name; }
    void setLocation(const std::string& location) { this->location = location; }
    void setPrice(float price) { this->pricePerHour = price; }
    void setRating(float rating) { this->rating = rating; }

    int getID() const { return id; }
    std::string getName() const { return name; }
    std::string getLocation() const { return location; }
    float getPricePerHour() const;
    float getRating() const { return rating; }

    virtual std::string getType() const = 0;
    virtual void displayInfo() const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
};
