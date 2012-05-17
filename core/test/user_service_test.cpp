#include "../service/user_service.h"
#include "../model/user.h"

#include <string>
#include <iostream>

int main() {
	UserService us;
	
	us.createUser(User(0, "user1", "pass1", ADMIN));
	us.createUser(User(0, "user2", "pass2", REPAIRER));

	if (us.getUser(("user1")).getName() != "user1") {
		return 100;
	}
	

}
