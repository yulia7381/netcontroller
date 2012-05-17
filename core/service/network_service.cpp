#include "network_service.h"

#include "../model/link.h"
#include "../model/node.h"

#include <set>
#include <fstream>
#include <ios>
#include <map>

#define NETWORK_FILE_NAME "network.ncr"

Graph NetworkService::getGraph() const {
    int node_count;
    int link_count;
    
    std::ifstream in(NETWORK_FILE_NAME, std::ios::in);

    in >> node_count;
    in >> link_count;

    std::map<unsigned long, Node*> node_map;
    for (int i = 0; i < node_count; ++i) {
        Node * node = new Node();
        in >> *node;
        node_map.insert(std::make_pair(node->getId(), node));
        std::cout << node->getId();
        std::cout << node->getName();
        std::cout << node->getCode();

    }

    std::list<Link*> links;
    for (int i = 0; i < link_count; ++i) {
        unsigned long id;
        unsigned long n1;
        unsigned long n2;
        in >> id >> n1 >> n2;

        Link * link = new Link(id, node_map[n1], node_map[n2]);

        links.push_back(link);
    }

    in.close();

    return Graph(links);
}

struct NodeComparator {
    bool operator() (const Node* l, const Node* r) const {return l < r;}
};

bool NetworkService::saveGraph(const Graph& graph) {
    std::set<Node*, NodeComparator> nodes;

    std::list<Link*> links = graph.getLinks();
    std::cout << links.size();

    for (std::list<Link*>::const_iterator it = links.begin(); it != links.end(); ++it) {
        nodes.insert((*it)->getNode1());
        nodes.insert((*it)->getNode2());
    }

    unsigned long id = 1;
    for (std::set<Node*, NodeComparator>::iterator it = nodes.begin(); it != nodes.end(); ++it, ++id) {
        const_cast<Node*>(*it)->setId(id);
    }

    std::ofstream out(NETWORK_FILE_NAME, std::ios::out);

    out << nodes.size() << "\n";
    out << links.size() << "\n";

    for (std::set<Node*, NodeComparator>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        out << **it << "\n";
    }

    id = 1;
    for (std::list<Link*>::const_iterator it = links.begin(); it != links.end(); ++it, ++id) {
        out << id << " " << (*it)->getNode1()->getId() << " " << (*it)->getNode2()->getId() << "\n";
    }

    out.close();
    return true;
}
