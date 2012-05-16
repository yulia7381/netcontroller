#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <string>

#include "../model/user.h"

class UserService {
public:
    User& getUser(unsigned long id) const;
    User& getUser(std::string& login) const;

    bool checkAccess(std::string& login, std::string& password) const;

    bool createUser(const User& user);
    bool deleteUser(unsigned long id);

    UserService();
    ~UserService();
private:
    std::map<unsigned long, User> users;
    std::map<std::string, User> user_logins;

    unsigned long next_id;

    bool save();
    void read();

};

#endif