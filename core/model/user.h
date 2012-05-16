#ifndef USER_H
#define USER_H

#include <string>

#include "enums.h"

class User {
public:
    User(unsigned long id, std::string name, std::string password_hash, UserRole role) 
    	: id(id), name(name), password_hash(password_hash), role(role) {};
    User() : id(0), name(""), password_hash(""), role(UNDEFINED) {};

    unsigned long getId() {return id;}
    std::string getName() {return name;}
    std::string getPasswordHash() {return password_hash;};
    UserRole getRole() {return role;}
private:
    unsigned long id;
    std::string name;
    std::string password_hash;
    UserRole role;
};

#endif