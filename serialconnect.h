
#include <QDialog>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QShortcut>

namespace Ui {
class SerialConnect;
}

class SerialConnect : public QDialog
{
	Q_OBJECT

public:
	explicit SerialConnect(QWidget *parent = 0);
	~SerialConnect();
	QString getPortName(){if(QSerialPortInfo::availablePorts().length() == 0) return port = ""; return port;}
private slots:
	void onConnect();
	void print();

private:
	QString port;
	Ui::SerialConnect *ui;
};
