#include "../core/model/user.h"
#include "../core/service/user_service.h"


#include <string>
#include <iostream>

int main(int argc, char **argv) {
    if (argc <= 3) {
        std::cout << "Usage:\n     ncr_add_user $name $password $role" << std::endl;
        return -1;
    }

    UserService us;
    std::string name = argv[1];
    std::string password = argv[2];
    int role = atoi(argv[3]);

    bool result = us.createUser(User(-1, name, password, UserRole(role)));
    if (result) {
        std::cout << "User " + name + " created." << std::endl;
    } else { 
        std::cerr << "Some error occured. Hope this message is helpful." << std::endl;
    }
}

