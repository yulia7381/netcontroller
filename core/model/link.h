#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link {
public:
	Link(uint id, Node node1, Node node2) : id(id), node1(node1), node2(node2) {};
private:
	uint id;
	Node node1;
	Node node2;
};

#endif