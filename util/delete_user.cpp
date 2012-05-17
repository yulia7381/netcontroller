#include "../core/model/user.h"
#include "../core/service/user_service.h"


#include <string>
#include <iostream>

int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Usage:\n     ncr_delete_user $name $password" << std::endl;
        return -1;
    }

    UserService us;
    std::string name = argv[1];
    std::string password = argv[2];

    User user = us.getUser(name);

    if (user.getName() == name) {
        if (!us.checkAccess(name, password)) {
            std::cerr << "Wrong password" << std::endl;
            return -1;
        }
        if (us.deleteUser(user.getId())) {
            std::cout << "User succsesfully deleted" << std::endl;
        } else { 
            std::cerr << "Some error occured. Hope this message is helpful." << std::endl;;
        }
    } else {
        std::cerr << "User " + name + " do not exists" << std::endl;
    }
}

