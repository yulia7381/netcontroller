#include "MainWindow.h"

#include <QtGui>
#include <QVBoxLayout>

MainWindow::MainWindow(GraphWidget * graphWidget, QWidget *parent) :
	QWidget(parent), graphWidget(graphWidget) {
	setMinimumSize(600, 600);
	setWindowTitle(tr("Network View"));

	QVBoxLayout *widgets = new QVBoxLayout();
	QHBoxLayout *buttons = new QHBoxLayout();
	panel = new QWidget();
	saveButton = new QPushButton("Save", panel);
	addNodeButton = new QPushButton("Add Node", panel);
	addEdgeButton = new QPushButton("Add Link", panel);


	QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
	QObject::connect(addNodeButton, SIGNAL(clicked()), this, SLOT(addNodeButtonClicked()));
	QObject::connect(addEdgeButton, SIGNAL(clicked()), this, SLOT(addEdgeButtonClicked()));


	buttons->addWidget(saveButton);
	buttons->addWidget(addNodeButton);
	buttons->addWidget(addEdgeButton);


	panel->setLayout(buttons);

	widgets->addWidget(graphWidget);
	widgets->addWidget(panel);
	this->setLayout(widgets);
}

void MainWindow::timerEvent(QTimerEvent *event) {

}

void MainWindow::init(){

}

void MainWindow::saveButtonClicked(){
	ns.saveGraph(graphWidget->getGraph());
}

void MainWindow::addNodeButtonClicked(){
	graphWidget->setWaitToAdd(true);
//	qDebug() << "clicked2";
}

void MainWindow::addEdgeButtonClicked(){
	graphWidget->setWaitToAddEdge(true);
//	qDebug() << "clicked3";
}

