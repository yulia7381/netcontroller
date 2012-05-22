#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>

#include "GraphWidget.h"
#include "../core/service/network_service.h"


class MainWindow: public QWidget {

Q_OBJECT;

public:
	MainWindow(GraphWidget * graphWidget, QWidget *parent = 0);

public slots:
	void saveButtonClicked();
	void addNodeButtonClicked();
	void addEdgeButtonClicked();


protected:
	void timerEvent(QTimerEvent *event);

private:
	void init();

private:
	GraphWidget *graphWidget;
	QWidget *panel;

	QPushButton *saveButton;
	QPushButton *addNodeButton;
	QPushButton *addEdgeButton;

    core::NetworkService ns;


};

#endif
