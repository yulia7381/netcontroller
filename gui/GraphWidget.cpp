#include "GraphWidget.h"
#include "GraphicEdge.h"
#include "GraphicNode.h"

#include <QtGui>

#include <qmath.h>

GraphWidget::GraphWidget(QWidget *parent) :
	QGraphicsView(parent), timerId(0) {
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	scene->setSceneRect(-200, -200, 400, 400);
	setScene(scene);
	setCacheMode(CacheBackground);
	setViewportUpdateMode(BoundingRectViewportUpdate);
	setRenderHint(QPainter::Antialiasing);
	setTransformationAnchor(AnchorUnderMouse);
	scale(qreal(0.8), qreal(0.8));
	setMinimumSize(400, 400);
	setWindowTitle(tr("Network View"));

	GraphicNode *node1 = new GraphicNode(this);
	GraphicNode *node2 = new GraphicNode(this);
	GraphicNode *node3 = new GraphicNode(this);
	GraphicNode *node4 = new GraphicNode(this);
	centerNode = new GraphicNode(this);
	GraphicNode *node6 = new GraphicNode(this);
	GraphicNode *node7 = new GraphicNode(this);
	GraphicNode *node8 = new GraphicNode(this);
	GraphicNode *node9 = new GraphicNode(this);
	scene->addItem(node1);
	scene->addItem(node2);
	scene->addItem(node3);
	scene->addItem(node4);
	scene->addItem(centerNode);
	scene->addItem(node6);
	scene->addItem(node7);
	scene->addItem(node8);
	scene->addItem(node9);
	scene->addItem(new GraphicEdge(node1, node2));
	scene->addItem(new GraphicEdge(node2, node3));
	scene->addItem(new GraphicEdge(node2, centerNode));
	scene->addItem(new GraphicEdge(node3, node6));
	scene->addItem(new GraphicEdge(node4, node1));
	scene->addItem(new GraphicEdge(node4, centerNode));
	scene->addItem(new GraphicEdge(centerNode, node6));
	scene->addItem(new GraphicEdge(centerNode, node8));
	scene->addItem(new GraphicEdge(node6, node9));
	scene->addItem(new GraphicEdge(node7, node4));
	scene->addItem(new GraphicEdge(node8, node7));
	scene->addItem(new GraphicEdge(node9, node8));
	scene->addItem(new GraphicEdge(node9, node1));
	scene->addItem(new GraphicEdge(node9, node2));

	node1->setPos(-50, -50);
	node2->setPos(0, -50);
	node3->setPos(50, -50);
	node4->setPos(-50, 0);
	centerNode->setPos(0, 0);
	node6->setPos(50, 0);
	node7->setPos(-50, 50);
	node8->setPos(0, 50);
	node9->setPos(50, 50);
}

void GraphWidget::itemMoved() {

}

void GraphWidget::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
	case Qt::Key_Up:
		centerNode->moveBy(0, -20);
		break;
	case Qt::Key_Down:
		centerNode->moveBy(0, 20);
		break;
	case Qt::Key_Left:
		centerNode->moveBy(-20, 0);
		break;
	case Qt::Key_Right:
		centerNode->moveBy(20, 0);
		break;
	case Qt::Key_Plus:
		zoomIn();
		break;
	case Qt::Key_Minus:
		zoomOut();
		break;
	case Qt::Key_Space:
	case Qt::Key_Enter:
		shuffle();
		break;
	default:
		QGraphicsView::keyPressEvent(event);
		break;
	}
}

void GraphWidget::timerEvent(QTimerEvent *event) {

}


void GraphWidget::wheelEvent(QWheelEvent *event) {
	scaleView(qPow((double) 2, -event->delta() / 240.0));
}


void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect) {
	Q_UNUSED(rect);

	// Shadow
	QRectF sceneRect = this->sceneRect();
	QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5,
			sceneRect.height());
	QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(),
			sceneRect.width(), 5);
	if (rightShadow.intersects(rect) || rightShadow.contains(rect))
		painter->fillRect(rightShadow, Qt::darkGray);
	if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
		painter->fillRect(bottomShadow, Qt::darkGray);

	// Fill
	QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
	gradient.setColorAt(0, Qt::white);
	gradient.setColorAt(1, Qt::lightGray);
	painter->fillRect(rect.intersect(sceneRect), gradient);
	painter->setBrush(Qt::NoBrush);
	painter->drawRect(sceneRect);

}


void GraphWidget::scaleView(qreal scaleFactor) {
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(
			QRectF(0, 0, 1, 1)).width();
	if (factor < 0.07 || factor > 100)
		return;

	scale(scaleFactor, scaleFactor);
}

void GraphWidget::shuffle() {
	foreach (QGraphicsItem *item, scene()->items()) {
		if (qgraphicsitem_cast<GraphicNode *>(item)) {
			item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
		}
	}
}

void GraphWidget::zoomIn() {
	scaleView(qreal(1.2));
}

void GraphWidget::zoomOut() {
	scaleView(1 / qreal(1.2));
}
