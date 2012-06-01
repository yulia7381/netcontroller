#include "node_status.h"

namespace core {

    NodeStatus& NodeStatus::operator= (const NodeStatus& st) {
        time = st.time;
        load_average = st.load_average;
        memory_usage = st.memory_usage;
        network_throughput = st.network_throughput;
        latency = st.latency;
        return *this;
    }

    std::ostream& operator<< (std::ostream& out, const NodeStatus& st) {
        out << st.getTime() << " " << st.getLoadAverage() << " " << st.getMemoryUsage() << " " << st.getNetworkThroughput() << " " << st.getLatency();
        return out;
    }

    std::istream& operator>> (std::istream& in, NodeStatus& st) {
        unsigned long time;
        unsigned long load_average;
        unsigned long memory_usage;
        unsigned long network_throughput;
        unsigned long latency;
        in >> time >> load_average >> memory_usage >> network_throughput >> latency;
        st = NodeStatus(time, load_average, memory_usage, network_throughput, latency);
        return in;
    }

}
