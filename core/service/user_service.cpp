#include "user_service.h"

#include <fstream>

#define USERS_FILE_NAME "users.ncr"

User& UserService::getUser(unsigned long id) const {
    return users[id];
}

User& UserService::getUser(std::string& login) const {
    return user_logins[login];
}

bool UserService::checkAccess(std::string& login, std::string& password) const {
    User user = getUser(login);
    return user != NULL && user.getPasswordHash() == password;
}

bool UserService::createUser(const User& user) {
    unsigned long new_id = next_id++;
    User new_user = new User(
        new_id,
        user.getName(),
        user.getPasswordHash(),
        user.getRole()
        );

    users.insert(std::pair(new_id, new_user));
    user_logins.insert(std::pair(new_user.getName(), new_user));

    return save();
}

bool UserService::deleteUser(unsigned long id) {
    User user = getUser(id);
    if (user == NULL) {
        return false;
    }

    users.erase(id);
    user_logins.erase(user.getName());

    return save()
}

UserService::UserService() : next_id(1) {
    read();
}

UserService::~UserService() {
    save();
}

bool UserService::save() {
    std::ofstream out(USERS_FILE_NAME, ios::out);

    out << "id:" << next_id << "\n";
    out << "count:" << users.size() << "\n";
    for (map<unsigned int, User>::iterator it = users.begin(); it != users.end(); ++it) {
        out << it->second() << "\n";
    }

    out.close();
    return true;
}

void UserService::read() {
    std::ifstream in(USERS_FILE_NAME, ios::in);
    size_t count = 0;

    if (in.is_open()) {
        in >> next_id >> "\n";
        in >> count >> "\n";

        for (int i = 0; i < count; ++i) {
            User user = new User();
            in >> user >> "\n";

            users.insert(std::pair(user.getId(), user));
            user_logins.insert(std::pair(user.getName(), user));
        }

    }

    in.close();
}