#ifndef GRAPH_H
#define GRAPH_H

#include "link.h"

class Graph {
public:
    Graph(std::list<Link> links) : links(link) {};
private:
    std::list<Link> links;
};

#endif