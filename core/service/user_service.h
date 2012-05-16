#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <string>
#include <map>

#include "../model/user.h"

class UserService {
public:
    const User& getUser(unsigned long id) const;
    const User& getUser(std::string& login) const;

    bool checkAccess(std::string& login, std::string& password) const;

    bool createUser(const User& user);
    bool deleteUser(unsigned long id);

    UserService();
    ~UserService();
private:
    std::map<unsigned long, User> users;
    std::map<std::string, User> user_logins;

    unsigned long next_id;
    User empty_user;

    bool save();
    void read();

};

#endif