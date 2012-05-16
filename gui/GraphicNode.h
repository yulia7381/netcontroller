#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>

class GraphicEdge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class GraphicNode: public QGraphicsItem {
public:
	GraphicNode(GraphWidget *graphWidget);

	void addEdge(GraphicEdge *edge);
	QList<GraphicEdge *> edges() const;

	enum {
		Type = UserType + 1
	};
	int type() const {
		return Type;
	}

	bool advance();

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	QList<GraphicEdge *> edgeList;
	QPointF newPos;
	GraphWidget *graph;
};

#endif
