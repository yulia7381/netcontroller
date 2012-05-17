#include "graph.h"

Graph& Graph::operator= (const Graph& gr) {
    links = gr.links;
}

bool Graph::containsNode(unsigned long id) const {
    for (std::list<Link*>::const_iterator it = links.begin(); it != links.end(); ++it) {
        if ((*it)->getNode1()->getId() == id || (*it)->getNode2()->getId() == id) {
            return true;
        }
    }
    return false;
}

bool Graph::containsLink(unsigned long id) const {
    for (std::list<Link*>::const_iterator it = links.begin(); it != links.end(); ++it) {
        if ((*it)->getId() == id) {
            return true;
        }
    }
    return false;
}