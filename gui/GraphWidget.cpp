#include "GraphWidget.h"
#include "GraphicEdge.h"
#include "GraphicNode.h"

#include <QtGui>

#include <qmath.h>

GraphWidget::GraphWidget(Graph *graphInfo, QWidget *parent) :
		QGraphicsView(parent), timerId(0), graphInfo(graphInfo),
		firstSelected(0), secondSelected(0), waitToAdd(false), waitToAddEdge(false) {
	QGraphicsScene *scene = initScene(graphInfo);
	setScene(scene);
	setCacheMode(CacheBackground);
	setViewportUpdateMode(BoundingRectViewportUpdate);
	setRenderHint(QPainter::Antialiasing);
	setTransformationAnchor(AnchorUnderMouse);
//	scale(qreal(0.8), qreal(0.8));
	setMinimumSize(600, 600);
	setWindowTitle(tr("Network View"));

}

QGraphicsScene* GraphWidget::initScene(Graph *graphInfo) {
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	scene->setSceneRect(-200, -200, 400, 400);
	const std::list<Link*> &links = graphInfo->getLinks();
	for (std::list<Link*>::const_iterator it = links.begin(); it != links.end();
			++it) {
		Link* link = *it;
		GraphicNode *graphNode1 = getGNode(link->getNode1());
		GraphicNode *graphNode2 = getGNode(link->getNode2());
		GraphicEdge *edge = new GraphicEdge(graphNode1, graphNode2);
		edges.insert(edge);
	}

	addNodes(scene, nodes);
	addEdges(scene, edges);


	return scene;
}

void GraphWidget::addNodes(QGraphicsScene* scene, const QSet<GraphicNode*> &set) {
	foreach(GraphicNode* item, set) {
		scene->addItem(item);
	}
}

void GraphWidget::addEdges(QGraphicsScene* scene, const QSet<GraphicEdge*> &set) {
	foreach(GraphicEdge* item, set) {
		scene->addItem(item);
	}
}

GraphicNode * GraphWidget::getGNode(Node * nodeInfo) {
	if (!nodeInfoToGNode.contains(nodeInfo)) {
		GraphicNode *node = new GraphicNode(this, nodeInfo);
		nodeInfoToGNode.insert(nodeInfo, node);
		nodes.insert(node);
	}
	return nodeInfoToGNode.value(nodeInfo);
}

void GraphWidget::itemMoved() {

}

void GraphWidget::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
	case Qt::Key_Up:
		break;
	case Qt::Key_Down:
		break;
	case Qt::Key_Left:
		break;
	case Qt::Key_Right:
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

void GraphWidget::mousePressEvent(QMouseEvent *event) {
	if(waitToAdd){
		QPoint p = event->pos();
		GraphicNode* newNode = getGNode(new Node(1, "new", "new-code", Position(p.x() - this->width()/2, p.y() - this->height()/2, 1, 1)));
		this->scene()->addItem(newNode);
		waitToAdd = false;
	}
	QGraphicsView::mousePressEvent(event);
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

void GraphWidget::nodeClickedSlot(GraphicNode* clickedNode){
	if(waitToAddEdge){
		if(firstSelected == 0) {
			firstSelected = clickedNode;
		} else {
			secondSelected = clickedNode;
			processSelectedNodes();
			firstSelected = secondSelected = 0;
			waitToAddEdge = false;
		}
	} else {
		firstSelected = secondSelected = 0;
	}
}

void GraphWidget::processSelectedNodes(){
	GraphicEdge* newEdge = new GraphicEdge(firstSelected, secondSelected);
	edges.insert(newEdge);
	this->scene()->addItem(newEdge);
}

Graph GraphWidget::getGraph(){
	std::list<Link*> links;
	foreach(GraphicEdge * edge, edges){
		links.push_back(new Link(
				1,
				edge->sourceNode()->getNodeInfo(),
				edge->destNode()->getNodeInfo()
		));
	}
	return Graph(links);
}


