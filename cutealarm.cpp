#include <QFileDialog>
#include <QMessageBox>
#include "cutealarm.h"
#include "ui_cutealarm.h"

CuteAlarm::CuteAlarm(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CuteAlarm)
{
	ui->setupUi(this);
	switcher(1);
}

CuteAlarm::~CuteAlarm()
{
	delete ui;
}

//Alarm
void CuteAlarm::on_radioButton_toggled(bool checked)
{
	switcher(1);
}

//Minutnik
void CuteAlarm::on_radioButton_2_toggled(bool checked)
{
	switcher(2);
}

//Stoper
void CuteAlarm::on_radioButton_3_toggled(bool checked)
{
	switcher(3);
}

//Start
void CuteAlarm::on_pushButton_clicked()
{
	ui->pushButton->setEnabled(false);
	ui->pushButton_2->setEnabled(true);
	ui->pushButton_5->setEnabled(ui->radioButton_3->isChecked());

	//Finish layout
}

//Stop
void CuteAlarm::on_pushButton_2_clicked()
{
	ui->pushButton_2->setEnabled(false);
	ui->pushButton->setEnabled(true);
	ui->pushButton_5->setEnabled(ui->radioButton_3->isChecked());

}

//Drzemka
void CuteAlarm::on_pushButton_3_clicked()
{

}

//Reset
void CuteAlarm::on_pushButton_4_clicked()
{
/*	ui->pushButton->setEnabled(true);
	ui->pushButton_2->setEnabled(false);
	ui->pushButton_5->setEnabled(!ui->radioButton_3->isEnabled());*/
	on_pushButton_2_clicked();
}

//Zapisz
void CuteAlarm::on_pushButton_5_clicked()
{

}

void CuteAlarm::switcher(const quint8 opt) noexcept
{
	ui->FirstEdit->setEnabled(false);
	ui->SecondEdit->setEnabled(false);
	ui->pushButton_2->setEnabled(false);
	ui->pushButton_3->setEnabled(false);
	ui->pushButton_4->setEnabled(false);
	ui->pushButton_5->setEnabled(false);
	ui->FirstEdit->setTime(QTime(0,0,0));
	ui->SecondEdit->setTime(QTime(0,0,0));
	ui->FirstRead->setTime(QTime(0,0,0));
	ui->SecondRead->setTime(QTime(0,0,0));

	switch(opt)
	{
		case 1:
		{
			ui->label->setText("Alarm o:");
			ui->FirstEdit->setEnabled(true);
			ui->SecondEdit->setEnabled(true);
			ui->pushButton_2->setEnabled(true);
			ui->pushButton_3->setEnabled(true);
			ui->pushButton_4->setEnabled(true);

			break;
		}

		case 2:
		{
			ui->label->setText("Alarm za:");
			ui->FirstEdit->setEnabled(true);
			ui->pushButton_4->setEnabled(true);
			break;
		}

		case 3:
		{
			ui->pushButton_5->setEnabled(true);
			ui->pushButton_4->setEnabled(true);
			break;
		}
	}
}
