#include "Stadium.h"

Stadium::Stadium(int id, const std::string& name, const std::string& location, float price, float rating)
    : id(id), name(name), location(location), pricePerHour(price), rating(rating) {
}

int Stadium::getID() const { return id; }
std::string Stadium::getName() const { return name; }
std::string Stadium::getLocation() const { return location; }
float Stadium::getPricePerHour() const { return pricePerHour; }
float Stadium::getRating() const { return rating; }
