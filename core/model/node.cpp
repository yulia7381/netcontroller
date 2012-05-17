#include "node.h"

#include <iostream>

std::ostream& operator<< (std::ostream& os, const Node& n){
	os << n.getId() << "\n";
	os << n.getName() << "\n";
	os << n.getCode() << "\n";
	os << n.getPosition() << "\n";
	return os;
}

std::istream& operator>> (std::istream& is, Node& n) {
	unsigned long id;
	std::string name;
	std::string code;
	Position pos;

	is >> id >> name >> code >> pos;

	n = Node(id, name, code, pos);
	return is;
}