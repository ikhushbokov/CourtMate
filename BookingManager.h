#pragma once
#include "Booking.h"
#include "StadiumManager.h"
#include <vector>

class BookingManager {
private:
    std::vector<Booking*> bookings;
    StadiumManager* stadiumManager;  // Adding a reference to StadiumManager to access stadium info

public:
    BookingManager(StadiumManager* stadiumMgr);  // Constructor should accept a StadiumManager reference
    ~BookingManager();

    void addBooking(Booking* booking);
    void displayAllBookings() const;
    bool isBookingAvailable(const Booking& newBooking) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
