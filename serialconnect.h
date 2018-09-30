
#include <QDialog>

#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class SerialConnect;
}

class SerialConnect : public QDialog
{
	Q_OBJECT

public:
	explicit SerialConnect(QWidget *parent = 0);
	~SerialConnect();
	QString getPortName(){return port;}
private slots:
	void onConnect();
private:
	QString port;
	void print();
	Ui::SerialConnect *ui;
};
