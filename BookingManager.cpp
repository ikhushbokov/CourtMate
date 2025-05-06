#include "BookingManager.h"
#include <iostream>
#include <fstream>

using namespace std;

BookingManager::BookingManager(StadiumManager* stadiumMgr) : stadiumManager(stadiumMgr) {}

BookingManager::~BookingManager() {
    for (Booking* booking : bookings) {
        delete booking;
    }
}

void BookingManager::addBooking(Booking* booking) {
    bookings.push_back(booking);
}

void BookingManager::displayAllBookings() const {
    for (const Booking* booking : bookings) {
        // Retrieve the stadium details associated with the booking
        int stadiumID = booking->getStadiumID();
        Stadium* stadium = stadiumManager->getStadiumByID(stadiumID); // Assuming you implement getStadiumByID

        cout << "Booking ID: " << booking->getBookingID()
             << " Stadium ID: " << stadium->getID()
             << " Name: " << stadium->getName()
             << " Location: " << stadium->getLocation()
             << " Type: " << stadium->getType()
             << " Price/Hour: " << stadium->getPrice() << " sums/hour"
             << " User: " << booking->getUserName()
             << " Date: " << booking->getTimeSlot().date
             << " Time: " << booking->getTimeSlot().startHour << endl;
    }
}

bool BookingManager::isBookingAvailable(const Booking& newBooking) const {
    for (const Booking* existingBooking : bookings) {
        if (existingBooking->conflictsWith(newBooking)) {
            return false;
        }
    }
    return true;
}

void BookingManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Booking* booking : bookings) {
            file << booking->serialize();
        }
        file.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}

void BookingManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Booking* booking = new Booking();
            booking->deserialize(line);
            addBooking(booking);
        }
        file.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}
