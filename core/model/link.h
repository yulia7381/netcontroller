#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link {
public:
	Link(unsigned int id, Node node1, Node node2) : id(id), node1(node1), node2(node2) {};
private:
	unsigned int id;
	Node node1;
	Node node2;
};

#endif