#ifndef ENUMS_H
#define ENUMS_H

enum NodeType {
    DESKTOP,
    SERVER,
    ROUTER
};

enum NodeStatus {
    OK,
    NETWORK_PROBLEMS,
    OVERLOAD,
    HIGH_LATENCY
};

enum UserRole {
    ADMIN,
    HELPDESK,
    REPAIRER
};

#endif