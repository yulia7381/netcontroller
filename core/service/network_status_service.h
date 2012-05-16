#ifndef NETWORK_STATUS_SERVICE_H
#define NETWORK_STATUS_SERVICE_H

#include <list>

#include "../model/node.h"
#include "../model/node_status.h"

class NetworkStatusService {
public:
    NodeStatus getNodeStatus(const Node& node) const;
    bool saveStatus(const Node& node, const NodeStatus status);

    std::list<NodeStatus> getStatusHistory(const Node& node) const;

private:

};

#endif