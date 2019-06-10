#ifndef CUTEALARM_H
#define CUTEALARM_H

#include <QMainWindow>

namespace Ui {
class CuteAlarm;
}

class CuteAlarm : public QMainWindow
{
	Q_OBJECT

public:
	explicit CuteAlarm(QWidget *parent = nullptr);
	~CuteAlarm();

private:
	Ui::CuteAlarm *ui;
};

#endif // CUTEALARM_H
