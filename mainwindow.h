#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help.h"
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void SerialReceived();


	void onTransmitt();
	void onLED_changed(bool state);

	void onClear();

	void serialConnect();
	void onDisconnect();
	void onConnected();
	void onUnconnected();

private:
	Ui::MainWindow *ui;
	QSerialPort serial;

};

#endif // MAINWINDOW_H
