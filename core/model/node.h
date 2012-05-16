#ifndef NODE_H
#define NODE_H

#include <string>

#include "enums.h"
#include "position.h"

class Node {
public:
    Node(unsigned long id, std::string name, std::string code, Position position) : id(id), name(name), code(code), position(position) {};

    unsigned long getId() {return id;}
    std::string getName() {return name;}
    std::string getCode() {return code;}
    Position getPosition() {return position;}

private:
    unsigned long id;
    std::string name;
    std::string code;
    Position position;
};

#endif