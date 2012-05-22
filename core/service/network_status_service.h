#ifndef NETWORK_STATUS_SERVICE_H
#define NETWORK_STATUS_SERVICE_H

#include <list>

#include "../model/node.h"
#include "../model/node_status.h"

namespace core {
    class NetworkStatusService {
    public:
        NodeStatus getNodeStatus(const Node& node);
        bool saveStatus(const Node& node, const NodeStatus& status);

        std::list<NodeStatus> getStatusHistory(const Node& node);

    private:

    };
}

#endif
