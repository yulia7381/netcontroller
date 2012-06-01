#ifndef NODE_DESKTOP_H
#define NODE_DESKTOP_H

#include "enums.h"
#include "node.h"

namespace core {
	class NodeDesktop : public virtual Node {
	public:
		NodeDesktop() {};
		NodeDesktop(unsigned long id, std::string name, std::string code, const Position &position)
			: Node(id, name, code, position) {};
		NodeDesktop(const NodeDesktop& node)
			: Node(node.id, node.name, node.code, node.position) {};

		virtual NodeType getType() const { return DESKTOP; }
//        virtual std::string getExtInfo() { return std::string(); }

	};
}

#endif
