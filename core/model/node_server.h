#ifndef NODE_SERVER_H
#define NODE_SERVER_H

#include "enums.h"
#include "node_router.h"
#include "node_desktop.h"


namespace core {
	class NodeServer : public NodeRouter, public NodeDesktop {
	public:
		NodeServer() {};
		NodeServer(unsigned long id, std::string name, std::string code, const Position &position)
			: Node(id, name, code, position),
			  NodeRouter(id, name, code, position),
			  NodeDesktop(id, name, code, position) {};
		NodeServer(const NodeServer& node)
			: Node(node.id, node.name, node.code, node.position),
			  NodeRouter(node.id, node.name, node.code, node.position),
			  NodeDesktop(node.id, node.name, node.code, node.position){};



		virtual NodeType getType() const { return SERVER; }
//        virtual std::string getExtInfo() { return NodeRouter::getExtInfo() + " " + NodeDesktop::getExtInfo(); }

	};
}

#endif
