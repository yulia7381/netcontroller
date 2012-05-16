#ifndef NODE_STATUS_H
#define NODE_STATUS_H

class NodeStatus {
public:
    NodeStatus(unsigned long time, unsigned long load_average, unsigned long memory_usage, unsigned long network_throughput, unsigned long latency)
        : time(time), load_average(load_average), memory_usage(memory_usage), network_throughput(network_throughput), latency(latency) {}

    unsigned long getTime() {return time;}
    unsigned long getLoadAverage() {return load_average;}
    unsigned long getMemoryUsage() {return memory_usage;}
    unsigned long getLatency() {return latency;}
private:
    unsigned long time;

    unsigned long load_average;
    unsigned long memory_usage;
    unsigned long network_throughput;
    unsigned long latency;
};

#endif
