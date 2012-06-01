#ifndef NODE_ROUTER_H
#define NODE_ROUTER_H

#include "enums.h"
#include "node.h"

namespace core {
	class NodeRouter : public virtual Node {
	public:
		NodeRouter() {};
		NodeRouter(unsigned long id, std::string name, std::string code, const Position &position)
			: Node(id, name, code, position) {};
		NodeRouter(const NodeRouter& node)
			: Node(node.id, node.name, node.code, node.position) {};

		virtual NodeType getType() const { return ROUTER; }
//        virtual std::string getExtInfo() { return ""; }

	};
}

#endif
