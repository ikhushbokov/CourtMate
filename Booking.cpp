#include "Booking.h"
#include <sstream>
#include <iostream>
#include <sstream>   // для std::istringstream
#include <string>    // для std::string и getline

using namespace std;

int Booking::bookingCounter = 1000;

Booking::Booking() : stadiumID(0), userName(""), bookingID(bookingCounter++), stadium(nullptr) {}

Booking::Booking(int stadiumID, string userName, TimeSlot slot, Stadium* stadium)
    : stadiumID(stadiumID), userName(userName), timeSlot(slot), bookingID(bookingCounter++), stadium(stadium) {
}

int Booking::getStadiumID() const { return stadiumID; }
TimeSlot Booking::getTimeSlot() const { return timeSlot; }
string Booking::getUserName() const { return userName; }
int Booking::getBookingID() const { return bookingID; }

void Booking::displayBookingInfo() const {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Customer: " << userName << endl;
    cout << "Date: " << timeSlot.date << ", Start Hour: " << timeSlot.startHour
        << ", Duration: " << timeSlot.duration << " hours" << endl;

    if (stadium) {
        cout << "Stadium ID: " << stadiumID << ", Name: " << stadium->getName() << endl;
    }
    else {
        cout << "Stadium info not available.\n";
    }
}

void Booking::setStadium(Stadium* stadiumPtr) {
    stadium = stadiumPtr;
}

bool Booking::conflictsWith(const Booking& other) const {
    return stadiumID == other.stadiumID && timeSlot == other.timeSlot;
}

string Booking::serialize() const {
    ostringstream oss;
    oss << bookingID << ',' << stadiumID << ',' << userName << ','
        << timeSlot.date << ',' << timeSlot.startHour << ',' << timeSlot.duration << '\n';
    return oss.str();
}

void Booking::deserialize(const string& data) {
    istringstream iss(data);
    string token;
    getline(iss, token, ','); bookingID = stoi(token);
    getline(iss, token, ','); stadiumID = stoi(token);
    getline(iss, userName, ',');
    getline(iss, timeSlot.date, ',');
    getline(iss, token, ','); timeSlot.startHour = stoi(token);
    getline(iss, token, ','); timeSlot.duration = stoi(token);
}
