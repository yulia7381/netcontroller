#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class GraphicNode;

class GraphicEdge: public QGraphicsItem {
public:
	GraphicEdge(GraphicNode *sourceNode, GraphicNode *destNode);

	GraphicNode *sourceNode() const;
	GraphicNode *destNode() const;

	void adjust();

	enum {
		Type = UserType + 2
	};
	int type() const {
		return Type;
	}

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

private:
	GraphicNode *source, *dest;

	QPointF sourcePoint;
	QPointF destPoint;
	qreal arrowSize;
};
//! [0]

#endif
