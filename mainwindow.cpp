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
	showMaximized();
	setWindowIcon(QIcon(":/icons/images/USB Icon.png"));

	ui->label->setAutoFillBackground(true);

	baud_	= QSerialPort::Baud9600;
	ui->comboBox_baud->setCurrentText("9600 baud");

	serial.setBaudRate(baud_);
	serial.setDataBits(QSerialPort::Data8);
	serial.setParity(QSerialPort::NoParity);
	serial.setStopBits(QSerialPort::OneStop);
	serial.setFlowControl(QSerialPort::NoFlowControl);

	onUnconnected();
	serialConnect();


	connect(&serial,SIGNAL(readyRead()),this,SLOT(SerialReceived()));
	connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(onTransmitt()));
	connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onTransmitt()));
	connect(ui->pushButton_connect,SIGNAL(clicked(bool)),this,SLOT(serialConnect()));
	connect(ui->pushButton_disconnect,SIGNAL(clicked(bool)),this,SLOT(onDisconnect()));
	connect(ui->pushButton_clear,SIGNAL(clicked(bool)),this,SLOT(onClear()));
	connect(&serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(onSerialError(QSerialPort::SerialPortError)));
	connect(ui->comboBox_baud,SIGNAL(currentIndexChanged(int)),this,SLOT(onBaudChanged()));
}

MainWindow::~MainWindow()
{
	delete ui;
	disconnect(&serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(onSerialError(QSerialPort::SerialPortError)));
	serial.close();
}

void MainWindow::SerialReceived(){
	QString read = serial.readAll();
	ui->plainTextEdit->insertPlainText(read);
	ui->plainTextEdit->ensureCursorVisible();
}

void MainWindow::onTransmitt()
{
	QString str	= ui->lineEdit->text();
	ui->lineEdit->clear();
	if(!serial.isOpen() || !serial.isWritable())
		return;
	str.append('\n');
	serial.write(str.toUtf8());
	if(ui->checkBox_show_tranmitted->isChecked()){
		Qt::GlobalColor col = Qt::blue;
		QTextCharFormat tf, tf_old;
		tf_old = tf = ui->plainTextEdit->currentCharFormat();
		tf.setForeground(QBrush((Qt::GlobalColor)col));
		ui->plainTextEdit->setCurrentCharFormat(tf);
		ui->plainTextEdit->insertPlainText(str);
		// restore color
		ui->plainTextEdit->setCurrentCharFormat(tf_old);
		ui->plainTextEdit->ensureCursorVisible();
	}
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
	if(error == QSerialPort::NoError)
		return;
	qDebug() << error;
	onDisconnect();
	if(error & QSerialPort::ResourceError){
		if(serial.isOpen())
			serial.close();
		QMessageBox box; //((QMessageBox::Critical, QString("Port not available"),QString("port %1 not available").arg(serial.portName()),QMessageBox::Retry | QMessageBox::Ok, btn);
		box.setText(tr("An Error occured on Port: %1\nprobably the device has been removed\nSoftware Statemend: %2").arg(serial.portName()).arg(serial.errorString()));
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

void MainWindow::onBaudChanged(){
	int baud = ui->comboBox_baud->currentText().remove("baud").trimmed().toInt();
	qDebug() << baud;
	baud_ = QSerialPort::BaudRate(baud);
	if(serial.isOpen() && serial.isWritable()){
		serial.close();
		serial.setBaudRate(baud_);
		onConnected();
		if(!serial.open(QIODevice::ReadWrite)){
			onSerialError(serial.error());
		}
	}
}
