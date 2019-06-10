#include "cutealarm.h"
#include "ui_cutealarm.h"

CuteAlarm::CuteAlarm(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CuteAlarm)
{
	ui->setupUi(this);
}

CuteAlarm::~CuteAlarm()
{
	delete ui;
}
