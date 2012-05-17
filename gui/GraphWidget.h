#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QtGui/QGraphicsView>
#include "../core/model/graph.h"

class GraphicNode;
class GraphicEdge;

class GraphWidget: public QGraphicsView {
public:
	GraphWidget(Graph *graphInfo, QWidget *parent = 0);

	void itemMoved();

public slots:
	void shuffle();
	void zoomIn();
	void zoomOut();

protected:
	void keyPressEvent(QKeyEvent *event);
	void timerEvent(QTimerEvent *event);
	void wheelEvent(QWheelEvent *event);
	void drawBackground(QPainter *painter, const QRectF &rect);

	void scaleView(qreal scaleFactor);

private:
	int timerId;
	GraphicNode *centerNode;
	Graph* graphInfo;
	QList<GraphicNode*> nodes;
	QList<GraphicEdge*> edges;


private:
	QGraphicsScene* initScene(Graph *graphInfo);
};

#endif
