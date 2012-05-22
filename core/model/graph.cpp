#include "graph.h"

namespace core {

    template<class Node, class Link>
    Graph<Node, Link>::Graph(const Graph<Node, Link>& gr) : nodes(gr.nodes), links(gr.links) {

    }

    template<class Node, class Link>
    Graph<Node, Link>& Graph<Node, Link>::operator= (const Graph<Node, Link>& gr) {
        nodes = gr.nodes;
        links = gr.links;
        return this;
    }

    template<class Node, class Link>
    std::list<NodeLink<Node, Link> > Graph<Node, Link>::getLinksFromNode(Node node) {
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
    }

    template<class Node, class Link>
    Link Graph<Node, Link>::getLink(Node node1, Node node2) {
        typedef NodeLink<Node, Link> node_link;
        typedef typename std::list<node_link> node_link_list;
        typedef typename node_link_list::const_iterator iter;

        for (iter it = links.begin(); it != links.end(); ++it) {
            if (node1 == it->getNode1() && node2 == it->getNode2()) {
                return it->getLink();
            }
        }
    }

    template<class Node, class Link>
    void Graph<Node, Link>::addNode(Node node) {
        nodes.push_back(node);
    }

    template<class Node, class Link>
    void Graph<Node, Link>::addLink(Node node1, Node node2, Link link) {
        links.push_back(NodeLink<Node, Link>(node1, node2, link));
    }
}
