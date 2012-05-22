#ifndef GRAPH_H
#define GRAPH_H

#include <list>

namespace core {
    template<class Node, class Link>
    class NodeLink {
    public:
        NodeLink() {};
        NodeLink(const NodeLink& lnk) : node1(lnk.node1), node2(lnk.node2), link(lnk.link) {};
        NodeLink(Node n1, Node n2, Link l) : node1(n1), node2(n2), link(l) {};
        NodeLink& operator = (const NodeLink& lnk) {
            node1 = lnk.node1;
            node2 = lnk.node2;
            link = lnk.link;
            return this;
        };

        Node getNode1();
        Node getNode2();

        Link getLink();
    private:
        Node node1;
        Node node2;
        Link link;
    };

    template<class Node, class Link>
    class Graph {
    public:
        Graph() {};
        Graph(const Graph& gr);

        Graph& operator= (const Graph& gr);
        
        std::list<Node> getNodes() const {return nodes;};
        std::list<NodeLink<Node, Link> > getLinks() const {return links;};

        std::list<NodeLink<Node, Link> > getLinksFromNode(Node node);
        Link getLink(Node node1, Node node2);

        void addNode(Node node);
        void addLink(Node node1, Node node2, Link link);
    private:
        std::list<Node> nodes;
        std::list<NodeLink<Node, Link> > links;
    };
}

#endif
