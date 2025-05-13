#include "Stadium.h"

Stadium::Stadium(int id, const std::string& name, const std::string& location, float price, float rating)
    : id(id), name(name), location(location), pricePerHour(price), rating(rating) {
}

float Stadium::getPricePerHour() const {
    return pricePerHour;
}
