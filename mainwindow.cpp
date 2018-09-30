#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialconnect.h"
#include "QMessageBox"



//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Modellbahnsteuerung IDE ALPHA");
	this->showMaximized();

	ui->checkBox_button->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->checkBox_button->setFocusPolicy(Qt::NoFocus);
	ui->label->setAutoFillBackground(true);

	onUnconnected();
	serialConnect();

	connect(&serial,SIGNAL(readyRead()),this,SLOT(SerialReceived()));
	connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(onTransmitt()));
	connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onTransmitt()));
	connect(ui->checkBox_led,SIGNAL(toggled(bool)),this,SLOT(onLED_changed(bool)));
	connect(ui->pushButton_connect,SIGNAL(clicked(bool)),this,SLOT(serialConnect()));
	connect(ui->pushButton_disconnect,SIGNAL(clicked(bool)),this,SLOT(onDisconnect()));
	connect(ui->pushButton_clear,SIGNAL(clicked(bool)),this,SLOT(onClear()));

	onLED_changed(false);
	ui->checkBox_led->setChecked(false);
}

MainWindow::~MainWindow()
{
	delete ui;
	serial.close();
}

void MainWindow::SerialReceived(){
	static QString str;
	str.append(serial.readAll());
	auto values = str.split('\n');
	str = values.last();
	values.removeLast();
	for(QString s : values) {
		if(s.contains("init",Qt::CaseInsensitive)){
			ui->checkBox_led->setChecked(false);
		}
		else if(s == "ON"){
			ui->checkBox_button->setCheckState(Qt::Checked);
		}
		else if(s == "OFF"){
			ui->checkBox_button->setCheckState(Qt::Unchecked);
		}
		ui->plainTextEdit->appendPlainText(s);
	}
}

void MainWindow::onTransmitt()
{
	QString str	= ui->lineEdit->text();
	ui->lineEdit->clear();
	str.append('\n');
	serial.write(str.toUtf8());
}

void MainWindow::onLED_changed(bool state)
{
	serial.write((state?"ON\n":"OFF\n"));
}

void MainWindow::onClear()
{
	ui->plainTextEdit->clear();
}

void MainWindow::serialConnect()
{
	SerialConnect serc;
	serc.exec();
	QString str = serc.getPortName();
	if(str.isEmpty()){
		if(!serial.isOpen()){
			onConnected();
		}
		return;
	}
	if(serial.isOpen()){
		if(str ==  serial.portName()){
			return;
		}
		serial.close();
	}
	serial.setPortName(str);
	serial.setBaudRate(QSerialPort::Baud9600);
	serial.setDataBits(QSerialPort::Data8);
	serial.setParity(QSerialPort::NoParity);
	serial.setStopBits(QSerialPort::OneStop);
	serial.setFlowControl(QSerialPort::NoFlowControl);
	if (!serial.open(QIODevice::ReadWrite)){
		qDebug() << "no access to port";
		QMessageBox box; //((QMessageBox::Critical, QString("Port not available"),QString("port %1 not available").arg(serial.portName()),QMessageBox::Retry | QMessageBox::Ok, btn);
		box.setText(tr("port %1 not available").arg(serial.portName()));
		box.setWindowTitle(tr("Port not available"));
		box.setIcon(QMessageBox::Critical);
		box.addButton(tr("Cancel"),QMessageBox::DestructiveRole);
		QAbstractButton * retry	= box.addButton(tr("Retry"),QMessageBox::ActionRole);
		box.exec();
		if(box.clickedButton() == retry){
			serialConnect();
			return;
		}
		else{
			onUnconnected();
			return;
		}
	}
	onConnected();
}

void MainWindow::onDisconnect()
{
	ui->label->setText(tr("No Connection"));
	ui->label->setAutoFillBackground(true);
	QPalette palette = ui->label->palette();
	palette.setColor(ui->label->backgroundRole(), Qt::red);
	ui->label->setPalette(palette);
	if(serial.isOpen()){
		serial.close();
	}
}

void MainWindow::onConnected()
{
	ui->label->setText(serial.portName());
	QPalette palette = ui->label->palette();
	palette.setColor(ui->label->backgroundRole(), QColor(Qt::green).light(120));
	ui->label->setPalette(palette);
}

void MainWindow::onUnconnected()
{
	ui->label->setText(tr("No Connection"));
	ui->label->setAutoFillBackground(true);
	QPalette palette = ui->label->palette();
	palette.setColor(ui->label->backgroundRole(),  QColor(Qt::red).light(120));
	ui->label->setPalette(palette);
}
