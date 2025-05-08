#include "BookingManager.h"
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

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
        Stadium* stadium = stadiumManager->getStadiumByID(booking->getStadiumID());
        if (stadium) {
            cout << "---------------------------\n";
            cout << "Booking ID: " << booking->getBookingID() << "\n";
            cout << "User: " << booking->getUserName() << "\n";
            cout << "Date: " << booking->getTimeSlot().date
                << " | Time: " << booking->getTimeSlot().startHour
                << " | Duration: " << booking->getTimeSlot().duration << "h\n";
            cout << "Stadium: " << stadium->getName()
                << " | Location: " << stadium->getLocation()
                << " | Type: " << stadium->getType()
                << " | Price: " << stadium->getPricePerHour() << " UZS/hour\n";
        }
        else {
            cout << "Booking ID: " << booking->getBookingID() << " — Stadium not found.\n";
        }
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
    }
    else {
        cerr << "Unable to open file.\n";
    }
}

void BookingManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Booking* booking = new Booking();
            booking->deserialize(line);

            // Восстановление stadium*
            Stadium* stadium = stadiumManager->getStadiumByID(booking->getStadiumID());
            booking->setStadium(stadium);

            addBooking(booking);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file.\n";
    }
}
