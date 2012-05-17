#include "user.h"

#include "enums.h"

#include <string>

std::istream& operator>> (std::istream& is, User& u) {
	unsigned long id;
	std::string name;
	std::string password_hash;
	int role;

	is >> id;
	is >> name;
	is >> password_hash;
	is >> role;
	u = User(id, name, password_hash, UserRole(role));
}

std::ostream& operator<< (std::ostream& os, const User& u) {
	os << u.getId() << "\n";
	os << u.getName() << "\n";
	os << u.getPasswordHash() << "\n";
	os << u.getRole() << "\n";

	return os;
}

bool operator== (const User& u1, const User& u2) {
	return u1.getId() == u2.getId()
		&& u1.getName() == u2.getName()
		&& u1.getPasswordHash() == u2.getPasswordHash()
		&& u1.getRole() == u2.getRole();
}

bool operator!= (const User& u1, const User& u2) {
	return !(u1 == u2);
}