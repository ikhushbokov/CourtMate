#pragma once
#include "StadiumManager.h"
#include "BookingManager.h"
#include "CustomExceptions.h"
#include <iostream>

class MenuSystem {
public:
    MenuSystem();
    void run();
private:
    void showMenu();
    void handleInput();
    void viewStadiums();
    void bookStadium();
    void addStadium(); // Add this
    void viewStadiumDetails(int stadiumID); // Add this for viewing full details of a stadium
};
