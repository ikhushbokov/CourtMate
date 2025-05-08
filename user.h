#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;
    std::vector<std::string> bookingHistory;

public:
    User();
    User(const std::string& username, const std::string& password);

    std::string getUsername() const;
    bool checkPassword(const std::string& input) const;

    void addBookingToHistory(const std::string& bookingInfo);
    const std::vector<std::string>& getBookingHistory() const;

    void displayBookingHistory() const;
};
class UserManager {
private:
    std::vector<User> users;
    std::string currentUsername;

public:
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    std::string getCurrentUsername() const;
    void saveSession() const;
    void loadSession();
    void logout();
};
#endif

