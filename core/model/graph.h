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
            return *this;
        };

        Node getNode1() const {return node1;};
        Node getNode2() const {return node2;};

        Link getLink() const {return link;};
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

        const std::list<Node>& getNodes() const {return nodes;};
        const std::list<NodeLink<Node, Link> >& getLinks() const {return links;};

        const std::list<NodeLink<Node, Link> >& getLinksFromNode(Node node);
        const Link& getLink(Node node1, Node node2);

        void addNode(Node node);
        void addLink(Node node1, Node node2, Link link);

    private:
        std::list<Node> nodes;
        std::list<NodeLink<Node, Link> > links;
    };
}

#endif
