#include "../core/service/network_status_service.h"
#include "../core/service/network_service.h"
#include "../core/model/node.h"
#include "../core/model/node_status.h"


#include <string>
#include <iostream>
#include <time.h>

int main(int argc, char **argv) {
    if (argc <= 5) {
        std::cout << "Usage:\n     ncr_add_point $node_id $load_average $memory_usage $network $latency" << std::endl;
        return -1;
    }

    NetworkStatusService nss;
    NetworkService ns;

    unsigned long node_id = atoi(argv[1]);
    unsigned long _time = std::time(0);
    unsigned long load_average = atoi(argv[2]);
    unsigned long memory_usage = atoi(argv[3]);
    unsigned long network_throughput = atoi(argv[4]);
    unsigned long latency = atoi(argv[5]);

    if (ns.getGraph().containsNode(node_id)) {
        if (nss.saveStatus(Node(node_id, "", "", Position()), NodeStatus(_time, load_average, memory_usage, network_throughput, latency))) {
            std::cout << "Point saved" << std::endl;
        } else {
            std::cerr << "Some error occured." << std::endl;
            return -1;
        }
    } else {
        std::cerr << "Graph do not have node with id = " << node_id << std::endl;
        return -1;
    }
}

