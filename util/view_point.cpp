#include "../core/service/network_status_service.h"
#include "../core/service/network_service.h"
#include "../core/model/node.h"
#include "../core/model/node_status.h"


#include <string>
#include <iostream>
#include <time.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Usage:\n     ncr_view_point $node_id" << std::endl;
        return -1;
    }

    NetworkStatusService nss;
    NetworkService ns;

    unsigned long node_id = atoi(argv[1]);
    

    if (ns.getGraph().containsNode(node_id)) {
        std::list<NodeStatus> history = nss.getStatusHistory(Node(node_id, "", "", Position()));
        for (std::list<NodeStatus>::const_iterator it = history.begin(); it != history.end(); ++it) {
            std::cout << *it << std::endl;
        }
    } else {
        std::cerr << "Graph do not have node with id = " << node_id << std::endl;
        return -1;
    }
}

