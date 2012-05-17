#include <QtGui>
#include <list>
#include "GraphWidget.h"


int main(int argc, char **argv) {
	QApplication app(argc, argv);
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	std::list<Link*> links;
	Node * node1 = new Node(1,"1","2", Position(10, 15, 1, 7));
	for(int i = 0; i < 10; i++){
		Node * node2 = new Node(2,"1","2", Position(i*10, (i%2==0 -7 ? : 7) + i*15, 1, 7));
		links.push_back(new Link(1, node1, node2));
		node1 = node2;
	}
	GraphWidget *widget = new GraphWidget(new Graph(links));

	QMainWindow mainWindow;
	mainWindow.setCentralWidget(widget);
	mainWindow.show();
	return app.exec();
}
