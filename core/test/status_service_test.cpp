#include "../service/network_status_service.h"
#include "../model/node.h"
#include "../model/node_status.h"
#include "../model/position.h"


#include <string>
#include <iostream>

int main() {

    core::NetworkStatusService nss;
    core::Node n1(1, "", "", core::Position());
    nss.saveStatus(core::Node(1, "", "", core::Position()), core::NodeStatus(1000069, 78, 99, 99, 44));

    std::cout << "Current: " << std::endl;
    std::cout << nss.getNodeStatus(n1) << std::endl;

    std::cout << "Whole history: " << std::endl;
    std::list<core::NodeStatus> history = nss.getStatusHistory(n1);
    std::cout << "Size: " << history.size() << std::endl;
    for (std::list<core::NodeStatus>::const_iterator it = history.begin(); it != history.end(); ++it) {
        std::cout << *it << std::endl;
    }

}
