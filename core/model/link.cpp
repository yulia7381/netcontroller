#include "link.h"

const Link& Link::operator=(const Link& link) {
	id = link.id;
	node1 = link.node1;
	node2 = link.node2;
	return *this;
}
