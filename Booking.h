#pragma once
#include <string>
#include "Stadium.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct TimeSlot {
    std::string date;
    int startHour = 0;
    int duration = 1;

    bool operator==(const TimeSlot& other) const {
        return date == other.date &&
            ((startHour < other.startHour + other.duration && startHour >= other.startHour) ||
                (other.startHour < startHour + duration && other.startHour >= startHour));
    }
};


class Booking {
private:
    static int bookingCounter;
    int bookingID;
    int stadiumID;
    std::string userName;
    TimeSlot timeSlot;
    Stadium* stadium;

public:
    Booking();
    Booking(int stadiumID, std::string userName, TimeSlot slot, Stadium* stadium);

    int getStadiumID() const;
    TimeSlot getTimeSlot() const;
    std::string getUserName() const;
    int getBookingID() const;

    void displayBookingInfo() const;
    void setStadium(Stadium* stadiumPtr);  // ✅ новое

    std::string serialize() const;
    void deserialize(const std::string& data);
    bool conflictsWith(const Booking& other) const;
};
