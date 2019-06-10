#ifndef CUTEALARM_H
#define CUTEALARM_H

#include <QThread>
#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class CuteAlarm;
}

class Clock : public QObject
{
	Q_OBJECT

	quint64 _periodOfTime = 1000;
	bool go = false;


public:

	explicit Clock(quint64 period, QObject * parent = nullptr)
		:QObject(parent), _periodOfTime{period} {}

	~Clock() {};

	quint64 period() const noexcept { return _periodOfTime; }

signals:

	void period();

public slots:

	void Period()
	{
		go = true;
		while (go)
		{
			QThread::currentThread()->msleep(_periodOfTime);
			emit period();
		}
	}

	void Stop()
	{
		go = false;
	}

};

class CuteAlarm : public QMainWindow
{
	Q_OBJECT

public:

	explicit CuteAlarm(QWidget *parent = nullptr);

	~CuteAlarm();

	Clock * clock = nullptr;

private slots:
	void on_radioButton_toggled(bool checked);

	void on_radioButton_2_toggled(bool checked);

	void on_radioButton_3_toggled(bool checked);

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

signals:

	void start();

	void stop();

private:

	void switcher(const quint8 opt) noexcept;

	Ui::CuteAlarm *ui;
};

#endif // CUTEALARM_H
