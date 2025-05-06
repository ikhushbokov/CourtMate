#include <iostream>
#include "MenuSystem.h"
#include "StadiumManager.h"
#include "BookingManager.h"
#include "CustomExceptions.h"
using namespace std;


int main() {
    try {
        MenuSystem menu;
        menu.run();  // Load, interact, and save
    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
    return 0;
}
