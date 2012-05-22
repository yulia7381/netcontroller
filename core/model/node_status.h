#ifndef NODE_STATUS_H
#define NODE_STATUS_H

#include <iostream>

namespace core {
        
    class NodeStatus {
    public:
        NodeStatus() {}
        NodeStatus(unsigned long time, unsigned long load_average, unsigned long memory_usage, unsigned long network_throughput, unsigned long latency)
            : time(time), load_average(load_average), memory_usage(memory_usage), network_throughput(network_throughput), latency(latency) {}

        unsigned long getTime() const {return time;}
        unsigned long getLoadAverage() const {return load_average;}
        unsigned long getMemoryUsage() const {return memory_usage;}
        unsigned long getNetworkThroughput() const {return network_throughput;}
        unsigned long getLatency() const {return latency;}

        NodeStatus& operator= (const NodeStatus& st);
    private:
        unsigned long time;

        unsigned long load_average;
        unsigned long memory_usage;
        unsigned long network_throughput;
        unsigned long latency;
    };

    std::ostream& operator<< (std::ostream& out, const NodeStatus& st);
    std::istream& operator>> (std::istream& in, NodeStatus& st);

}

#endif
