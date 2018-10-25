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
	setWindowTitle("QSerialMonitor");
	this->showMaximized();

	ui->checkBox_button->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->checkBox_button->setFocusPolicy(Qt::NoFocus);
	ui->label->setAutoFillBackground(true);

	serial.setBaudRate(QSerialPort::Baud9600);
	serial.setDataBits(QSerialPort::Data8);
	serial.setParity(QSerialPort::NoParity);
	serial.setStopBits(QSerialPort::OneStop);
	serial.setFlowControl(QSerialPort::NoFlowControl);

	onUnconnected();
	serialConnect();


	connect(&serial,SIGNAL(readyRead()),this,SLOT(SerialReceived()));
	connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(onTransmitt()));
	connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onTransmitt()));
	connect(ui->checkBox_led,SIGNAL(toggled(bool)),this,SLOT(onLED_changed(bool)));
	connect(ui->pushButton_connect,SIGNAL(clicked(bool)),this,SLOT(serialConnect()));
	connect(ui->pushButton_disconnect,SIGNAL(clicked(bool)),this,SLOT(onDisconnect()));
	connect(ui->pushButton_clear,SIGNAL(clicked(bool)),this,SLOT(onClear()));
	connect(&serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(onSerialError(QSerialPort::SerialPortError)));

	onLED_changed(false);
	ui->checkBox_led->setChecked(false);
}

MainWindow::~MainWindow()
{
	delete ui;
	disconnect(&serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(onSerialError(QSerialPort::SerialPortError)));
	serial.close();
}

void MainWindow::SerialReceived(){
	static QString str; // only for evaluation
	QString read = serial.readAll();
	ui->plainTextEdit->insertPlainText(read);

	str.append(read);
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
	}
}

void MainWindow::onTransmitt()
{
	QString str	= ui->lineEdit->text();
	ui->lineEdit->clear();
	if(!serial.isOpen() || !serial.isWritable())
		return;
	str.append('\n');
	serial.write(str.toUtf8());
}

void MainWindow::onLED_changed(bool state)
{
	if(!serial.isOpen() || !serial.isWritable())
		return;
	serial.write((state?"ON\n":"OFF\n"));
}

void MainWindow::onClear()
{
	ui->plainTextEdit->clear();
}

void MainWindow::serialConnect()
{
	static bool useable = true;
	if(!useable)
		return;
	useable = false;
	SerialConnect serc;
	serc.exec();
	QString str = serc.getPortName();
	if(str.isEmpty()){
		useable = true;
		if(serial.isOpen() && serial.isWritable()){
			return;
		}
		if(serial.isOpen())
			serial.close();
		onUnconnected();
		return;
	}
	if(serial.isOpen() && serial.isWritable()){
		if(str ==  serial.portName()){
			useable = true;
			return;
		}
		serial.close();
	}
	serial.setPortName(str);
	if (!serial.open(QIODevice::ReadWrite)){
		qDebug() << "no access to port";
		QMessageBox box;
		box.setText(tr("port %1 not available").arg(serial.portName()));
		box.setWindowTitle(tr("Port not available"));
		box.setIcon(QMessageBox::Critical);
		box.addButton(tr("Cancel"),QMessageBox::NoRole);
		QAbstractButton * retry	= box.addButton(tr("Retry"),QMessageBox::ActionRole);
		box.exec();
		if(box.clickedButton() == retry){
			useable = true;
			serialConnect();
			return;
		}
		else{
			onUnconnected();
			useable = true;
			return;
		}
	}
	useable = true;
	onConnected();
}

void MainWindow::onDisconnect()
{
	onUnconnected();
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

void MainWindow::onSerialError(QSerialPort::SerialPortError error)
{
	if(error & QSerialPort::NoError)
		return;
	qDebug() << error;
	onDisconnect();
	if(error & QSerialPort::ResourceError){
		if(serial.isOpen())
			serial.close();
		QMessageBox box; //((QMessageBox::Critical, QString("Port not available"),QString("port %1 not available").arg(serial.portName()),QMessageBox::Retry | QMessageBox::Ok, btn);
		box.setText(tr("An Error occured.\nport %1 not availale, device has been removed").arg(serial.portName()));
		box.setWindowTitle(tr("Port not available"));
		box.setIcon(QMessageBox::Critical);
		box.addButton(tr("Cancel"),QMessageBox::DestructiveRole);
		QAbstractButton * reconnect	= box.addButton(tr("Reconnect"),QMessageBox::ActionRole);
		box.exec();
		if(box.clickedButton() == reconnect){
			serialConnect();
		}
	}
	return;
}
