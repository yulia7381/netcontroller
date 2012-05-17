#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#include "link.h"

class Graph {
public:
    Graph(const std::list<Link*>& links) : links(links) {};
    Graph(const Graph& gr) : links(gr.links) {};

    const std::list<Link*>& getLinks() const {return links;};

    Graph& operator= (const Graph& gr);
private:
    std::list<Link*> links;
};

#endif
