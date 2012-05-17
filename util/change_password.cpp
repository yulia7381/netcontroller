#include "../core/service/network_status_service.h"
#include "../core/model/user.h"
#include "../core/service/user_service.h"


#include <string>
#include <iostream>

int main(int argc, char **argv) {
    if (argc <= 3) {
        std::cout << "Usage:\n     ncr_ch_pswd $name $old_password $password" << std::endl;
        return -1;
    }

    UserService us;
    std::string name = argv[1];
    std::string old_password = argv[2];
    std::string password = argv[3];

    User user = us.getUser(name);

    if (user.getName() == name) {
        if (!us.checkAccess(name, old_password)) {
            std::cerr << "Wrong password" << std::endl;
            return -1;
        }
        if (us.deleteUser(user.getId()) && us.createUser(User(-1, name, password, user.getRole()))) {
            std::cout << "Password succsesfully changed" << std::endl;
        } else { 
            std::cerr << "Some error occured. Hope this message is helpful." << std::endl;;
        }
    } else {
        std::cerr << "User " + name + " do not exists" << std::endl;
    }
}

