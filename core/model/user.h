#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "enums.h"

namespace core {

    class User {
    public:
        User(unsigned long id, std::string name, std::string password_hash, UserRole role) 
            : id(id), name(name), password_hash(password_hash), role(role) {};
        User() : id(0), name(""), password_hash(""), role(UNDEFINED) {};
        User(const User& user) : id(user.id), name(user.name), password_hash(user.password_hash), role(role) {};
        User(User& user) : id(user.id), name(user.name), password_hash(user.password_hash), role(role) {};


        unsigned long getId() const {return id;}
        std::string getName() const {return name;}
        std::string getPasswordHash() const {return password_hash;};
        UserRole getRole() const {return role;}
    private:
        unsigned long id;
        std::string name;
        std::string password_hash;
        UserRole role;
    };

    std::istream& operator>> (std::istream& is, User& u);
    std::ostream& operator<< (std::ostream& os, const User& u);

    bool operator== (const User& u1, const User& u2);
    bool operator!= (const User& u1, const User& u2);

}
#endif