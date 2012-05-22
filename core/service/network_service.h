#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include "../model/graph.h"
#include "../model/node.h"

namespace core {
    class NetworkService {
    public:
        Graph<Node*, bool> getGraph() const;
        bool saveGraph(const Graph<Node*, bool>& graph);

    private:

    };
}


#endif