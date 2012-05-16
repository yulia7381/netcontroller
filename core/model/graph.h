#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#include "link.h"

class Graph {
public:

    Graph(std::list<Link> links) : links(links) {

    };

    const std::list<Link>& getLinks() const {return links; }

private:
    std::list<Link> links;
};

#endif
