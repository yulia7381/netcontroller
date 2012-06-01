#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QObject>

#include "GraphicEdge.h"
#include "GraphicNode.h"
#include "GraphWidget.h"

GraphicNode::GraphicNode(GraphWidget *graphWidget, Node *nodeInfo)
		: nodeInfo(nodeInfo), graph(graphWidget) {
	setFlag(ItemIsMovable);
	setFlag(ItemSendsGeometryChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-1);
	setPos(nodeInfo->getPosition().getX(), nodeInfo->getPosition().getY());

    QObject::connect(this, SIGNAL(nodeClickedSignal(GraphicNode*)), graph, SLOT(nodeClickedSlot(GraphicNode*)));
}

void GraphicNode::addEdge(GraphicEdge *edge) {
	edgeList << edge;
	edge->adjust();
}

QList<GraphicEdge *> GraphicNode::edges() const {
	return edgeList;
}

bool GraphicNode::advance() {
	if (newPos == pos())
		return false;

	setPos(newPos);
	return true;
}


QRectF GraphicNode::boundingRect() const {

	qreal adjust = 2;
	return QRectF(-10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}


QPainterPath GraphicNode::shape() const {
	QPainterPath path;

	path.addEllipse(-10, -10, 20, 20);
	return path;
}


void GraphicNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *) {
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::darkGray);
	painter->drawEllipse(-7, -7, 20, 20);

	QColor color;
	QColor colorDark;
	switch(nodeInfo->getType()){
		default:
		case ROUTER : { color = Qt::blue; colorDark = Qt::darkBlue; } break;
		case DESKTOP : { color = Qt::yellow; colorDark = Qt::darkYellow; } break;
		case SERVER : { color = Qt::green; colorDark = Qt::darkGreen; } break;
	}

	QRadialGradient gradient(-3, -3, 10);
	if (option->state & QStyle::State_Sunken) {
		gradient.setCenter(3, 3);
		gradient.setFocalPoint(3, 3);
		gradient.setColorAt(1, color.light(120));
		gradient.setColorAt(0, colorDark.light(120));
	} else {
		gradient.setColorAt(0, color);
		gradient.setColorAt(1, colorDark);
	}
	painter->setBrush(gradient);

	painter->setPen(QPen(Qt::black, 0));
	painter->drawEllipse(-10, -10, 20, 20);

}


QVariant GraphicNode::itemChange(GraphicsItemChange change, const QVariant &value) {
	switch (change) {
	case ItemPositionHasChanged:
		foreach (GraphicEdge *edge, edgeList) {
			edge->adjust();
		}
		graph->itemMoved();

		nodeInfo->setPosition(core::Position(
				this->x(),
				this->y(),
				nodeInfo->getPosition().getFloor(),
				nodeInfo->getPosition().getBuilding()
		));

		break;
	default:
		break;
	};

	return QGraphicsItem::itemChange(change, value);
}


void GraphicNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	update();
	QGraphicsItem::mousePressEvent(event);
    emit nodeClickedSignal(this);
}

void GraphicNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	update();
	QGraphicsItem::mouseReleaseEvent(event);
}



