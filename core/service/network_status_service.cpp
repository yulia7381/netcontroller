#include <fstream>

#include "network_status_service.h"

#define STATUS_FILE_NAME "status.ncr"

namespace core {

    NodeStatus NetworkStatusService::getNodeStatus(const Node& node) {
        return getStatusHistory(node).back();
    }


    bool NetworkStatusService::saveStatus(const Node& node, const NodeStatus& status) {
        std::ofstream out(STATUS_FILE_NAME, std::ios::app);

        out << node.getId() << " " << status << "\n";
        out.close();
        return true;
    }

    std::list<NodeStatus> NetworkStatusService::getStatusHistory(const Node& node) {
        std::ifstream in(STATUS_FILE_NAME, std::ios::in);

        std::list<NodeStatus> result;

        while (!in.eof()) {
            unsigned long node_id;
            NodeStatus status;
            in >> node_id >> status;
            if (node_id == node.getId() && !in.eof()) {
                result.push_back(status);
            }
        }


        in.close();
        return result;
    }
}
