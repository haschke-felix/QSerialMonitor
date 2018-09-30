#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::Help)
{
	ui->setupUi(this);
	setWindowTitle("Sign In");
}

Help::~Help()
{
	delete ui;
}

void Help::on_cancel_clicked()
{
	 hide();
}

