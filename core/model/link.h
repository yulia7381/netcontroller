#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link {
public:
	Link(unsigned long id, const Node &node1, const Node &node2) : id(id), node1(node1), node2(node2) {};
	Link(const Link& link) : id(link.id), node1(link.node1), node2(link.node2) {};

	const unsigned long getId() {return id;}
	const Node& getNode1() {return node1;}
	const Node& getNode2() {return node2;}
private:
	unsigned long id;
	Node node1;
	Node node2;
};

#endif
