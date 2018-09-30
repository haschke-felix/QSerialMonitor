#include "serialconnect.h"
#include "ui_serialconnect.h"
#include "qdebug.h"
#include "QStandardItemModel"


SerialConnect::SerialConnect(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::SerialConnect)
{
	ui->setupUi(this);
	setWindowTitle("Select Serial Device");
	print();
	connect(ui->treeWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(onConnect()));
	connect(ui->pushButtonConnect,SIGNAL(clicked()),this,SLOT(onConnect()));
	connect(ui->pushButtonCancel,SIGNAL(clicked(bool)),this,SLOT(hide()));
}

SerialConnect::~SerialConnect()
{
	delete ui;
}


void SerialConnect::onConnect()
{
	QTreeWidgetItem * item = ui->treeWidget->currentItem();
	QString portname = item->text(0);
	port = portname;
	this->hide();
}

void SerialConnect::print()
{
	foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
		QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
		item->setText(0,info.portName());
		item->setText(1,info.description());
		item->setText(2,info.manufacturer());
		ui->treeWidget->addTopLevelItem(item);
	}
	for(int i = 0; i < 3; i++){
		 ui->treeWidget->resizeColumnToContents(i);
	}
}

