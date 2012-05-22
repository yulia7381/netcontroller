#include <set>
#include <fstream>
#include <ios>
#include <map>

#include "network_service.h"

#define NETWORK_FILE_NAME "network.ncr"

namespace core {
    Graph<Node*, bool> NetworkService::getGraph() const {
        int node_count;
        int link_count;

        std::ifstream in(NETWORK_FILE_NAME, std::ios::in);

        in >> node_count;
        in >> link_count;

        core::Graph<core::Node*, bool> graph;

        std::map<unsigned long, Node*> node_map;
        for (int i = 0; i < node_count; ++i) {
            Node * node = new Node();
            in >> *node;
            node_map.insert(std::make_pair(node->getId(), node));
            graph.addNode(node);
        }

        for (int i = 0; i < link_count; ++i) {
            unsigned long id;
            unsigned long n1;
            unsigned long n2;
            in >> id >> n1 >> n2;

            graph.addLink(node_map[n1], node_map[n2], true);
        }

        in.close();

        return graph;
    }

    struct NodeComparator {
        bool operator() (const Node* l, const Node* r) const {return l < r;}
    };

    bool NetworkService::saveGraph(const Graph<Node*, bool>& graph) {
        std::list<Node*> nodes = graph.getNodes();
        nodes.unique();

        std::list<NodeLink<Node*, bool> > links = graph.getLinks();

        std::ofstream out(NETWORK_FILE_NAME, std::ios::out);

        out << nodes.size() << "\n";
        out << links.size() << "\n";

        for (std::list<Node*>::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
            out << **it << "\n";
        }

        int id = 1;
        for (std::list<NodeLink<Node*, bool> >::const_iterator it = links.begin(); it != links.end(); ++it, ++id) {
            out << id << " " << it->getNode1()->getId() << " " << it->getNode2()->getId() << "\n";
        }

        out.close();
        return true;
    }
}
