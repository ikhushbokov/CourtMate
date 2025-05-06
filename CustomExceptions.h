#pragma once
#include <stdexcept>

class BookingConflictException : public std::runtime_error {
public:
    BookingConflictException() : std::runtime_error("Time slot is already booked.") {}
};

class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& msg) : std::runtime_error(msg) {}
};
