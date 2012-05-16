#ifndef NODE_H
#define NODE_H

#include <string>

#include "enums.h"
#include "position.h"

class Node {
public:
    Node(unsigned int id, std::string name, std::string code, Position position) : id(id), name(name), code(code), position(position) {};

    unsigned int getId() {return id;}
    std::string getName() {return name;}
    std::string getCode() {return code;}
    Position getPosition() {return position;}

private:
    unsigned int id;
    std::string name;
    std::string code;
    Position position;
};

#endif