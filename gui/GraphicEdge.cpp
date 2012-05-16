#include <QPainter>
#include <qmath.h>

#include "GraphicEdge.h"
#include "GraphicNode.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

GraphicEdge::GraphicEdge(GraphicNode *sourceNode, GraphicNode *destNode) :
		arrowSize(10) {
	setAcceptedMouseButtons(0);
	source = sourceNode;
	dest = destNode;
	source->addEdge(this);
	dest->addEdge(this);
	adjust();
}

GraphicNode *GraphicEdge::sourceNode() const {
	return source;
}

GraphicNode *GraphicEdge::destNode() const {
	return dest;
}

void GraphicEdge::adjust() {
	if (!source || !dest)
		return;

	QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
	qreal length = line.length();

	prepareGeometryChange();

	if (length > qreal(20.)) {
		QPointF edgeOffset((line.dx() * 10) / length,
				(line.dy() * 10) / length);
		sourcePoint = line.p1() + edgeOffset;
		destPoint = line.p2() - edgeOffset;
	} else {
		sourcePoint = destPoint = line.p1();
	}
}

QRectF GraphicEdge::boundingRect() const {
	if (!source || !dest)
		return QRectF();

	qreal penWidth = 1;
	qreal extra = (penWidth + arrowSize) / 2.0;

	return QRectF(sourcePoint,
			QSizeF(destPoint.x() - sourcePoint.x(),
					destPoint.y() - sourcePoint.y())).normalized().adjusted(
			-extra, -extra, extra, extra);
}

void GraphicEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
		QWidget *) {
	if (!source || !dest)
		return;

	QLineF line(sourcePoint, destPoint);
	if (qFuzzyCompare(line.length(), qreal(0.)))
		return;

	// Draw the line itself
	painter->setPen(
			QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter->drawLine(line);

	// Draw the arrows
	double angle = qAcos(line.dx() / line.length());
	if (line.dy() >= 0)
		angle = TwoPi - angle;

	painter->setBrush(Qt::black);
	painter->drawPolygon(QPolygonF() << line.p1());
	painter->drawPolygon(QPolygonF() << line.p2());
}
