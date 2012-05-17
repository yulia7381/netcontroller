#include "../service/network_status_service.h"
#include "../model/node.h"
#include "../model/node_status.h"
#include "../model/position.h"


#include <string>
#include <iostream>

int main() {
    NetworkStatusService nss;
    Node n1(1, "", "", Position());
    nss.saveStatus(Node(1, "", "", Position()), NodeStatus(1000069, 78, 99, 99, 44));

    std::cout << "Current: " << std::endl;
    std::cout << nss.getNodeStatus(n1) << std::endl;

    std::cout << "Whole history: " << std::endl;
    std::list<NodeStatus> history = nss.getStatusHistory(n1);
    std::cout << "Size: " << history.size() << std::endl;
    for (std::list<NodeStatus>::const_iterator it = history.begin(); it != history.end(); ++it) {
        std::cout << *it << std::endl;
    }

}
