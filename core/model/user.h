#ifndef USER_H
#define USER_H

class User {
public:
    User(uint id, std::string name, std::string password_hash, UserRole role) : id(id), name(name), password_hash(password_hash), role(role) {};
private:
    uint id;
    std::string name;
    std::string password_hash;
    UserRole role;
};

#endif