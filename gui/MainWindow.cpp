#include "MainWindow.h"

#include <QtGui>
#include <QVBoxLayout>
#include <QString>

MainWindow::MainWindow(GraphWidget * graphWidget, QWidget *parent) :
	QWidget(parent), graphWidget(graphWidget), selectedNode(0) {
	setMinimumSize(600, 600);
	setWindowTitle(tr("Network View"));

	QVBoxLayout *widgets = new QVBoxLayout();
	QHBoxLayout *buttons = new QHBoxLayout();
	QHBoxLayout *mainLayout = new QHBoxLayout();
	QVBoxLayout *infoLayout = new QVBoxLayout();

	panel = new QWidget();
	infoPanel = new QWidget();
	saveButton = new QPushButton("Save", panel);
	addNodeButton = new QPushButton("Add Node", panel);
	addEdgeButton = new QPushButton("Add Link", panel);
	saveNodeInfoButton = new QPushButton("Save Node Info", infoPanel);

	QHBoxLayout* idInfoLine = createWidgetWithLabel("id", idLineEdit = new QLabel("", infoPanel));
	idInfoLine->addStretch(5);
	QHBoxLayout* nameInfoLine = createWidgetWithLabel("name", nameLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* codeInfoLine = createWidgetWithLabel("code", codeLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* floorInfoLine = createWidgetWithLabel("floor", floorLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* buildingInfoLine = createWidgetWithLabel("building", buildingLineEdit = new QLineEdit("", infoPanel));

	QHBoxLayout* loadAverageInfoLine = createWidgetWithLabel("load average", loadAverageLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* memoryUsageInfoLine = createWidgetWithLabel("memory usage", memoryUsageLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* networkThroughputInfoLine = createWidgetWithLabel("network throughput", networkThroughputLineEdit = new QLineEdit("", infoPanel));
	QHBoxLayout* latencyInfoLine = createWidgetWithLabel("latency", latencyLineEdit = new QLineEdit("", infoPanel));


	QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
	QObject::connect(addNodeButton, SIGNAL(clicked()), this, SLOT(addNodeButtonClicked()));
	QObject::connect(addEdgeButton, SIGNAL(clicked()), this, SLOT(addEdgeButtonClicked()));
	QObject::connect(saveNodeInfoButton, SIGNAL(clicked()), this, SLOT(saveNodeInfoButtonClicked()));
	QObject::connect(graphWidget, SIGNAL(nodeClickedSignal(GraphicNode*)), this, SLOT(selectNode(GraphicNode*)));


	buttons->addWidget(saveButton);
	buttons->addWidget(addNodeButton);
	buttons->addWidget(addEdgeButton);

	panel->setLayout(buttons);

	widgets->addWidget(graphWidget);
	widgets->addWidget(panel);

	infoLayout->addLayout(idInfoLine);
	infoLayout->addLayout(nameInfoLine);
	infoLayout->addLayout(codeInfoLine);
	infoLayout->addLayout(floorInfoLine);
	infoLayout->addLayout(buildingInfoLine);
	infoLayout->addSpacing(25);
	infoLayout->addLayout(loadAverageInfoLine);
	infoLayout->addLayout(memoryUsageInfoLine);
	infoLayout->addLayout(networkThroughputInfoLine);
	infoLayout->addLayout(latencyInfoLine);
	infoLayout->addSpacing(15);
	infoLayout->addWidget(saveNodeInfoButton);

	infoLayout->addStretch(5);


	infoPanel->setLayout(infoLayout);

	mainLayout->addLayout(widgets, 1);
	mainLayout->addWidget(infoPanel);

	this->setLayout(mainLayout);
}

//QHBoxLayout* MainWindow::wrapInLayout(QWidget* left, QWidget* right){
//	QHBoxLayout * layout = new QHBoxLayout();
//	layout->addWidget(left);
//	layout->addWidget(right);
//	return layout;
//}

QHBoxLayout* MainWindow::createWidgetWithLabel(const char * labelName, QWidget* w){
	QHBoxLayout * layout = new QHBoxLayout();
	layout->addWidget(new QLabel(labelName));
	layout->addWidget(w);
	return layout;
}

void MainWindow::timerEvent(QTimerEvent *event) {

}

void MainWindow::init(){

}

void MainWindow::saveButtonClicked(){
	Graph g = graphWidget->getGraph();
	ns.saveGraph(g);
//	const std::list<Node*> nodes = g.getNodes();
//	for (std::list<Node*>::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
//		Node* node = *it;
//		nss.saveStatus(*node, core::NodeStatus(0, 10, 20, 15, 40));
//	}
}

void MainWindow::addNodeButtonClicked(){
	graphWidget->setWaitToAdd(true);
//	qDebug() << "clicked2";
}

void MainWindow::addEdgeButtonClicked(){
	graphWidget->setWaitToAddEdge(true);
//	qDebug() << "clicked3";
}

void MainWindow::saveNodeInfoButtonClicked(){
//	qDebug() << "clicked3";
	if(selectedNode != 0){
		Node* nodeInfo = selectedNode;
		nodeInfo->setName(nameLineEdit->text().toStdString());
		nodeInfo->setCode(codeLineEdit->text().toStdString());
		core::Position oldPos = nodeInfo->getPosition();
		nodeInfo->setPosition(core::Position(
				oldPos.getX(),
				oldPos.getY(),
				floorLineEdit->text().toInt(),
				buildingLineEdit->text().toInt()
		));

			nss.saveStatus(*nodeInfo, core::NodeStatus(
					time(0),
					loadAverageLineEdit->text().toULong(),
					memoryUsageLineEdit->text().toULong(),
					networkThroughputLineEdit->text().toULong(),
					latencyLineEdit->text().toULong()
			));
	}
}

void MainWindow::selectNode(GraphicNode *node){
//	qDebug() << "clicked3888" << (int*)node;
	Node* info = node;
	idLineEdit->setText(QString::number(info->getId()));
	nameLineEdit->setText(QString::fromStdString(info->getName()));
	codeLineEdit->setText(QString::fromStdString(info->getCode()));

	core::Position pos = info->getPosition();

	buildingLineEdit->setText(QString::number(pos.getBuilding()));
	floorLineEdit->setText(QString::number(pos.getFloor()));
	try{
		core::NodeStatus status = nss.getNodeStatus(*info);
		latencyLineEdit->setText(QString::number(status.getLatency()));
		loadAverageLineEdit->setText(QString::number(status.getLoadAverage()));
		memoryUsageLineEdit->setText(QString::number(status.getMemoryUsage()));
		networkThroughputLineEdit->setText(QString::number(status.getNetworkThroughput()));
	} catch(...){
		latencyLineEdit->setText("0");
		loadAverageLineEdit->setText("0");
		memoryUsageLineEdit->setText("0");
		networkThroughputLineEdit->setText("0");
	}


	selectedNode = node;
}



