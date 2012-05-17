#include <QtGui>
#include <list>
#include "GraphWidget.h"


int main(int argc, char **argv) {
	QApplication app(argc, argv);
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	std::list<Link> x;
	GraphWidget *widget = new GraphWidget(new Graph(x));

	QMainWindow mainWindow;
	mainWindow.setCentralWidget(widget);
	mainWindow.show();
	return app.exec();
}
