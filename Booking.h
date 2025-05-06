#pragma once
#include <string>
#include "Stadium.h"  // Added to get stadium info for display

struct TimeSlot {
    std::string date;     // Format: YYYY-MM-DD
    int startHour;        // 24-hour format (e.g., 14 for 2 PM)
    int duration;         // In hours

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
    Stadium* stadium; // Pointer to Stadium object for reference

public:
    Booking();
    Booking(int stadiumID, std::string userName, TimeSlot slot, Stadium* stadium);

    int getStadiumID() const;
    TimeSlot getTimeSlot() const;
    std::string getUserName() const;
    int getBookingID() const;
    void displayBookingInfo() const; // Display all booking details

    std::string serialize() const;
    void deserialize(const std::string& data);

    bool conflictsWith(const Booking& other) const;
};
