#include "user_service.h"

#include <fstream>
#include <ios>

#define USERS_FILE_NAME "users.ncr"

const User& UserService::getUser(unsigned long id) const {
    std::map<unsigned long, User>::const_iterator it = users.find(id);
    if (it == users.end()) {
        return empty_user;
    } else {
        return it->second;
    }
}

const User& UserService::getUser(const std::string& login) const {
    std::map<std::string, User>::const_iterator it = user_logins.find(login);
    if (it == user_logins.end()) {
        return empty_user;
    } else {
        return it->second;
    }
}

bool UserService::checkAccess(std::string& login, std::string& password) const {
    User user = getUser(login);
    return user != empty_user && user.getPasswordHash() == password;
}

bool UserService::createUser(const User& user) {
    if (getUser(user.getName()) != empty_user) {
        return false;
    }

    unsigned long new_id = next_id++;
    User new_user(
        new_id,
        user.getName(),
        user.getPasswordHash(),
        user.getRole()
        );

    users.insert(std::make_pair(new_id, new_user));
    user_logins.insert(std::make_pair(new_user.getName(), new_user));

    return save();
}

bool UserService::deleteUser(unsigned long id) {
    User user = getUser(id);
    if (user == empty_user) {
        return false;
    }

    users.erase(id);
    user_logins.erase(user.getName());

    return save();
}

UserService::UserService() : next_id(1) {
    read();
}

UserService::~UserService() {
    save();
}

bool UserService::save() {
    std::ofstream out(USERS_FILE_NAME, std::ios::out);

    out << next_id << "\n";
    out << users.size() << "\n";
    for (std::map<unsigned long, User>::iterator it = users.begin(); it != users.end(); ++it) {
        out << it->second << "\n";
    }

    out.close();
    return true;
}

void UserService::read() {
    std::ifstream in(USERS_FILE_NAME, std::ios::in);
    size_t count = 0;

    if (in.is_open()) {
        in >> next_id;
        in >> count;

        for (int i = 0; i < count; ++i) {
            User user;
            in >> user;

            users.insert(std::make_pair(user.getId(), user));
            user_logins.insert(std::make_pair(user.getName(), user));
        }

    }

    in.close();
}
