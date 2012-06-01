#include "node.h"
#include "node_router.h"
#include "node_server.h"
#include "node_desktop.h"



#include <iostream>

namespace core {

    std::ostream& operator<< (std::ostream& os, const Node& n){
        os << n.getId() << "\n";
        os << n.getName() << "\n";
        os << n.getCode() << "\n";
        os << n.getPosition() << "\n";
        os << n.getType() << "\n";

        return os;
    }

    std::istream& operator>> (std::istream& is, Node& n) {
        unsigned long id;
        std::string name;
        std::string code;
        Position pos;

        int type;

        is >> id >> name >> code >> pos >> type;
    	switch(NodeType(type)){
    		default:
    		case ROUTER : { n = NodeRouter(id, name, code, pos); } break;
    		case DESKTOP : { n = NodeDesktop(id, name, code, pos); } break;
    		case SERVER : { n = NodeServer(id, name, code, pos); } break;
    	}

        return is;
    }

    Node& Node::operator= (const Node& node) {
        id = node.id;
        name = node.name;
        code = node.code;
        position = node.position;
        return *this;
    }

}
