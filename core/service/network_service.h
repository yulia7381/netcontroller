#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include "../model/graph.h"

class NetworkService {
public:
    Graph& getGraph() const;
    bool saveGraph(const Graph& graph);

private:

};

#endif