#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>

#include "GraphWidget.h"
#include "../core/service/network_service.h"
#include "../core/service/network_status_service.h"



class MainWindow: public QWidget {

Q_OBJECT;

public:
	MainWindow(GraphWidget * graphWidget, QWidget *parent = 0);

public slots:
	void saveButtonClicked();
	void addNodeButtonClicked();
	void addEdgeButtonClicked();
	void saveNodeInfoButtonClicked();


	void selectNode(GraphicNode *node);


protected:
	void timerEvent(QTimerEvent *event);

private:
	void init();
	QHBoxLayout* createWidgetWithLabel(const char * labelName, QWidget* w);

private:
	GraphWidget *graphWidget;
	QWidget *panel;
	QWidget *infoPanel;


	QPushButton *saveButton;
	QPushButton *addNodeButton;
	QPushButton *addEdgeButton;
	QPushButton *saveNodeInfoButton;


	QLabel * idLineEdit;
	QLineEdit * nameLineEdit;
	QLineEdit * codeLineEdit;
	QLineEdit * floorLineEdit;
	QLineEdit * buildingLineEdit;

	QLineEdit * loadAverageLineEdit;
	QLineEdit * memoryUsageLineEdit;
	QLineEdit * networkThroughputLineEdit;
	QLineEdit * latencyLineEdit;


    core::NetworkService ns;
    core::NetworkStatusService nss;

    GraphicNode *selectedNode;

};

#endif
