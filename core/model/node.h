#ifndef NODE_H
#define NODE_H

#include <string>

#include "node_type.h"

class Node {
public:
    Node(uint id, std::string name, std::string code) : id(id), name(name), code(code) {};

private:
    uint id;
    std::string name;
    std::string code;
};

#endif