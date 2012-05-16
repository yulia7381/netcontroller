#ifndef USER_H
#define USER_H

#include <string>

#include "enums.h"

class User {
public:
    User(unsigned int id, std::string name, std::string password_hash, UserRole role) : id(id), name(name), password_hash(password_hash), role(role) {};
private:
    unsigned int id;
    std::string name;
    std::string password_hash;
    UserRole role;
};

#endif