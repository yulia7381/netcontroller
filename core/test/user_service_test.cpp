#include "../service/user_service.h"
#include "../model/user.h"

#include <string>
#include <iostream>

int main2() {
    core::UserService us;

    std::cout<<us.getUser("user1").getName();
    std::cout<<us.getUser("user2").getName();


    // us.createUser(User(0, "user1", "pass1", ADMIN));
    // us.createUser(User(0, "user2", "pass2", REPAIRER));
    us.createUser(core::User(0, "user3", "pass3", REPAIRER));


    if (us.getUser("user1").getName() != "user1") {
        return 100;
    }

    return 0;
}
