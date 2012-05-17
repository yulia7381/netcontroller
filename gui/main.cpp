#include <QtGui>
#include <list>
#include "GraphWidget.h"


int main(int argc, char **argv) {
	QApplication app(argc, argv);
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	std::list<Link> links;
	for(int i = 0; i < 10; i++){
		links.push_back(Link(
				i+1,
				Node(i*i,"","", Position(i*10, i*10+(i%2==0?-5:5), i, i+7)),
				Node(i*i+1,"","", Position(i*8, i*8+(i%2==0?-5:5), i, i+7))
		));
	}
	GraphWidget *widget = new GraphWidget(new Graph(links));

	QMainWindow mainWindow;
	mainWindow.setCentralWidget(widget);
	mainWindow.show();
	return app.exec();
}
