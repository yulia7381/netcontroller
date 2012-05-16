#ifndef NODE_H
#define NODE_H

#include <string>

#include "enums.h"

class Node {
public:
    Node(unsigned int id, std::string name, std::string code) : id(id), name(name), code(code) {};

private:
    unsigned int id;
    std::string name;
    std::string code;
};

#endif