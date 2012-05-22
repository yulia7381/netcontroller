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
        Graph(const Graph& gr) : nodes(gr.nodes), links(gr.links) {};

        Graph& operator= (const Graph& gr) { 
            nodes = gr.nodes;
            links = gr.links;
            return *this;
        };

        const std::list<Node>& getNodes() const {return nodes;};
        const std::list<NodeLink<Node, Link> >& getLinks() const {return links;};

        const std::list<NodeLink<Node, Link> >& getLinksFromNode(Node node) {
            std::list<NodeLink<Node, Link> > result;
            typedef NodeLink<Node, Link> node_link;
            typedef typename std::list<node_link> node_link_list;
            typedef typename node_link_list::const_iterator iter;

            for (iter it = links.begin(); it != links.end(); ++it) {
                if (node == it->getNode1()) {
                    result.push_back(*it);
                }
            }
            return result;
        };
        const Link& getLink(Node node1, Node node2) {
            typedef NodeLink<Node, Link> node_link;
            typedef typename std::list<node_link> node_link_list;
            typedef typename node_link_list::const_iterator iter;

            for (iter it = links.begin(); it != links.end(); ++it) {
                if (node1 == it->getNode1() && node2 == it->getNode2()) {
                    return it->getLink();
                }
            }
        };

        void addNode(Node node) {nodes.push_back(node);};
        void addLink(Node node1, Node node2, Link link) {links.push_back(NodeLink<Node, Link>(node1, node2, link));};

    private:
        std::list<Node> nodes;
        std::list<NodeLink<Node, Link> > links;
    };
}

#endif
