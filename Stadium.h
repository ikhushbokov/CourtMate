#pragma once
#include <iostream>
#include <string>
#include <vector>

class Stadium {
protected:
    int id;
    std::string name;
    std::string location;
    std::string type;
    float pricePerHour;
    float rating;
    int totalRatings;
    float ratingSum;
    int openHour;  // Opening hour (e.g., 8 AM)
    int closeHour; // Closing hour (e.g., 10 PM)
    std::vector<int> availableHours; // List of available hours for booking

public:
    Stadium();
    Stadium(int id, std::string name, std::string location, std::string type, float price, int open, int close);
    virtual ~Stadium();

    virtual void displayInfo() const;
    void rateStadium(int stars);
    void rateStadium(float stars);  // Overloaded

    int getID() const;
    std::string getName() const;
    std::string getType() const;
    std::string getLocation() const;
    float getPrice() const;
    float getRating() const;
    int getOpenHour() const;
    int getCloseHour() const;
    const std::vector<int>& getAvailableHours() const;

    // File I/O support
    virtual std::string serialize() const;
    virtual void deserialize(const std::string& data);

    // New methods for managing available hours
    void addAvailableHour(int hour);
    bool isAvailableAt(int hour) const;
};

