#pragma once
#include "StadiumManager.h"
#include "BookingManager.h"
#include "user.h"
#include <iostream>

class MenuSystem {
public:
    MenuSystem();
    void run();

private:
    StadiumManager stadiumManager;
    BookingManager bookingManager;
    UserManager userManager;

    void showMenu();
    void handleInput();
    void viewStadiums();
    void bookStadium();
    void addStadium();
    void viewStadiumDetails(int stadiumID);
    void editStadium();
    void removeStadium();
    void addReview();
    void viewReviews();


};
