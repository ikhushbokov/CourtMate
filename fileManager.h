#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include <string>
#include "user.h"
#include "review.h"

class FileManager {
public:
    static void saveUsers(const std::vector<User>& users, const std::string& filename);
    static void loadUsers(std::vector<User>& users, const std::string& filename);

    static void saveReviews(const std::vector<Review>& reviews, const std::string& filename);
    static void loadReviews(std::vector<Review>& reviews, const std::string& filename);
};

#endif

